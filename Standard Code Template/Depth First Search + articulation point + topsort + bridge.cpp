/*
    DEPTH FIRST SEARCH (DFS)
    O(V+E)
*/
#include <bits/stdc++.h>

using namespace std;
const int mx = 10000;


int discovery_time[mx], finishing_time[mx], low[mx];
vector<bool>is_vis(mx, 0);
vector<int>parent(mx, -1);
int Time = 1;
vector<int>edge[mx];

void dfs( int u )
{
    is_vis[u] = 1;
    low[u] = discovery_time[u] = Time++;
    int l = edge[u].size();
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( is_vis[v] == 0 )
        {
            parent[v] = u;
            dfs(v);
            low[u] = min( low[u], low[v] );
        }
        else if( v != parent[u] )
        {
            low[u] = min( low[u], discovery_time[v] );
        }
    }
    finishing_time[u] = Time++;
    // u is articulation point if low[v] >= discovery_time[u] //O(E+V)
    // u-v is a bridge if low[v] > discovery_time[u] // O(E+V)
    // sort by finishing time is a dag ( higher to lower ) you will get topsort result //O(E+Vlogn)
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertex, edg;
    cin >> vertex >> edg;
    for( int i = 0; i < edg; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for( int i = 1; i <= vertex; i++ )
    {
        if( is_vis[i] == 0 )
             dfs(i);
    }

    for( int i = 1; i <= vertex; i++ )
    {
        cout <<"vertex " << i << " dis " << discovery_time[i] << " fin " << finishing_time[i] << " low " << low[i] << " par " << parent[i] << endl;
    }
}
