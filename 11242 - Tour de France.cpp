#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int f, r;
    scanf("%d", &f);
    while( f!= 0 )
    {
        scanf("%d", &r);
        int fr[f], re[r];
        for( int i = 0; i < f; i++ )
        {
            scanf("%d", &fr[i]);
        }
        for( int j = 0; j < r; j++ )
        {
            scanf("%d", &re[j]);
        }
        int n = f*r, c = 0;
        double ara[n+2], mm = 0.0;
        for( int i = 0; i < f; i++ )
        {
            for( int j = 0; j < r; j++ )
            {
                ara[c++] = (double)re[j]/fr[i];
                //cout << ara[c-1] << "  " ;
            }
        }
        sort(ara, ara + n );
        //for( int i = 0 ; i < n; i++ )
        //{
            //cout << ara[i] << " ";
        //}
        for( int i = 1; i < n; i++ )
        {
            mm = max( ara[i]/ara[i-1], mm );
        }
        printf("%.2lf\n", mm);
        scanf("%d", &f);
    }
    return 0;
}
