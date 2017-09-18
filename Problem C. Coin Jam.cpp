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
    //filein;
    fileout;
    int n, m, c = 0;
    cin >> n >> m;
    cout << "Case #1: \n";
    if( n == 16 )
    {
        string s = "1000000000000101";
        int ara[8], even[6];
        for( int i = 2; i < 16; i+=2 )
        {
            ara[i/2-1] = i;
        }
        for( int i = 1; i < 12; i+=2 )
        {
            even[ i/2 ] = i;
        }
        for( int i = 0; i < 7 && c < m; i++ )
        {
            for( int j = i+1; j < 7 && c < m; j++ )
            {
                for( int k = 0; k < 6 && c < m; k++ )
                {
                    string ans = s;
                    ans[ara[i]] = '1';
                    ans[ara[j]] = '1';
                    ans[even[k]] = '1';
                    cout << ans;
                    for( int l = 2; l <= 10; l++ )
                    {
                        cout << " " << l+1;
                    }
                    cout << "\n";
                    c++;
                }
            }
        }
        //what_is(c);
    }
    if( n == 32 )
    {
        string s = "10000000000000000000000000010101";
        int ara[16], even[14];
        for( int i = 2; i < 32; i+=2 )
        {
            ara[ i/2 - 1] = i;
        }
        for( int i = 1; i < 26; i+=2 )
        {
            even[i/2] = i;
        }
        for( int i = 0; i < 15 && c < m; i++ )
        {
            for( int j = i+1; j < 15 && c < m; j++ )
            {
                for( int k = j + 1; k < 15 && c < m; k++ )
                {
                    for( int p = 0; p < 13 && c < m; p++ )
                    {
                        string ans = s;
                        ans[ara[i]] = '1';
                        ans[ara[j]] = '1';
                        ans[ara[k]] = '1';
                        ans[even[p]] = '1';
                        cout << ans;
                        for( int l = 2; l <= 10; l++ )
                        {
                            cout << " " << l+1;
                        }
                        cout << "\n";
                        c++;
                    }
                }
            }
        }
        //what_is(c);
    }
    return 0;
}


