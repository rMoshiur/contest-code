#include<bits/stdc++.h>

using namespace std;

const int mx = 10005; //highest number of node = 10000 ____ all vertex is greater or equal than 1

int vertex_order_visited_dfs[2*mx], level_of_vertex[2*mx], discovery_time_of_vertex[2*mx];
int tt = 1; //time elapsed
int level = 0; //depth of tree
int sparse_table[mx][25];

void dfs( int current_index )
{
    vertex_order_visited_dfs[tt] = current_index;
    discovery_time_of_vertex[current_index] = tt;
    level_of_vertex[tt++] = level++;

    for( int i = 0; i < edge[current_index].size(); i++ )
    {
        sparse_table[ edge[current_index][i] ][0] = current_index;
        dfs( edge[current_index][i] );
        vertex_order_visited_dfs[tt] = current_index;
        level_of_vertex[tt++] = level;
    }
}

void buildsparse( int root, int number_of_vertex )
{
    dfs(root);
    sparse_table[root][0] = -1;
    for( int i = 1; i < 25; i++ )
        for( int j = 1; j <= number_of_vertex; j++ )
            sparse_table[j][i] = sparse_table[ sparse_table[j][i-1] ][i-1];
}

int lca( int u, int v ) //lca of two vertex u and v
{

}
