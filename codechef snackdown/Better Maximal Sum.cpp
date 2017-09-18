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

intl ara[100005], x[100005], y[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, flag = 1;
        intl ans = 0;
        scanf("%d", &n);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%lld", &ara[i]);
            ans += ara[i];
        }


        x[n] = ara[n];
        for( int i = n-1; i >= 1; i-- )
            x[i] = max( x[i+1] +ara[i], ara[i] );

        y[1] = ara[1];
        for( int i = 2; i <= n; i++ )
            y[i] = max( y[i-1] + ara[i], ara[i] );

        x[n+1] = y[n+1] = x[0] = y[0] = 0;

        intl temp = -1e9, a, b;
        for( int i = 1; i <= n; i++ )
        {
            if( ara[i] < 0 )
            {
                if( x[i+1] < 0 ) a = 0;
                else a = x[i+1];
                if( y[i-1] < 0 ) b = 0;
                else b = y[i-1];
                if( a == 0 && b == 0 )
                    ans = max( ans, ara[i] );
                else
                    ans = max( a+b, ans );
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}



