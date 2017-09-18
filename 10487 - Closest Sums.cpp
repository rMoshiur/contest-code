#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int caseno = 1, n, xx;
    scanf("%d", &n);
    while( n != 0 )
    {
        int ara[n+2];
        for( int i = 0; i < n; i++  )
        {
            scanf(" %d ", &ara[i]);
        }
        int m;
        scanf("%d", &m);
        printf("Case %d:\n", caseno++);
        while(m--)
        {
            scanf("%d", &xx);
            //cout << "xxxx  " << xx << endl;
            int sum, ans = ara[0] + ara[1], d = abs(ans - xx), temp, a1, a2;
            //cout << "ans   " << ans << "   xxxx  " << xx << "   dddd    " << d << endl;

            for( int i = 0; i < n; i++ )
            {
                for( int j = i + 1; j < n; j++ )
                {
                    sum = ara[i] + ara[j];
                    temp = abs(sum - xx);
                    if( temp < d )
                    {
                        ans = sum;
                        d = temp;
                        //cout << "ans   " << ans << "   dddd    " << d << endl;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", xx, ans);
        }
        scanf("%d", &n);
    }
    return 0;
}
