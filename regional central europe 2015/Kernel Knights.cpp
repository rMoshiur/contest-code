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
#define what(x)     cout << #x << " is " << x << " "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define lldb        long double

intl level[200005], vis[200005];
intl play[200005], in[200005], c, par[20005];
vector<intl>vec;
void bfs( intl u )
{
    level[u] = 0;
    queue<int>qq;
    qq.push(u);
    while( !qq.empty() )
    {
        intl v = qq.front();
        qq.pop();
        vis[v] = 1;
        if( level[v]%2 == 0 )
        {
            vec.pb(v);
        }
        intl child = play[v];
        if( vis[child] == 0 )
        {
            level[child] = level[v] + 1;
            qq.push(child);
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    intl n;
    while( scanf("%lld", &n) == 1 )
    {
        c = 1;

        memset( in, 0, sizeof(in) );
        memset( level, 0, sizeof(level) );
        memset( vis, 0, sizeof(vis) );
        for( ; c<= 2*n; c++ )
        {
            scanf("%lld", &play[c] );
            in[ play[c] ]++;
            par[ play[c] ] = c;
        }
        for( int i = 1; i <= 2*n; i++ )
        {
            if( in[i] == 0 )
            {
                vec.pb(i);
                vis[ i ] = 1;
                vis[ play[i] ] = 1;
            }
        }
        for( int i = 1; i <= 2*n; i++ )
        {
            if( vis[i] == 0 )
            {
                //what_is(i);
                bfs(i);
            }
        }
        printf("%lld", vec[0]);
        for( int i = 1; i < vec.size(); i++ )
        {
            printf(" %lld", vec[i]);
        }
        puts("");
        vec.clear();
    }

    return 0;
}



