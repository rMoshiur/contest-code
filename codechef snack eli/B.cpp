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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>

pii exteuclid( intl a, intl b )
{
    if( b == 0 )
        return mp(1,0);
    pii x = exteuclid(b,a%b);
    return mp( x.yy, x.xx - (a/b)*x.yy );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl t;
    cin >> t;
    while(t--)
    {
        intl n, c;
        cin >> n >> c;
        c = 2*c;
        if( c % n != 0 )
        {
            cout << "No\n";
            continue;
        }
        intl a = 2, b = n-1, d = c/n, g;

        if(b&1)
            g = 1;
        else
            g = 2;
        if( d%g != 0 )
        {
            cout << "No\n";
            continue;
        }
        a/=g;
        b/=g;
        d/=g;
        pii tt = exteuclid(a,b);

        long double x0 = tt.xx, y0 = tt.yy;
        x0 *= d;
        y0 *= d;
        intl k1 = ceil( (1.0-x0)/b ), k2 = floor( (y0-1.0)/a );
        //what_is(k1);
        //what_is(k2);
        if( k1 <= k2 )
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }

    return 0;
}



