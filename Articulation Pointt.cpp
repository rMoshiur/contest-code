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

const int mx = 10005;

bool isvis[mx];
bool isart[mx];
int par[mx];
vector<int>edge[mx];
int low[mx];
int disc[mx];
int tt, child;

void dfs( int u )
{
    low[u] = disc[u] = tt++;
    isart[u] = 0;
    isvis[u] = 1;
    int l = edge[u].size();
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( !isvis[v] )
        {
            if( par[u] == -1 ) child++;
            par[v] = u;
            dfs(v);
            low[u] = min( low[u], low[v] );
        }
        else if(  )
    }
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int v, e;
    cin >> v >> e;
    for( int i = 0; i < e; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }

    memset(  )

    return 0;
}



