#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

intl mn;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        intl dp[n][m], val[n][m], dis[n][m];
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
                scanf("%lld", &val[i][j]);
        }

        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
                scanf("%lld", &dis[i][j]);
        }

        intl mn = 1e9;
        for( int i = 0; i < m; i++ )
        {
            dp[0][i] = val[0][i];
            mn = min( mn, val[0][i] );
        }

        for( int i = 1; i < n ; i++ )
        {
            intl temp = 1e9;
            for( int j = 0; j < m ; j++ )
            {
                intl p = val[i][j] - dis[i-1][j];
                if( p < 0 ) p = 0;
                p += dp[i-1][j];
                intl q = mn + val[i][j];
                dp[i][j] = min( p, q );
                temp = min( temp, dp[i][j] );
            }
            mn = temp;
        }

        printf("%lld\n", mn);
    }

    return 0;
}


