#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d\n", &t);
    while( t-- )
    {
        char str1[1020];
        char str2[1020];
        gets(str1);
        int n = strlen(str1);
        int j = 0;
        for( int i = n-1; i >= 0; i-- )
        {
            str2[j++] = str1[i];
        }
        str2[j] = '\0';
        //puts(str1);
        //puts(str2);
        int ara[n+1][n+1];
        for(int i = 0; i <= n; i++ )
        {
            for( j = 0; j <= n; j++ )
            {
                if( i == 0 || j == 0 )
                    ara[i][j] = 0;
                else if(  str1[i-1] == str2[j-1] )
                    ara[i][j] = ara[i-1][j-1] + 1;
                else
                {
                    ara[i][j] = max( ara[i-1][j], ara[i][j-1] );
                }
            }
        }
        printf("%d\n", ara[n][n]);
    }
    return 0;
}
