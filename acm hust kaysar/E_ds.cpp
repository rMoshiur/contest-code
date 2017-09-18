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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb        long double

vector<pii>vec;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, a, b;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d %d", &a, &b);
            vec.pb(mp(a, 1));
            vec.pb(mp(b,-1));
        }
        sort( vec.begin(), vec.end() );
        int ans= 0, num = 0;
        for( int i = 0; i < 2*n; i++ )
        {
            num += vec[i].yy;
            ans = max(ans,num);
        }
        printf("%d\n", ans);
        vec.clear();
    }

    return 0;
}




