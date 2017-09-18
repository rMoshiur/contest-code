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

int scomp( int n, string p, string s )
{
    int l = p.size();
    int ll = s.size();
    for( int i = 0; i < l; i++ )
    {
        if( (n+i) >= ll )
            return 2;
        if( s[n+i] < p[i] )
            return 2;
        if( s[n+i] > p[i] )
            return -1;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    vector<pair<string,int>>vec;
    vector<int>ara;
    int l = s.size();
    for( int i = 0; i < l; i++ )
    {
        vec.pb( {s.substr(i,l), i} );
    }
    sort( vec.begin(), vec.end(), comp );
    for( int i = 0; i < l; i++ )
    {
        ara.pb( vec[i].yy );
        cout << setw(14) << vec[i].xx << "  " << ara[i] << endl;
    }


    string p;
    cin >> p;
    int r = l-1, mid, lb = l, hb = l;
    l = 0;
    while( l <= r )
    {
        mid = (l + r)/2;
        //what_is(ara[mid]);
        int x = scomp( ara[mid], p, s );
        if( x == 1 )
        {
            cout << ara[mid] << endl;
            l = mid + 1;
        }
        else if( x == -1 )
            r = mid - 1;
        else
            l = mid + 1;
    }

    return 0;
}



