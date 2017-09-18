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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl dp[15][100];
    memset( dp, 0, sizeof(dp) );
    dp[1][0]  = 1;
    dp[1][1]  = 0;
    for( int i = 2; i <= 12; i++ )
    {
        dp[i][0] = 1;
        int lim = i*(i-1)/2;
        for( int j = 1; j <= lim; j++ )
        {
            intl s = 0, k = 0;
            for( k = j; k > j-i; k-- )
                s += dp[i-1][k];
            dp[i][j] = s;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%lld\n", dp[n][k]);
    }

    return 0;
}


