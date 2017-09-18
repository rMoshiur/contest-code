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
    intl dp[2][105][105];
    memset( dp, 0, sizeof(dp) );
    dp[1][1][0] = dp[0][1][0] = 1;
    for( int i = 2; i <= 100; i++ )
    {
        for( int j = 0; j < i; j++ )
        {
            dp[0][i][j] = dp[1][i-1][j] + dp[0][i-1][j];
            dp[1][i][j] = dp[0][i-1][j] + dp[1][i-1][j-1];
        }
    }
    int t;
    scanf("%d", &t);
    while( t-- )
    {
        intl a, b, c, ans = 0;
        scanf("%lld %lld %lld", &a, &b, &c);
        ans = dp[0][b][c] + dp[1][b][c];
        printf("%lld %lld\n", a, ans);
    }
    return 0;
}


