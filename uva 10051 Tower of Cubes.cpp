#include <bits/stdc++.h>

using namespace std;

int par[510];

void create_set( int n )
{
    for( int i = 1; i <=n; i++ )
        par[i] = i;
    return;
}

int find_par( int a )
{
    if( par[a]==a )
        return a;
    return par[a] = find_par( par[a] );
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n != 0)
    {
        vector<int>vec[107];
        vector<int>data[n+2];
        create_set(n);
        int a;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 0; j < 6; j++ )
            {
                scanf("%d", &a );
                vec[a].push_back(i);
            }
        }
        for( int i = 1; i <= 100; i++ )
        {
            int t = vec[i].size(), x;
            if( t > 0 )
                x = find_par( vec[i][0] );
            for( int j = 1; j < t; j++ )
            {
                int y = find_par( vec[i][j] );
                if( x != y )
                {
                    par[y] = x;
                }
            }
        }
        int ans[n+1];
        memset( ans, 0, sizeof(ans) );
        for( int i = n; i > 0; i-- )
        {
            for( int j = i-1; j > 0; j-- )
            {
                if( (ans[i] + 1) > ans[j] )
                {
                    ans[j] = ans[i] + 1;
                }
            }
        }
        int mm = 0;
        for( int i = 1; i <=n; i++ )
        {
            if( ans[i] > mm )
                mm = ans[i];
        }
        printf("%d\n", mm);
        scanf("%d", &n);
    }
    return 0;
}
