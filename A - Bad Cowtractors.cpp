#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct data
{
    int x, y, w;
};

int n, m;
int par[1010];
data ara[20005];

void makeset()
{
    for(int i = 0; i <= n; i++ )
        par[i] = i;
    return;
}

int find_set( int a )
{
    if( par[a] == a )
        return a;
    return par[a] = find_set(par[a]);
}

;

bool comp( data d1, data d2 )
{
    return d1.w > d2.w;
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    makeset();
    int co = 1, s = 0, re;

    for( int i = 0; i < m; i++ )
    {
        scanf("%d %d %d", &ara[i].x, &ara[i].y, &ara[i].w);
    }
    sort( ara, ara + m, comp );
    re = ara[0].x;
    for( int i = 0; i < m && co < n; i++ )
    {
        int pa = find_set( ara[i].x ), pb = find_set( ara[i].y );
        if( pa != pb )
        {
            s += ara[i].w;
            co++;
            par[ara[i].x] = re;
            par[ara[i].x] = re;

        }
    }
    for( int i = 1; i <= n; i++ )
    {
        if( par[i] != re )
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", s);
    return 0;
}
