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
    double a;
    while( scanf("%lf", &a) != EOF )
    {
        a = sqrt(3)*a/2.0;
        printf("%.10lf %.10lf %.10lf %.10lf\n",a, a/(1+sqrt(3)/2.0), a/2.0, a/2.309307341 );
        //cout << a << "  " << a/(1+sqrt(3)/2.0) << "   " << a/2.0 << "  " << a/2.309307341 << endl;
    }

    return 0;
}



