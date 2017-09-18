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

class comp
{
public:

   bool operator() (  pii a, pii b  )
   {
       if( a.xx == b.xx )
            return a.yy > b.yy;
       return a.xx > b.xx;
   }
};

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    map<pii, int, comp> mm;
    mm.insert({{1,2},60});
    mm.insert({{2,3},100});
    mm.insert({{4,1},70});
    mm.insert({{5,0},50});
    mm.insert({{2,1},100});
    for( auto it = mm.begin(); it != mm.end(); it++ )
    {
        cout << "mm.xx.xx  " << it->xx.xx << " mm.xx.yy " << it->xx.yy << " mm.yy " << it->yy << endl;
    }

    return 0;
}



