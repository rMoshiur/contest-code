#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair< pair<intl, intl>, intl>
#define ldb         long double

struct node //0=1st, 1=max, 2=last, 3 = allsum
{
    intl val[4];
};

node tree[4*50004], sudu;
int ara[50005];

node merge_sg( node a, node b )
{
    node ans;
    ans.val[0] = max( a.val[0], a.val[3]+b.val[0] );
    ans.val[1] = max( a.val[2] + b.val[0], max( a.val[1], b.val[1] ) );
    ans.val[2] = max( b.val[2], a.val[2] + b.val[3] );
    ans.val[3] = a.val[3] + b.val[3];
    return ans;
}

void init( int cn, int s, int e )
{
    if( s == e )
    {
        for( int i = 0; i < 4; i++ )
        {
            tree[cn].val[i] = ara[s];
        }
        return;
    }
    int m = (s+e)/2, l = cn*2, h = cn*2+1;
    init(l, s, m);
    init(h, m+1, e);
    tree[cn] = merge_sg( tree[l], tree[h] );
    return;
}

node query( int cn, int s, int e, int x, int y )
{
    if( e < x || s > y )
        return sudu;
    if( s >= x && e <= y )
        return tree[cn];
    int m = (s+e)/2;
    node s1 = query(cn*2, s, m, x, y);
    node s2 = query(cn*2+1, m+1, e, x, y);
    return merge_sg(s1, s2);
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    sudu.val[0] = sudu.val[1] = sudu.val[2] = -1000000000;
    for( int i = 1; i <= n; i++ ) scanf("%lld", &ara[i]);
    init(1,1,n);
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int x, y;
        scanf("%d %d", &x,&y);
        node ans = query(1,1,n,x,y);
        printf("%lld\n", ans.val[1]);
    }

    return 0;
}




