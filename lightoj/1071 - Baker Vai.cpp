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

int dp[105][105], ara[105][105], m, n, temp[105][105];
char str[105][105];
int ans;

void findbest()
{

    for( int i = 1; i <= m; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( i == 1 )
            {
                dp[i][j] = ara[i][j] + dp[i][j-1];
                str[i][j] = 'L';
            }
            else if( j == 1 )
            {
                dp[i][j] = ara[i][j] + dp[i-1][j];
                str[i][j] = 'U';
            }
            else
            {
                if(  dp[i-1][j] >  dp[i][j-1] )
                {
                    str[i][j] = 'U';
                    dp[i][j] = ara[i][j] + dp[i-1][j];
                }
                else
                {
                    str[i][j] = 'L';
                    dp[i][j] = ara[i][j] + dp[i][j-1];
                }
            }
        }
    }
    ans += dp[m][n];
}

int main()
{
    //ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d %d", &m, &n);
        for( int i = m; i > 0; i-- )
        {
            for( int j = 1; j <= n; j++ )
                scanf("%d", &ara[i][j]);
        }
        for( int i = 1; i<= m ; i++ )
        {
            for( int j = 1; j <= n; j++ )
                printf("%d ", ara[i][j]);
            puts("");
        }
        findbest();
        what_is(ans);
        int x = m, y = n;
        ara[1][1] = 0;
        while( x != 1 || y != 1 )
        {
            ara[x][y] = 0;
            if( str[x][y] == 'L' )
                y--;
            else
                x--;
        }

        for( int i = 1; i<= m ; i++ )
        {
            for( int j = 1; j <= n; j++ )
                printf("%d ", ara[i][j]);
            puts("");
        }

        for( int i = m; i > 0; i-- )
        {
            for( int j = n; j > 0; j-- )
            {
                temp[m-i+1][n-j+1] = ara[i][j];
            }
        }
        for( int i = m; i > 0; i-- )
        {
            for( int j = n; j > 0; j-- )
            {
                ara[i][j] = temp[i][j];
            }
        }
        for( int i = 1; i<= m ; i++ )
        {
            for( int j = 1; j <= n; j++ )
                printf("%d ", ara[i][j]);
            puts("");
        }
        findbest();
        printf("Case %d: %d\n", caseno++, ans );
    }

    return 0;
}



