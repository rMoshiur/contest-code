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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    long long a;
    vector<double> vec;
    while( scanf("%lld", &a) != EOF )
    {
        //cout << setprecision(4) << fixed << sqrt(a) << endl;
        vec.pb(sqrt(a));
    }
    for( auto i = vec.end() - 1; i >= vec.begin(); i-- )
    {
        cout << setprecision(4) << fixed << *i << endl;
    }

    return 0;
}



