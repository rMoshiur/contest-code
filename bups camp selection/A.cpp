#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

int ara[SZ];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int f = 1;
        for( int i = 0; i < n; i++ )
            cin >> ara[i];

        for( int i = 1; i < n; i++ )
        {
            if( ara[i] != ara[i-1] )
            {
                f = 0;
                break;
            }
        }
        //what_is(f);
        if(f)
        {
            cout << "neutral" << endl;
            //what_is(f);
            continue;
        }
        f = 1;
        for( int i = 1; i < n; i++ )
        {
            if( ara[i] > ara[i-1] )
            {
                f = 0;
                break;
            }
        }
        if(f)
        {
            cout << "allBadDays" << endl;
            continue;
        }
        f = 1;

        for( int i = 1; i < n; i++ )
        {
            if( ara[i] < ara[i-1] )
            {
                f = 0;
                break;
            }
        }
        if(f)
        {
            cout << "allGoodDays" << endl;
            continue;
        }
        int c = 0, prev = -1, ans = -1;
        for( int i = 1; i < n-1; i++ )
        {
            if( ara[i] > ara[i-1] && ara[i] > ara[i+1] )
            {
                if( c > 0 )
                {
                    ans = max(ans, i - prev-1 );
                    prev = i;
                    c++;
                }
                else
                {
                    prev = i;
                    c++;
                }
            }
        }
        if(ans == -1)
        {
            cout << "none" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}




