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

struct data
{
    int x, y;
};

bool comp( data a, data b )
{
    if(a.x==b.x)
        return a.y < b.y;
    return a.x > b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n, num,a, b;//petre = 1, jan = 0;
        intl sp = 0, sj = 0;
        string str;
        cin >> n >> str;
        if( str == "Petra" ) num = 1;
        else num = 0;
        pii dp[n+5][n+5];
        memset(dp, 0, sizeof(dp));
        data ara[n+5];
        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i].x >> ara[i].y;
        }
        sort( ara+1, ara+n+1, comp );
        if( num )
        {
            dp[1][0].xx = ara[1].x;
            dp[1][0].yy = 0;
        }
        else
        {
            dp[1][0].xx = ara[1].x;
            dp[1][0].yy = 0;
            dp[1][1].xx = 0;
            dp[1][1].yy = ara[1].y;
        }
        for( int i = 2; i <= n; i++ )
        {
            int k = i/2;
            if( i%2==1 && num==0) k++;
            intl sum = 0;
            for( int j = 1; j <= i; j++) sum += ara[j].x;
            dp[i][0].xx = sum;
            dp[i][0].yy = 0;
            for( int j = 1; j <= k; j++ )
            {
                intl pet1 = dp[i-1][j].xx + ara[i].x, jan1= dp[i-1][j].yy, pet2 = dp[i-1][j-1].xx, jan2 = dp[i-1][j-1].yy + ara[i].y;
                if( jan1 == jan2 )
                {
                    dp[i][j].yy = jan1;
                    dp[i][j].xx = max(pet1, pet2);
                }
                else
                {
                    if( jan1 > jan2 )
                    {
                        dp[i][j].yy = jan1;
                        dp[i][j].xx = pet1;
                    }
                    else
                    {
                        dp[i][j].yy = jan2;
                        dp[i][j].xx = pet2;
                    }
                }
            }
            //cout << dp[i][k].xx << " " << dp[i][k].yy << endl;
        }
        int k = n/2;
        if( n%2==1 && num==0) k++;
        cout << dp[n][k].xx << " " << dp[n][k].yy << endl;
    }

    return 0;
}




