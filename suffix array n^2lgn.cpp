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

bool comp( pair<string,int> a, pair<string,int> b )
{
    return a<b;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    vector<pair<string,int>>vec;
    int l = s.size();
    for( int i = 0; i < l; i++ )
    {
        vec.pb( {s.substr(i,l), i} );
    }
    sort( vec.begin(), vec.end(), comp );
    for( int i = 0; i < l; i++ )
    {
        cout << setw(14) << vec[i].xx << "  " << vec[i].yy << endl;
    }
    return 0;
}



