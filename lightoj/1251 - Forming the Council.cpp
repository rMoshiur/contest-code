#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


// x = i, ~x = n+i //n is number of variable
vector<int>edge[22222], sccEdge[22222], transEdge[22222], scctransEdge[22222], scclist[22222];
int scc[22222], topsort[22222], vis[22222], c, sccNo, sign[22222], ans[11111];


void dfs1( int u )
{
    vis[u]= 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( !vis[v] )
        {
            dfs1(v);
        }
    }
    topsort[c++] = u;
}

void dfs2( int u )
{
    vis[u]= 1;
    for( int i = 0; i < transEdge[u].size(); i++ )
    {
        int v = transEdge[u][i];
        if( !vis[v] )
        {
            dfs2(v);
        }
    }
    scclist[sccNo].pb(u);
    scc[u] = sccNo;
}

void dfs3( int u )
{
    vis[u] = 1;
    for( int i = 0; i < sccEdge[u].size(); i++ )
    {
        int v = sccEdge[u][i];
        if( !vis[v] )
        {
            dfs3(v);
        }
    }
    topsort[c++] = u;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        c = 1;
        sccNo = 1;
        memset(vis, 0, sizeof vis);
        memset( scc,0 , sizeof scc );
        int m, n, a, b;
        cin >> m >> n;
        for( int i = 1; i <= 2*n; i++ )
        {
            edge[i].clear();
            transEdge[i].clear();
            sccEdge[i].clear();
            scctransEdge[i].clear();
            scclist[i].clear();
        }
        for( int i = 0; i < m; i++ )
        {
            cin >> a >> b;
            if( a > 0 && b > 0  )
            {
                edge[n+a].pb(b);
                edge[n+b].pb(a);
                transEdge[a].pb(n+b);
                transEdge[b].pb(n+a);
            }
            else if( a > 0 && b < 0 )
            {
                b = -b;
                edge[b].pb(a);
                edge[n+a].pb(n+b);
                transEdge[a].pb(b);
                transEdge[n+b].pb(a+n);
            }
            else if( a < 0 && b > 0 )
            {
                a = -a;
                edge[n+b].pb(n+a);
                edge[a].pb(b);
                transEdge[n+a].pb(n+b);
                transEdge[b].pb(a);
            }
            else
            {
                a = -a;
                b = -b;
                edge[a].pb(n+b);
                edge[b].pb(n+a);
                transEdge[n+b].pb(a);
                transEdge[n+a].pb(b);
            }
        }
        for( int i = 1; i <= 2*n; i++ )
        {
            if( !vis[i] )
            {
                dfs1(i);
            }
        }
        /*for( int i = 1; i <= 2*n; i++ )
        {
            cout << topsort[i] << endl;
        }*/
        memset( vis, 0, sizeof vis );
        for( int i = c-1; i >= 1; i-- )
        {
            if( !vis[topsort[i]])
            {
                //what_is(i);
                dfs2( topsort[i] );
                sccNo++;
            }
        }
        /*for( int i = 1; i <= 2*n; i++ )
        {
            cout << scc[i] << endl;
        }*/
        int f = 1;
        for( int i = 1; i <= n; i++ )
        {
            if( scc[i] == scc[i+n] )
            {
                f = 0;
                break;
            }
        }
        for( int i = 1; i <= 2*n && f == 1; i++ )
        {
            for( int j = 0; j < edge[i].size(); j++ )
            {
                int v = edge[i][j];
                if( scc[i] != scc[v] )
                {
                    sccEdge[ scc[i] ].pb( scc[v] );
                    scctransEdge[ scc[v] ].pb( scc[i] );
                }
            }
        }
        memset( vis, 0, sizeof vis );
        c = 1;
        //what_is( sccNo );
        for( int i = 1; i < sccNo && f == 1; i++ )
        {
            if( !vis[i] )
            {
                //what_is(i);
                dfs3(i);
            }
        }
        //what_is(c);
        /*for( int i = 1; i < c; i++ )
        {
            cout << topsort[i] << endl;
        }
        for( int i  =1; i < c; i++ )
        {
            for( int v: scclist[i] )
            {
                cout << v << " ";
            }
            cout << endl;
        }*/
        memset( sign, -1, sizeof sign );
        for( int i = 1; i < c; i++ )
        {
            int u = topsort[i];
            if( sign[u] == -1 ) sign[u] = 1;
            for( int i = 0; i < scclist[u].size(); i++ )
            {
                int v = scclist[u][i];
                if( v > n && sign[ scc[v-n] ] == -1 )
                {
                    sign[ scc[v-n] ] = !sign[u];
                }
            }
            for( int i = 0; i < scctransEdge[u].size(); i++ )
            {
                int v = scctransEdge[u][i];
                cout << u << " " << v << endl;
                if( sign[v] == -1 )
                {
                    sign[v] = !sign[u];
                }
            }
        }

        c = 0;
        for( int i = 1; i <= n && f == 1; i++ )
        {
            if( sign[ scc[i] ] == 1 )
            {
                //what_is(i);
                ans[c++] = i;
            }
        }

        if( f == 0 )
        {
            cout << "Case " << caseno++ << ": No" << endl;
        }
        else
        {
            cout << "Case " << caseno++ << ": Yes" << endl;
            cout << c;
            for( int i = 0; i < c; i++ )
            {
                cout << " " << ans[i];
            }
            cout << endl;
        }

    }
    return 0;
}
