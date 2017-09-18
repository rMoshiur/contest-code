#include <bits/stdc++.h>

using namespace std;

vector<int> cost(1200);
vector<int> weight(1200);
int n;
int cap;
int dp[1200][1200];

int hgain( int k,int w )
{
    if( k > n )
    {
        return 0;
    }
    if( dp[k][w] != -1 )
    {
        return dp[k][w];
    }
    int price1 = 0;
    if( w + weight[k] <= cap )
    {
        price1 = cost[k] + hgain( k+1, w + weight[k] );
    }
    int price2 = hgain( k+1, w );
    dp[k][w] = max( price1, price2 );
    return dp[k][w];

}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int pp, sum = 0;
        scanf("%d", &n);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d %d", &cost[i], &weight[i]);
        }
        scanf("%d", &pp);
        while(pp--)
        {
            scanf("%d", &cap);
            memset(dp,-1,sizeof(dp));
            sum += hgain( 1, 0);
            //cout << sum << endl;
        }
        printf("%d\n", sum);
    }
    return 0;
}
