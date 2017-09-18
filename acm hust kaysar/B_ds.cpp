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

struct node //0=max, 1=2ndmax
{
    intl val[2];
};

node tree[4*100004], sudu;
int ara[100005];

node merge_sg( node a, node b )
{
    node ans;
    if( a.val[0] > b.val[0] )
    {
        ans.val[0] = a.val[0];
        ans.val[1] = max( a.val[1], b.val[0] );
    }
    else
    {
        ans.val[0] = b.val[0];
        ans.val[1] = max( b.val[1], a.val[0] );
    }
    return ans;
}

void init( int cn, int s, int e )
{
    if( s == e )
    {
        tree[cn].val[0] = ara[s];
        tree[cn].val[1] = -1999999999;
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

void update( int cn, int s, int e, int x, int v )
{
    if( e < x || s > x )
        return;
    if( s == e && s == x )
    {
        ara[s] = v;
        tree[cn].val[0] = ara[s];
        tree[cn].val[1] = -1299999999;
        return;
    }
    int m = (s+e)/2, l = cn*2, h = cn*2+1;
    update(l, s, m, x, v);
    update(h, m+1, e, x, v);
    tree[cn] = merge_sg( tree[l], tree[h] );
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    sudu.val[0] = sudu.val[1] = -1000000000;
    for( int i = 1; i <= n; i++ ) scanf("%lld", &ara[i]);
    init(1,1,n);
    int m;
    scanf("%d\n", &m);
    while(m--)
    {
        int x, y;
        char z;
        scanf("%c %d %d\n",&z,&x,&y);
        //what_is(z);
        if(z == 'Q')
        {
            node ans = query(1,1,n,x,y);
            printf("%lld\n", ans.val[0] + ans.val[1]);
        }
        else
        {
            update(1,1,n,x,y);
        }

    }

    return 0;
}




