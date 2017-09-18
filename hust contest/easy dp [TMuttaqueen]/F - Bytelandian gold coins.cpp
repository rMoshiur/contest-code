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

intl dp[1000006];

intl answer( intl n )
{
    if( n <= 1000000 )
        return dp[n];
    return max( n, answer(n/2) + answer(n/3) + answer(n/4) );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    for( int i = 6; i <= 1000000; i++ )
        dp[i] = max( (intl)i, dp[i/2] + dp[i/3] + dp[i/4] );
    while( scanf("%lld", &n) != EOF )
    {

        intl ans = answer(n);

        printf("%lld\n", ans);
    }

    return 0;
}



