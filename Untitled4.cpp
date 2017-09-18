#include<bits/stdc++.h>

using namespace std;

struct node
{
    int x, y, w;
};

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, e, t;
    scanf("%d", &t);
    while(t--)
    {
        bool flag = 1;
        scanf("%d %d", &n, &e);
        node ara[e];
        for( int  i = 0; i < e; i++ )
        {
            scanf("%d %d %d", &ara[i].x, &ara[i].y, &ara[i].w);
        }
        int distance[n];
        for( int i = 0; i < n; i++ )
            distance[i] = 1<<30;
        distance[0] = 0;
        for( int i = 1; i < n; i++ )
        {
            for( int j = 0; j < e; j++)
            {
                if( (distance[ara[j].x]+ara[j].w) < distance[ara[j].y] )
                    distance[ara[j].y] = distance[ara[j].x]+ara[j].w;
            }
        }
        //cout << "yes\n";
        for( int j = 0; j < e; j++ )
        {
            if( (distance[ara[j].x]+ara[j].w) < distance[ara[j].y] )
                {
                    flag = 0;
                }
        }
        if( flag  == 1 )
        {
            printf("not possible\n");
        }
        else
        {
            printf("possible\n");
        }
    }
    return 0;
}
