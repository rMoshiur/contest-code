#include <bits/stdc++.h>

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

int a1[70000], a2[70000];
int p, q, s;
int ara[70000];
vector<int> vec;

int main()
{
    //filein;
    int t, caseno = 1, n;
    cin >> t;
    while( t-- )
    {
        scanf("%d %d %d", &n, &p, &q);
        p++;
        q++;
        memset( ara, -1, sizeof(ara) );
        for( int i = 0; i < p; i++  )
        {
            scanf("%d", &s);
            ara[s] = i + 1;
        }
        for( int i = 0; i < q; i++  )
        {
            scanf("%d", &s);
            if( ara[s] != -1 )
                vec.pb(ara[s]);
        }
        int x = vec.size();
        set<int> ss;
        for( int i = 0; i < x; i++ )
        {
            ss.insert(vec[i]);
            set<int>::iterator y = ss.find(vec[i]);
            y++;
            if( y != ss.end() )
                ss.erase(y);
        }
        printf("Case %d: %d\n", caseno++, ss.size());
        ss.clear();
        vec.clear();
    }

    return 0;
}


