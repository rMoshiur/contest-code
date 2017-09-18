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

intl h[200005], dp[200005], p2[20];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    for( int i = 0; i < n;i++ )
    {
        scanf("%lld", &h[i]);
    }
    dp[0] = 0;
    if( n == 1 )
    {
        printf("0\n");
        return 0;
    }
    dp[1] = abs(h[1] - h[0]);
    for( int i = 0; i < 20; i++ )
        p2[i] = 1<<i;

    for( int i = 2; i < n; i++ )
    {
        intl mn = 1000000000000000;
        int j;
        for(j = 0; j < 20 && (i-p2[j]) >= 0; j++  )
            mn = min( mn, dp[i-p2[j]]+abs(h[i] - h[ i-p2[j] ] ));
        dp[i] = mn;
        //what_is(mn);
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}


