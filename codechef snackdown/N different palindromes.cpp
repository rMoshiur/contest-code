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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        string c = "aabbcc";
        int k = n/9, l;
        l = n-k*9;
        for( int i = 0; i < k; i++ )
            s += c;
        char d = 'd';
        for( int i = 0; i < l; i++ )
        {
            s += d;
            d++;
        }
        cout << s << endl;
    }

    return 0;
}



