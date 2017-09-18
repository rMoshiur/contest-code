#include <bits/stdc++.h>

using namespace std;

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

int dist[20][20], dp[1<<17], n;

int solve( int mask = 1, int prev = 0 )
{
    if( mask == ( (1<<n) -1 ) )
        return dist[prev][0];
    if( dp[mask] != -1 )
        return dp[mask];
    int ans = 1<<25;
    for( int i = 1; i < n; i++ )
    {
        if((mask&(1<<i)) == 0)
        {
            int ret = dist[prev][i] + solve( mask|(1<<i), i );
            ans = min( ans, ret );
        }
    }
    return dp[mask] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    pii arr[25];
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset( dp, -1, sizeof dp );
        int r,c;
        n = 1;
        scanf("%d %d\n", &r, &c);
        char str[25];
        for( int i = 0; i < r; i++ )
        {
            scanf("%s", str);
            for( int j = 0; j < c; j++ )
            {
                if( str[j] == 'g' )
                {
                    arr[n++] = mp(i,j);
                }
                if( str[j] == 'x' )
                    arr[0] = mp(i,j);
            }
        }

        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                dist[i][j] = max( abs( arr[i].xx - arr[j].xx ), abs( arr[i].yy - arr[j].yy ) );
            }
        }
        int ans = solve();
        printf("Case %d: %d\n", caseno++, ans );

    }

    return 0;
}




