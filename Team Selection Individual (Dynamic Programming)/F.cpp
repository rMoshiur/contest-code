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
#define pii         pair<double, double>
#define piii        pair<pii, int>
#define double      long double

double dist( pii a, pii b )
{
    return sqrt( (a.xx-b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy) );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    pii ara[5005];
    double dp[5005];
    while( scanf("%d", &n)==1)
    {
        for( int i = 0; i < n; i++ ) cin >> ara[i].xx >> ara[i].yy;
        dp[0] = 0;
        int f = 2, b = 1;
        dp[1] = dist( ara[0], ara[1] )*2;
        dp[2] = dist(ara[0],ara[1]) + dist(ara[1],ara[2]) + dist(ara[0] + ara[2]);
        for( int i = 3; i < n-1; i++ )
        {
            double temp = dist( ara[i-1], ara[i] ), t1 = dist( ara[f], ara[i] ), t2 = dist(ara[b], ara[i]), t3 = ;
            if(  )
        }
    }
    return 0;
}




