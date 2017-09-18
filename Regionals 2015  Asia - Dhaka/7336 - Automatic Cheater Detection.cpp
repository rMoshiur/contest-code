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
#define what(x)     cout << #x << " is " << x << " "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define lldb        long double

struct data
{
    int d, s;
    char r;
};

int n, a, b, c;
char ch;
int bit[50005];
data mcq[50005];

bool comp( data a, data b )
{
    if( a.d == b.d )
    {
        return a.s > b.s;
    }
    return a.d < b.d;
}

void update( int x, int val )
{
    while( x <= n )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x )
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            cin >> a >> b >> ch;
            mcq[i] = {a,b,ch};
        }
        sort(mcq+1, mcq+n+1, comp);
       /* for( int i = 1; i <= n; i++ )
        {
            cout << mcq[i].d << " " <<  mcq[i].s << " " << mcq[i].r << endl;
        }*/
        intl ans = 0;
        for( int i = n; i > 0; i-- )
        {
            if( mcq[i].s == 1 && mcq[i].r == 'c' )
            {
                update(i, 1);
            }
            if( mcq[i].s == 0 && mcq[i].r == 'i' )
            {
                ans += query(n);
            }
        }
        memset(bit, 0, sizeof(bit));
        cout << ans << endl;
    }

    return 0;
}
