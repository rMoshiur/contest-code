#include <bits/stdc++.h>

using namespace std;

const int n = 100000;

vector< pair<pair<int,int>, int> > edge; //save edges along with weight
int par[n]; //save the parent of every node

int find_parent( int x )
{
    if( par[x] == x )
        return x;
    par[x] = find_parent( par[x] );
    return par[x];
}

int main()
{
    int v, e, te = 0, tw = 0; //vertex, edge, tree_edge, tree_weight
    scanf("%d %d", &v, &e);
    for( int i = 0; i<= v; i++ )
    {
        par[i] = i;
    }
    for( int i = 0; i < e; i++ )
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back( {{a,b}, c} );
    }

    sort( edge.begin(), edge.end(), [](pair<pair<int,int>, int> p, pair<pair<int,int>, int> q){ return p.second < q.second; } );

    for( int i = 0; i < e; i++ )
    {
        int pa = edge[i].first.first;
        int pb = edge[i].first.second;
        if( pa != pb )
        {
            te++;
            par[pa] = pb;
            tw += edge[i].second;
        }
    }

    printf("total tree weight is: %d\n", tw);
    return 0;

}
