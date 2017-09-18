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
#define piii        pair<pii, int>
#define ldb        long double

int tree[4*100005][2]; //0=off, 1=on
int lazy[4*100005];
bool flag[4*100005];

void relax(int cn, int s, int e)
{
    //what_is(s);
    //what_is(e);
    if( s == e )
    {
        if( lazy[cn] % 2 )
        {
            int temp = tree[cn][0];
            tree[cn][0] = tree[cn][1];
            tree[cn][1] = temp;
        }
        flag[cn] = 0;
        lazy[cn] = 0;
        return;
    }

    if( lazy[cn] % 2 )
    {
        int temp = tree[cn][0];
        tree[cn][0] = tree[cn][1];
        tree[cn][1] = temp;
    }
    flag[cn] = 0;
    flag[cn*2] = flag[cn*2+1] = 1;
    lazy[cn*2] += lazy[cn];
    lazy[cn*2+1] += lazy[cn];
    lazy[cn] = 0;
    return;

}

void init( int cn, int s, int e )
{
    if(s==e)
    {
        tree[cn][0] = 1;
        tree[cn][1] = 0;
        return;
    }
    int m = (s+e)/2;
    init(cn*2, s,m);
    init(cn*2+1,m+1, e);
    tree[cn][0] = tree[cn*2][0] + tree[cn*2+1][0];
    tree[cn][1] = tree[cn*2][1] + tree[cn*2+1][1];
}

void update(int cn, int s, int e, int x, int y)
{
    if(flag[cn])
        relax(cn, s, e);
    if( s > y || e < x ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] += 1;
        //what_is(lazy[cn]);
        relax(cn, s, e);
        return;
    }
    int m = (s+e)/2;
    update(cn*2, s, m, x, y);
    update(cn*2+1, m+1, e, x, y);
    tree[cn][0] = tree[cn*2][0] + tree[cn*2+1][0];
    tree[cn][1] = tree[cn*2][1] + tree[cn*2+1][1];
}

int query( int cn, int s, int e, int x, int y )
{
    if(flag[cn])
        relax(cn, s, e);
    if( s > y || e < x ) return 0;
    if( s >= x && e <= y )
        return tree[cn][1];
    int m = (s+e)/2;
    int s1 = query(cn*2, s, m, x, y);
    int s2 = query(cn*2+1, m+1, e, x, y);
    return s1+s2;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int n, q;
    scanf("%d %d", &n, &q);
    init(1,1,n);
    while(q--)
    {
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        if(a == 0)
        {
            update(1,1,n,x,y);
        }
        else
        {
            int ans = query(1,1,n,x,y);
            printf("%d\n", ans);

        }
    }

    return 0;
}




