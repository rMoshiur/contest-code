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
    int n;
    cin >> n;
    int ara[n][n], mx[n];
    for( int i = 0; i < n; i++ )
    {
        int mm = 0;
        for( int j = 0; j < n; j++ )
        {
            cin >> ara[i][j];
            mm = max( mm, ara[i][j] );
        }
        mx[i] = mm;
    }
    for( int i = 0 )
    return 0;
}
