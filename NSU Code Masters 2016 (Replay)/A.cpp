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

struct point
{
    long double x, y,z;
};

long double sq( long double a, long double b )
{
    return (a-b)*(a-b);
}

long double dist( point a, point b )
{
    return sqrt( sq(a.x,b.x)+sq(a.y,b.y)+sq(a.z,b.z) );
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<point>vec(n);
        for( int i = 0; i < n; i++ )
        {
            cin >> vec[i].x >> vec[i].y >> vec[i].z;
        }
        long double dis = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = i+1; j < n; j++ )
            {
                dis = max( dis, dist( vec[i], vec[j] ) );
            }
        }

        long double r = dis/2;
        long double ans = 4*pi*r*r*r/3.0;
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}



