#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

bool comp( pii a, pii b )
{

    return a.yy < b.yy;
}

bool comp2( pii a, pii b )
{
    return a.xx < b.xx;
}


int main()
{
    //filein;
    int n, m;
    cin >> n >> m;
    vector<pii> vec;

    for( int i = 0; i < n; i++ )
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vec.pb(mp(a,b));
    }

    sort( vec.begin(), vec.end(), comp );

    /*for( int i = 0; i < n; i++ )
    {
        cout << vec[i].xx << " " << vec[i].yy << endl;
    }
    debug;*/
    vector<pii> v;

    for( int  i=0 ; i < m; i++  )
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.pb(mp(a,b));
    }
    sort( v.begin(), v.end(), comp2 );

    /*for( int i = 0; i < m; i++ )
    {
        cout << v[i].xx << " " << v[i].yy << endl;
    }
    debug;*/
    int ara[n];
    for( int i =0; i < n; i++ ) ara[i] = -1;
    int c = 0, x = 0;
    for( int i = 0; i < m; i++ )
    {
        int k = v[i].xx;
        for( int j = 0; j < n && v[i].yy > 0; j++  )
        {
            if( vec[j].xx <= k && vec[j].yy >= k && ara[j] == -1 )
            {
                c++;
                ara[j] = 1;
                //cout << vec[j].xx << " " << vec[j].yy << endl;
                v[i].yy--;
            }
        }
    }
    cout << c << endl;
    return 0;
}



