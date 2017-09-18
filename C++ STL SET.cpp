#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

int main()
{
    freopen("input.txt", "r", stdin);
    long long a, b, ans, q;
    cin >> a >> b;
    double d = sqrt(a);

    long long x, r, sq;
    x = d;
    sq = x;
    if( d > x )
        x++;
    ans = ((a%mod)*(b%mod))%mod;
    //cout << x << " " << d << " " << sq << endl;
    for( long long i = 1; i <= x && i <= b; i++   )
    {
        q = a/i;
        r = a - q*i;
        q %= mod;
        r %= mod;
        if( r == 0  )
        {
            //ans -= 2*(a%mod);
            if( q <= b && i < x )
            {
                ans -= 2*(a%mod);
            }
            else
            {
                ans -= (a%mod);
            }
        }
        else
        {
            if( q <= b && i < x )
            {
                ans -= 2*(q%mod)*(i%mod);
            }
            else
            {
                ans -= (q%mod)*(i%mod);
            }
        }
        ans %= mod;
    }
    if( ans < 0 ) ans+= mod;
    cout << ans << "\n";
    return 0;
}
