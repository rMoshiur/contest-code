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

int ara[1000005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    ara[0] = 0;
    ara[1] = 1;
    ara[2] = 2;
    ara[3] = 3;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, m, k, flag[1005];
        memset( flag, 0 , sizeof(flag) );
        cin >> n >> m >> k;
        //debug;
        //cout << 1 << " " << 2 << " " << 3;
        for( int i = 4; i <= n; i++ )
        {
            ara[i] = ( ara[i-1] + ara[i-2] + ara[i-3] )%m + 1;
            //cout << " " << ara[i];
        }

        //debug;
        int l = 1, r = 1, c = 0, ans = 10000000;
        for( int i = 1; i <= n; i++ )
        {
            int a = ara[r++];
            if( a <= k && flag[a] == 0 )
                c++;
            flag[a]++;
            if( c == k )
            {
                ans = min( ans, r-l );
                while( c == k && l < r )
                {
                    int b = ara[l++];
                    if( b <= k && flag[b]== 1 )
                    {
                        c--;
                        ans = min( ans, r-l+1 );
                    }
                    flag[b]--;
                }
            }
        }
        if( ans == 10000000 )
            cout << "Case " << caseno++ << ": sequence nai" << endl;
        else
            cout << "Case " << caseno++ << ": " << ans << endl;
        //what_is(t);
    }

    return 0;
}




