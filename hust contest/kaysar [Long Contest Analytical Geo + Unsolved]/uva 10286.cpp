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
    double d;
    while( scanf("%lf", &d) != EOF )
    {
        //cout << setprecision(10) << d*0.9510565163/0.8910065242 << endl;
        printf("%.10lf\n", d*0.9510565163/0.8910065242);
    }
    return 0;
}



