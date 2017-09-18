#include <bits/stdc++.h>

int main()
{
    char ara[100][100] = {"NULL", "sondhi", "araf", "arnob", "tanveer", "akash", "abed"};
    int n = 6, rnk = -1;
    //rank of akash
    for( int i = 0; i <= n; i++ )
    {
        if( !strcmp(ara[i],"akash") )
        {
            rnk = i;
            break;
        }
    }
    printf("rank of akash %d\n", rnk);
    //process akash
    n--;
    for( int i = rnk; i <= n; i++ )
    {
        int len = strlen(ara[i+1]);
        for( int j = 0; j < len; j++ )
        {
            ara[i][j] = ara[i+1][j];
        }
        ara[i][len] = '\0';
    }
    //current ara
    for( int i = 1; i <= n; i++ )
    {
        printf("%s ", ara[i]);
    }
    puts("");
    return 0;
}
