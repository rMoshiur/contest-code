#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define what(x)     cout << #x << " is " << x << " "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define lldb        long double

intl mod = 1e9+7;

intl bigmod( intl x, intl y )
{
    if( y == 1 )
        return x;
    intl tt = bigmod(x, y/2 );
    tt = (tt*tt)%mod;
    if(y&1)
        tt = (tt*x)%mod;
    return tt;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    char str[200005];
    intl m, n;
    while( scanf("%lld %lld %s\n", &n, &m, str ) == 3)
    {
        intl c = 0;
        intl temp = 0;
        for( int i = 0; str[i]; i++ )
        {
            temp = 10*temp + ( str[i] - '0' );
            temp %= m;
            //what_is(temp);
            if( temp == 0 )
                c++;
        }
        if( temp == 0 )
            c--;
        //what_is(c);
        //what_is(m);
        if( c != 0 )
            cout << bigmod(2, c) << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}



