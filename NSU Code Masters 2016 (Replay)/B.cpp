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
#define piii        pair<pii, int>

intl mx = 1000000000000LL;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl ara[10000];
    ara[1]= 1;
    for( int i = 2; i <= 1000 && ara[i-1] <= mx; i++)
    {
        if( i%2 == 0 )
            ara[i] = ara[i/2]*ara[i/2]+1;
        else
            ara[i] = ara[i/2]*ara[i/2+1] + 2;
    }
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl a, i = 1;
        cin >> a;
        while( ara[i] != a )
        {
            i++;
        }
        cout << "Case " << caseno++ << ": " << i <<endl;
    }
    return 0;
}



