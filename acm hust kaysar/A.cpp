#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb         long double



int main()
{
    ios::sync_with_stdio(false);
    filein;
    vector<set<int>>vec(200005);
    map<int, int>mx;
    set<int>mxx;
    //int ara[20005];
    int c = 1;
    int q;
    cin >> q;
    string s;
    int x, y;
    while(q--)
    {
        cin >> s >> x >> y;
        cin.ignore();
        if( s == "add" )
        {
            if( mx.count(x) < 1 )
            {
                mx[x] = c;
                //ara[c] = x;
                c++;
            }
            int xp = mx[x];
            vec[xp].insert(y);
            mxx.insert(x);

        }
        else if( s == "remove" )
        {
            int xp = mx[x];
            auto it = vec[xp].find(y);
            vec[xp].erase(it);
            if( vec[xp].empty() )
            {
                mxx.erase(x);
            }
        }
        else
        {
            auto ix = mxx.upper_bound(x);
            if( ix == mxx.end() )
            {
                cout << -1 << endl;
                continue;
            }
            int nx = *ix;
            int xp = mx[nx];
            auto iy = vec[xp].upper_bound(y);
            if( iy == vec[xp].end() )
            {
                cout << -1 << endl;
                continue;
            }
            int ny = *iy;
            cout << nx << " " << ny << endl;
        }
    }

    return 0;
}




