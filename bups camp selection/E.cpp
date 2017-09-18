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
const int SZ = 1000005, mod = 1000000007, s = 11;

intl ara[11][11], mx, ans[s][s];
intl temp[s][s];

void multiply( intl ara1[s][s], intl ara2[s][s] )
{
    for( int i = 0; i < mx; i++ )
    {
        for( int j = 0; j < mx; j++ )
        {
            intl sum = 0;
            for( int k = 0; k < mx; k++ )
            {
                sum += (ara1[i][k]*ara2[k][j])%mod;
            }
            sum %= mod;
            temp[i][j] = sum;
        }
    }

    for( int i = 0; i < mx; i++ )
    {
        for( int j = 0; j < mx; j++ )
        {
            ara1[i][j] = temp[i][j];
        }
    }
}

void power( intl ans[s][s], intl x )
{
    if( x == 1 )
        return;
    power(ans, x/2);
    multiply( ans, ans );
    if( x&1 )
    {
        multiply( ans, ara );
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl k, n;
        cin >> k >> n;
        cout << "Case " << caseno++ << ": ";
        if( n < k )
        {
            cout << 1 << endl;
            continue;
        }
        if( n == k )
        {
            cout << 2 << endl;
            continue;
        }
        memset( ara, 0, sizeof ara );
        ara[0][0] = ara[0][k-1] = 1;
        for( int i = 1; i < k; i++ )
        {
            ara[i][i-1] = 1;
        }
        mx = k;
        for( int i = 0; i < mx; i++ )
        {
            for( int j = 0; j < mx; j++ )
            {
                ans[i][j] = ara[i][j];
            }
        }
        intl p = n-k;
        power( ans, p );

        intl sol = 0;
        for( int i = 0; i < k; i++ )
        {
            if( i == 0 )
            {
                sol += 2*ans[0][i];
            }
            else
                sol += ans[0][i];
        }
        sol %= mod;
        cout << sol << endl;
    }

    return 0;
}



