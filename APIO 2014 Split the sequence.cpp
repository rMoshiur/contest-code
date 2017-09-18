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

intl dp[205][100005];
intl ara[100005], sum[100005], s = 0;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, k;
    cin >> n >> k;

    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        sum[i] = s+=ara[i];
    }
    //for( int i = 0; i < n; i++ )
      //  cout << i << " is " << sum[i] << endl;

    //memset( dp, 0, sizeof(dp) );
    for( int i = 0; i < n; i++ )
    {
        dp[0][i] = 0;//sum[i];
    }
    for( int i = 1; i <= k; i++ )
    {
        for( int j = i; j < n; j++ )
        {
            intl temp = 0;
            for( int k = i-1; k < j; k++ )
            {
                temp = max(temp, dp[i-1][k] + ( sum[j] - sum[k] )*sum[k] );
            }
            dp[i][j] = temp;
        }
    }
    /*for( int i = 0; i <= k; i++ )
    {
        for( int j = 0; j < n; j++ )
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    cout << dp[k][n-1] << endl;
    return 0;
}



