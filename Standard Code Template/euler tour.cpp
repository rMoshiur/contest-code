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

const int mx = 1000;
stack<int>st;
vector<int>edge[mx];
vector<int>tour;
map<pii,int>mm;

void euler_tour( int u )
{
    for( int i = edge[u].size() - 1; i >= 0 ; i-- )
    {
        int v = edge[u][i];
        edge[u].pop_back();
        int a = min(u,v),b = max(u,v);//for undirected graph
        if( mm[mp(a,b)] )
        {
            mm[mp(a,b)]--;
            euler_tour(v);
        }
    }
    tour.pb(u);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int v,e;
    scanf("%d %d", &v, &e);
    for( int i = 0; i < e; i++ )
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int u = min(a,b), v = max(a,b);
        mm[mp(u,v)]++;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    euler_tour(1);
    for( int i = 0; i < tour.size(); i++ )
    {
        cout << tour[i] << " ";
    }
    return 0;
}




