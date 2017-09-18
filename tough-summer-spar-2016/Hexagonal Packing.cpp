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


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, r;
        scanf("%d %d", &n, &r);
        double a = 2.0*r/sqrt(3*(2*n-1)*(2*n-1)+1);
        //what_is(a);
        double ans = 3*sqrt(3)*a*a/2.0;
        //what_is(ans);
        cout << setprecision(10) << fixed << ans << endl;
    }

    return 0;
}




