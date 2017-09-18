#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    //filein;
    int r, n;
    while( scanf("%d %d", &r, &n) != EOF )
    {
        if( n == 1 )
        {
            printf("%d.0000000000 0.0000000000 0.0000000000\n", r);
            continue;
        }
        double rr = r*sin(pi/n)/(1+sin(pi/n));
        double ag = n*rr*rr/tan(pi/n) - .5*n*rr*rr*(n-2)*pi/n;
        //what_is(n*rr*rr/tan(pi/n));
        double u = pi*(r*r - n*rr*rr);
        double gg = u - ag;
        printf("%.10lf %.10lf %.10lf\n", rr, ag, gg);
        //cout << rr << "  " << ag << "  " << gg << endl;
    }

    return 0;
}



