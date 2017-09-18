#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while( scanf("%d", &n) != EOF )
    {
        int k;
        scanf("%d", &k);
        int ara[k];
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &ara[i]);
        }
        sort( ara, ara+k);
        bool flag[n+1];
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < n; i++)
        {
            if( flag[i] == 0 )
            {
                for( int j = 0; j < k && (i+ara[j]) <= n; j++ )
                {
                    flag[i+ara[j]] = 1;
                }
            }
        }
        if( flag[n] == 1 )
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
