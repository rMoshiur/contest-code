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
    intl t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        if(n < 0)
        {
            for( intl i = n; i < 0; i++ )
            {
                printf("%lld ", i);
            }
            printf("%lld\n", 0LL);
            continue;
        }
        for( intl i = 0; i < n; i++ )
        {
            printf("%lld ", i);
        }
        printf("%lld\n", n);
    }

    return 0;
}




