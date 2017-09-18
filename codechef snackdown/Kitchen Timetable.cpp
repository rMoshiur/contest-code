#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        long long ara[n], tm[n];
        for( int i = 0; i < n; i++ )
            scanf("%lld", &ara[i]);
        for( int i = 0; i < n; i++ )
            scanf("%lld", &tm[i]);
        long long ans = 0, prev = 0;
        for( int i = 0; i < n; i++ )
        {
            if( ara[i] - prev >= tm[i] )
                ans++;
            prev = ara[i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}
