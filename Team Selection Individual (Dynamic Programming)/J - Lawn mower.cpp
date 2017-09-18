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

double a1[1005], b1[1005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int a, b;
    double d;
    cin >> a >> b >> d;
    while( a != 0 || b != 0 || d >= 0.00000001 )
    {
        bool flag = 1;
        for( int i = 0; i < a; i++ )
        {
            cin >> a1[i];
        }
        for( int i = 0; i < b; i++ )
        {
            cin >> b1[i];
        }
        sort( a1, a1+a );
        sort(b1, b1+b);
        double ea = 0.0;
        d/=2.0;
        for( int i = 0; i < a; i++ )
        {
            double x = a1[i]-d, y = a1[i]+d;
            if( x - ea >= 0.000000001 )
            {
                flag = 0;
                break;
            }
            ea = y;
        }
        if( 75.0 - ea >= 0.000000001 )
            flag = 0;
        for( int i = 0; i < b; i++ )
        {
            double x = b1[i]-d, y = b1[i]+d;
            if( x - ea >= 0.000000001 )
            {
                flag = 0;
                break;
            }
            ea = y;
        }
        if( 100.0 - ea >= 0.000000001 )
            flag = 0;
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
        cin >> a >> b >> d;
    }

    return 0;
}




