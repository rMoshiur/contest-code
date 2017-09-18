#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define ldb         long double


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, a;
    cin >> n;
    intl ara[100005] = {};
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        ara[a]++;
    }
    vector<pii>vec;
    vec.pb(mp(0,0));
    for( int i = 1; i<= 100000; i++ )
    {
        if(ara[i]!=0)
            vec.pb( mp(i,ara[i]) );
    }

    intl dp[n+5], l = vec.size();
    dp[0] = 0;
    dp[1] = vec[1].xx*vec[1].yy;
    for( int i = 2; i < l; i++ )
    {
        if( vec[i].xx-1 == vec[i-1].xx )
        {
            dp[i] = max( dp[i-1], vec[i].xx*vec[i].yy+dp[i-2] );
        }
        else
        {
            dp[i] = vec[i].xx*vec[i].yy+dp[i-1];
        }
    }

    cout << dp[l-1] << endl;

    return 0;
}



