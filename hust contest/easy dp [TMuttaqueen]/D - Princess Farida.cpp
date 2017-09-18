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
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        intl dp[n+5], ara[n+5], ans;
        for( int i = 1; i <= n; i++ )
            scanf("%lld", &ara[i]);
        dp[0] = 0;
        dp[1] = ara[1];
        for( int i = 2; i <= n; i++ )
        {
            dp[i] = max( ara[i] + dp[i-2], dp[i-1] );
        }
        ans = dp[n];

        printf("Case %d: %lld\n",caseno++, ans);
    }


    return 0;
}
