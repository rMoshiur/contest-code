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
    int ans[110];
    memset( ans, 0, sizeof(ans) );
    for( int i = 0; i <= 100; i++ )
    {
        if( ans[i] == 0 )
        {
            ans[i+2] = ans[i+3] = ans[i+5] = 1;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if( ans[n] )
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}



