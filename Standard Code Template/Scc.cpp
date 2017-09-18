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

const int mx = 100000;
vector<int>edge[mx];
int vis[mx], in[mx];
stack<int>st;
//memset edge, vis, st
//this dfs sort by finishing time top of stack = higher finishing time
void dfs( int u )
{
    vis[u] = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( !vis[v] )
            dfs( v );
    }
    st.push(u);
}

int main()
{
    //ios::sync_with_stdio(false);
    filein;
    int v, e;
    cin >> v >> e;
    for( int i = 0; i < e; i++ )
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].pb(b);
        in[b]++;
    }
    for( int  i = 0; i < v; i++ )
    {
        if( !in[i] )
            dfs(i);
    }
    while( !st.empty() )
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}



