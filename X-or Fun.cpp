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
    int ara[] = { 1,2,4,5,3,5,6,3,6,7,5,7 };
    sort( ara, ara+12 );
    for( int i = 0; i < 12; i++ )
    {
        cout << ara[i] << ' ';
    }
    cout << endl;
    int d = unique(ara, ara+12) -ara;
    resize( ara, 7 );
    for( int i = 0; i < d; i++ )
    {
        cout << ara[i] << ' ';
    }
    return 0;
}



