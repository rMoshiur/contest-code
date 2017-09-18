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
    int n, s = 0, a, d = 0;
    vector<int> vec;
    cin >> n;
    cin >> a;
    s += a;
    vec.pb(a);
    d++;
    for( int i = 1; i < n; i++ )
    {
        cin >> a;
        s += a;
        int k = d;
        for( int j = 0; j < k; j++)
        {
            vec.pb( a+vec[j] );
            d++;
        }
        vec.pb(a);
        d++;
    }
    int ans = 1e9;
    for( int i = 0; i < d; i++ )
    {
        ans = min( ans,abs(s-2*vec[i]) );
    }
    cout << ans << endl;
    return 0;
}



