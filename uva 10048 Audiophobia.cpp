#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int caseno = 1;
    int c, e, q;
    scanf("%d %d %d", &c, &e, &q);
    while( c != 0 || e != 0 || q != 0 )
    {
        int ara[c+5][c+5];
        int temp = 1<<30, x, y, z;
        for( int i = 1; i<= c; i++ )
        {
            for( int j = 1; j <= c; j++ )
                ara[i][j] = temp;
        }
        for( int i = 1; i <= e; i++ )
        {
            scanf("%d %d %d", &x, &y, &z );
            ara[x][y] = z;
            ara[y][x] = z;
        }
        for(int k = 1; k<= c; k++)
        {
            for( int i = 1; i <= c; i++ )
            {
                for( int j = 1; j <= c; j++ )
                {
                    if( ara[i][j] > ara[i][k] && ara[i][j] > ara[k][j] )
                    {
                        ara[i][j] = max( ara[i][k], ara[k][j] );
                    }
                }
            }
        }
        if( caseno != 1 ) printf("\n");
        printf("Case #%d\n", caseno++);
        while(q--)
        {
            scanf("%d %d", &x, &y);
            if( ara[x][y] != temp )
                printf("%d\n", ara[x][y]);
            else
                printf("no path\n");
        }
        scanf("%d %d %d", &c, &e, &q);

    }

    return 0;
}
