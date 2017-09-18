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


int main()
{
    //ios::sync_with_stdio(false);
    filein;
    int mx[1005];
    int mn[1005];
    for( int i = 0; i <= 1000; i++ )
    {
        if( i%2 )
        {
            mx[i] = (i+1)/2;
            mn[i] = (i-1)/2;
        }
        else
        {
            mx[i] = i/2;
            mn[i] = i/2;
        }
    }
    mn[1] = 1;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int r, c, k;
        scanf("%d %d %d", &r, &c, &k);
        pii ara[k];
        //debug;
        for( int i = 0; i < k; i++ ) scanf("%d %d", &ara[i].xx, &ara[i].yy );
        sort( ara, ara+k );
        intl ans1 = 0, ans2 = 0;
        int cc = 0;
        for( int i = 0; i < r; i++ )
        {
            vector<int>vec;
            vec.pb(-1);
            while( cc < k && ara[cc].xx == i  )
            {
                vec.pb( ara[cc].yy );
                cc++;
            }
            vec.pb(c);
            //what_is(i);
            for( int j = 1; j < vec.size(); j++ )
            {
                //what_is(vec[j]);
                ans1 += mx[ vec[j] - vec[j-1] - 1 ];
                ans2 += mn[ vec[j] - vec[j-1] - 1 ];
            }
            //what_is(ans1);
            //what_is(ans2);
        }

        printf("Case #%d: %lld %lld\n", caseno++, ans1, ans2  );
    }

    return 0;
}




