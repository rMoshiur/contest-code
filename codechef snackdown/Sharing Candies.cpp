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

intl gcd( intl a, intl b )
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        intl a, b, c, d;
        cin >> a>> b >> c >> d;
        intl dif = abs(a-b);
        intl g = gcd(c,d);
        intl ans = min( abs(dif%g), abs( g - dif%g ) );
        cout << ans << endl;
    }

    return 0;
}


