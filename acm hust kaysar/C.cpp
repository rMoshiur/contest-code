#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


intl bit[1100][1100];

void update( int x, int y, int val )
{
    while( x < 1100 )
    {
        int k = y;
        while( k < 1100 )
        {
            bit[x][k] += val;
            k += (k&(-k));
        }
        x += (x&(-x));
    }
}

intl query( int x, int y )
{
    intl ans = 0;
    while( x > 0 )
    {
        int k = y;
        while( k > 0 )
        {
            ans += bit[x][k];
            k -= (k&(-k));
        }
        x -= (x&(-x));
        //what_is(x);
    }
    //what_is(ans);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int a, v ,p, q, r, s, n;
    cin >> a;
    while( a != 3 )
    {
        //what_is(a);
        if( a == 0 )
        {
            cin >> n;
            memset(bit, 0, sizeof(bit));
        }
        else if( a == 1 )
        {
            cin >> p >> q >> v;
            p++;
            q++;
            update(p,q,v);
        }
        else if(a == 2)
        {
            cin >> p >> q >> r >> s;
            p++;
            q++;
            r++;
            s++;
            //debug;
            intl ans = query(r,s) - query(r,q-1) - query(p-1, s) + query(p-1, q-1);
            //what_is(ans);
            cout << ans << endl;
        }
        cin >> a;
    }

    return 0;
}




