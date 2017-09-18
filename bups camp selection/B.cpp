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
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

int dp[5005][5005];
int ara[5005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i];
        }
        for( int i = 1; i <= n; i++ )
        {
            int sum = 0;
            dp[0][i] = -1000000000;
            for( int j = i; j >= 1; j-- )
            {
                sum += ara[j];
                dp[0][i] = max( dp[0][i], sum );
            }
        }

        for( int i = 1; i <= k; i++ )
        {
            dp[i][1] = ara[1];
            if( k > 0 && ara[1] < 0 )
                dp[i][1] = 0;
            for( int j = 2; j <= n; j++ )
            {
                dp[i][j] = max( dp[i][j-1] + ara[j], dp[i-1][j-1] );
            }
        }
        int ans = -1000000000;
        for( int i = 0; i <= k; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                ans = max( ans, dp[i][j] );
            }
        }
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
    return 0;
}



