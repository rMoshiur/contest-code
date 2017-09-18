# include <bits/stdc++.h>

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while( scanf("%d",&n) != EOF )
    {
        int ara[109], col[109][109], smoke[109][109];
        int temp;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
        }
        for( int i = 0; i < n; i++ )
        {
            col[i][i] = ara[i];
            for( int j = i+1; j < n; j++ )
            {
                col[i][j] = ( col[i][j-1] + ara[j] )%100;
            }
        }
        for(int l = 2; l <= n; l++)
        {
            int xx = n-l+1;
            for(int i = 0; i < xx; i++)
            {
                int j = i+l-1;
                int minim = 1<<30 ;
                for(int k = i; k <= j-1; k++)
                {
                    temp = smoke[i][k] + smoke[k+1][j] + col[i][k]*col[k+1][j];
                    if( temp<minim )
                    {
                        minim = temp;
                        smoke[i][j] = minim ;
                    }
                }
            }
        }
        int ans;
        printf("%d\n",smoke[0][n-1]);
    }
    return 0;
}
