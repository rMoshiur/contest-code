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


vector<int> vec[100];
vector<int> visited(101); // 0=white  1=ash  2=black
vector<int> st(101);
vector<int> et(101);
int v, e, tim = 0;

int dfs( int n )
{
    st[n] = tim++;
    visited[n] = 1;
    for( int i = 0; i < vec[n].size(); i++ )
    {
        if( visited[vec[n][i]] == 0 )
            dfs( vec[n][i] );
    }
    et[n] = tim++;
    visited[n] = 2;
}


int main()
{
    ios::sync_with_stdio(false);
    filein;
    cin >> v >> e;
    for( int i = 0; i < e; i++ )
    {
        int a, b;
        cin >> a >> b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    dfs(1);
    for( int i = 1; i <= v; i++ )
    {
        cout << i << " st "  << st[i] << " et " << et[i] << endl;
    }
    return 0;
}



