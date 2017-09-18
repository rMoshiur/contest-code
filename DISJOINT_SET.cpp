#include <bits/stdc++.h>

using namespace std;

int node, edge, par[100000];
struct data
{
    int x, y;
};

void make_set()
{
    for( int i = 1; i <= node; i++ )
        par[i] = i;
}

int find_parent( int n )
{
    if( par[n] == n )
        return n;
    par[n] = find_parent( par[n] );
    return par[n];
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &node, &edge);
    data vertex[edge];
    for( int i = 0; i < edge; i++ )
    {
        scanf("%d %d", &vertex[i].x, &vertex[i].y);
    }
    int c = 1;
    make_set();
    //cout << find_parent( vertex[0].x ) << endl;
    for( int i = 0 ; i < edge && c <= node; i++ )
    {
        int pa = find_parent(vertex[i].x), pb = find_parent(vertex[i].y);
        //cout << pa << "  " << pb << endl;
        if( pa != pb )   ///union of two graph component
        {
            //cout << "yes\n";
            par[pa] = pb;
            c++;
        }
    }
    for( int i = 1; i <= node; i++ )
    {
        par[i] = find_parent( par[i] );
        cout << par[i] << endl;
    }

    return 0;
}
