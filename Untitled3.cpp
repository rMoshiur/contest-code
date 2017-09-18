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
    fileout;
    cout << 100000 << " " << 50000 << endl;
    for(int i = 0; i < 50000; i++)
    {
        if( i%2 ==0 )
        {
            cout << 1 << " " << i << " " << i + 1 << " " << 10000;
        }
        else
            cout << 2 << " " << i << " " << i + 1 ;

    }
    return 0;
}


