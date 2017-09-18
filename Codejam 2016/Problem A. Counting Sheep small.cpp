#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("A-large.in", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    ios::sync_with_stdio(false);
    filein;
    fileout;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl n, ans;
        cin >> n;
        bool ara[10], flag = 0;
        memset( ara, 0, sizeof(ara) );
        for( int i = 1; i < 5000; i++ )
        {
            ans = n*i;
            while( ans > 0 )
            {
                int k = ans%10;
                ans/=10;
                ara[k] = 1;
            }
            flag = 1;
            for( int j = 0; j < 10; j++ )
            {
                if( ara[j] == 0 )
                {
                    flag = 0;
                    break;
                }
            }
            if( flag )
            {
                ans = n*i;
                break;
            }
            //cout << ans << endl;
        }
        if( flag )
            cout << "Case #" << caseno++ << ": " << ans << "\n";
        else
            cout << "Case #" << caseno++ << ": INSOMNIA" << "\n";
    }
    return 0;
}



