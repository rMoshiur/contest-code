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
#define pii         pair<unsigned long long, unsigned long long>
#define piii        pair<pii, int>
#define uint        unsigned long long


vector<pii>dp(100);
pii dt[100][4];
int c;

void process()
{
    uint l = 0, r = 0;
    dp[0].xx = dp[0].yy = 0;
    for( int i = 0; i < 4; i++ )
        dt[0][i].xx = dt[0][i].yy = -1;
    l = 1;
    r = 5;
    c = 1;
    while( l < r )
    {
        dp[c].xx = l;
        dp[c].yy = r;
        uint diff = r-l+1;
        if( !(c%2) )
        {

            dt[c][0].xx = l;
            dt[c][0].yy = r;
            for( int i = 1; i < 4; i++ )
            {
                dt[c][i].xx = dt[c][i].yy = 0;
            }
            l = r+1;
            r = 6*l - 1;

        }
        else
        {

            dt[c][0].xx = dt[c][0].yy = 0;
            dt[c][1].xx = l;
            dt[c][1].yy = l + diff/5 -1;
            l = l + diff/5;
            dt[c][2].xx = l;
            dt[c][2].yy = l + (diff/5)*2 -1;
            l = l + (diff/5)*2;
            dt[c][3].xx = l;
            dt[c][3].yy = l + (diff/5)*2 -1;
            l = r+1;
            r = 2*l - 1;

        }

        c++;
    }
    /*what_is(c);
    cout << dp[35].xx << " " << dp[35].yy << endl;
    for( int i = 0; i < 4; i++ )
    {
        cout << "   " << dt[35][i].xx << " " << dt[35][i].yy  << endl;
    }*/
    return;
}

uint sea( uint a )
{
    for( int i = 0; i < c; i++ )
    {
        if( a >= dp[i].xx && a <= dp[i].yy )
        {
            for( int j = 0; j < 4; j++ )
            {
                if( a >= dt[i][j].xx && a <= dt[i][j].yy )
                    return j;
            }
        }
    }
    debug;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    process();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        uint ans = 0, a;
        int n;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%llu", &a);
            uint k = sea(a);
            ans ^= k;
        }
        if(ans)
        {
            printf("Henry\n");
        }
        else
            printf("Derek\n");
    }

    return 0;
}



