#include <bits/stdc++.h>

using namespace std;

/*void ccc( int temp[], int a )
{
    long long k = 1;
    for( int i = 0; i < 35 && k <= a; i++ )
    {
        if( a&k ==1 )
            temp[i]++;
        k = k<<1;
    }
    return;
}*/

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n,a ,b, ans;
        scanf("%d", &n);
        int ara[1000];
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            ara[i] = b - a - 1;
            //cout << b << ' ' << a << endl;
            //ccc(temp, b-a-1);
        }
        ans = ara[0];
        //cout << ans << endl;
        for( int i = 1; i < n; i++ )
        {
            ans = ans^ara[i];
            //cout << i << ' ' << ans << endl;
        }
        /*bool flag = 1;
        for( int i = 0; i < 35; i++ )
        {
            if( temp[i]%2 == 1 )
            {
                flag = 0;
                break;
            }
        }*/
        if( ans == 0 )
        {
            printf("Case %d: Bob\n", caseno++);
        }
        else
        {
            printf("Case %d: Alice\n", caseno++);
        }
    }
    return 0;
}
