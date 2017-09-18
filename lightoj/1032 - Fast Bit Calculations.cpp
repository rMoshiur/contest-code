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
    int t, caseno = 1;
    cin >> t;
    intl ara[33], a = 1;
    ara[0] = ara[1] = 0;
    for( int i = 2; i <= 32; i++ )
    {
        ara[i] = ara[i-2] + ara[i-1] + a;
        a *= 2;
    }
    while(t--)
    {
        intl n;
        cin >> n;
        intl a = n&(n-1);
        if( a == 0 )
        {
            int k;
            for( int i = 0; i <= 32; i++ )
            {
                a = 1<<i;
                if( a == n )
                {
                    k = i;
                    break;
                }
            }
            cout << ara[k] << endl;
        }
    }

    return 0;
}



