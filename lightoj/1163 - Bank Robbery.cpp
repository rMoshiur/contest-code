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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl n;
        scanf("%lld", &n);
        intl t1 = n/9*10;
        t1 += n%9;
        if( n%9 == 0 )
        {
            printf("Case %d: %lld %lld\n", caseno++, t1-1, t1 );
        }
        else
            printf("Case %d: %lld\n", caseno++, t1 );
    }

    return 0;
}



