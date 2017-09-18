#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m, s = 0, a, b, c, d, ans=0;
    scanf("%d %d", &n, &m);
    int rod1[n+2], rod2[n+2], cow1[m+2], cow2[m+2];
    for( int i = 0; i < n; i++ )
    {
        scanf("%d %d", &a, &rod2[i]);
        s += a;
        rod1[i] = s;
    }
    s = 0 ;
    for( int i = 0; i < m; i++ )
    {
        scanf("%d %d", &a, &cow2[i]);
        s += a;
        cow1[i] = s;
    }
    for( int i = 0; i < m; i++ )
    {
         if( i <= 0)
         {
             a = 0;
             b = cow1[i];
         }
         else
         {
             a = cow1[i-1] + 1;
             b = cow1[i];
         }
         for( int j = 0; j < n; j++ )
         {
             if( j <= 0)
             {
                 c = 0;
                 d = rod1[j];
             }
             else
             {
                 c = rod1[j-1] + 1;
                 d = rod1[j];
             }
             if( !( (a < c && b < c) || (a > d && b > d) )  )
             {
                 if( cow2[i] > rod2[j] )
                 {
                     ans = max( ans, cow2[i] - rod2[j] );
                 }
             }
         }
    }
    printf("%d\n", ans);
    return 0;
}
