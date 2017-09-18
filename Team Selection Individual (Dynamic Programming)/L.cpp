#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int l = 1, h = 100, mx = -1, nax = 1;
    for( int i = 1; i <= 100; i++ )
    {
        int cnt = 0, x = 0;
        l = 1;
        h = 100;
        while( l < h )
        {
            cnt++;
            int m = (l+h)/2;
            if( m == i )
            {
                break;
            }
            else if( m > i )
            {
                x++;
                if( x == 1 )
                {
                    cnt += i - l + 1;
                    break;
                }
                h = m - 1;
            }
            else
                l = m+1;
        }
        cout << cnt << endl;
        mx = max( cnt, mx );
    }
    cout << mx << endl;
    return 0;
}




