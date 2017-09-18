#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const intl SZ = 1000005, mod = 1000000007;

intl tree[SZ][2], lazy[SZ]; //0-d-sum, 1-sum
intl ara[SZ];

void propagate( int cn, int s, int e )
{
    lazy[cn]%=mod;
    int  l = cn<<1, r = (cn<<1)+1;
    intl z = (e-s);
    intl t = z*(z+1)/2;
    t %= mod;
    intl sum = ((((z+1)*s)%mod)*lazy[cn])%mod;
    sum = ( sum + (t*lazy[cn])%mod )%mod;
    tree[cn][0] = ( tree[cn][0] + (e-s+1)*lazy[cn] )%mod;
    tree[cn][1] = ( tree[cn][1] + sum )%mod;
    if( s != e )
    {
        lazy[l] += lazy[cn];
        lazy[r] += lazy[cn];
    }
    lazy[cn] = 0;
    return;
}

void init( int cn, int s, int e )
{
    lazy[cn] = 0;
    if( s==e )
    {
        tree[cn][0] = (ara[s])%mod;
        tree[cn][1] = (s*ara[s])%mod;
        return;
    }
    int m = (s+e)/2, l=cn<<1, r=  (cn<<1)+1;
    init( l, s, m );
    init( r, m+1, e );
    tree[cn][0] = (tree[l][0] + tree[r][0])%mod;
    tree[cn][1] = (tree[l][1] + tree[r][1])%mod;
    return;
}

void update( int cn, int s, int e, int x, int y, int val )
{
    if( lazy[cn] != 0 )
    {
        propagate(cn, s, e);
    }
    if( s > y || e < x )
        return;
    if( s >= x && e <= y )
    {
        lazy[cn] += val;
        propagate(cn, s, e);
        return;
    }

    int m = (s+e)/2, l=cn<<1, r=  (cn<<1)+1;
    update( l, s, m, x, y, val );
    update( r, m+1, e, x, y, val );
    tree[cn][0] = (tree[l][0] + tree[r][0])%mod;
    tree[cn][1] = (tree[l][1] + tree[r][1])%mod;
    return;
}

pii query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] != 0 )
    {
        propagate(cn, s, e);
    }
    if( s > y || e < x )
        return mp(0,0);
    if( s >= x && e <= y )
    {
        return mp( tree[cn][0], tree[cn][1] );
    }
    int m = (s+e)/2, l=cn<<1, r=  (cn<<1)+1;
    pii a = query( l, s, m, x, y );
    pii b = query( r, m+1, e, x, y);
    a.xx = ( a.xx + b.xx )%mod;
    a.yy = ( a.yy + b.yy )%mod;
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, n, q, caseno = 1;
    cin >> t;
    while( t-- )
    {
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) cin >> ara[i];
        init( 1, 1, n );
        cout << "Case " << caseno++ << ":" << endl;
        while(q--)
        {
            int c, l, r, x;
            cin >> c >> l >> r >> x;
            if( c == 1 )
            {
                update( 1, 1, n, l, r, x );
            }
            else
            {
                pii a = query( 1, 1, n, l, r );
                intl ans = ( a.yy - l*a.xx )%mod;
                ans = ( ans*x )%mod;
                ans += a.xx;
                ans %= mod;
                ans = ( ans + mod )%mod;
                cout << ans << endl;
            }
        }
    }
    return 0;
}



