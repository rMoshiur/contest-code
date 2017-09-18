#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("D-small-attempt0.in", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    ios::sync_with_stdio(false);
    filein;
    fileout;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int k , c, s;
        cin >> k >> c >> s;
        cout << "Case #" << caseno++ << ": " << 1;
        for( int i = 2; i <= k; i++ )
        {
            cout << " " << i;
        }
        cout << endl;
    }

    return 0;
}



