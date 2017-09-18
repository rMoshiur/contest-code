#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

///LCA O(logn)
//create par[] = parent of a vertex via dfs,
//create depth[] = level of a vertex from root via dfs
const int factor = 18;
void create_lca( int par[], int n ) // n is number of vertex
{
    for( int i = 0; i <= n; i++ )
        lca[0][i] = par[i];
    for( int j = 1; j <= factor; j++ )
    {
        for( int i = 0; i <= n; i++ )
        {
            if( lca[j-1][i] != -1 )
                lca[j][i] = lca[j-1][ lca[j-1][i] ];
        }
    }
}

int find_lca( int u, int v )
{
    if( depth[u] < depth[v] )//after this u is deeper than v
    {
        int t = u;
        u = v;
        v = t;
    }
    int diff = depth[u] - depth[v];
    int c = 0;
    while( diff > 0 )
    {
        if( diff&1 )
            u = lca[c][u];
        diff/=2;
        c++;
    }
    for( int i = factor; i >= 0; i--  )
    {
        if( lca[i][u] != lca[i][v] )
        {
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;


    return 0;
}



