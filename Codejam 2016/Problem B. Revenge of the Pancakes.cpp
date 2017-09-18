#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("B-large.in", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    ios::sync_with_stdio(false);
    filein;
    //fileout;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        string s;
        int ans = 0;
        cin >> s;
        cout << s << endl;
        for( int i = 0; i < s.size(); i++ )
        {
            int k;
            if( s[i] == '-' )
            {
                k = i;
                while( i < ( s.size()-1 ) && s[i+1] == '-' )
                {
                    i++;
                }
                for( int j = k; j <= i; j++ )
                {
                    s[j] = '+';
                }
            }
            else
            {
                k = i;
                while( i < ( s.size()-1 ) && s[i+1] == '+' )
                {
                    i++;
                }
                if( i != ( s.size() - 1 ) )
                {
                    for( int j = k; j <= i; j++ )
                    {
                        s[j] = '-';
                    }
                }
               else
                    break;
            }
            i = k-1;
            ans++;
            //debug;
        }
        cout << "Case #" << caseno++ << ": " << ans << endl;
    }

    return 0;
}


