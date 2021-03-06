#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>edge[3005];
int ara[3005][3005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
    }
    for( int i = 1; i <= n; i++  )
    {
        for( int v: edge[i] )
        {
            for( int u: edge[v] )
            {
                if( u != i )
                {
                    ara[i][u]++;
                }
            }
        }
    }
    intl ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            intl s = ara[i][j];
            ans += s*(s-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}




