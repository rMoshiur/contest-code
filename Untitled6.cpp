#include <bits/stdc++.h>

using namespace std;

int val[10015];

void grundy( )
{
    val[1] = 0;
    val[2] = 0;
    for( int i = 3; i <= 10000; i++ )
    {
        int k = i/2;
        vector<bool> vec(1000, 0);
        for( int j = i -1; j > k; j-- )
        {
            vec[val[j]^val[i - j]] = 1;
        }
        for( int j = 0; j < 1000; j++ )
        {
            if( vec[j] == 0 )
            {
                val[i] = j;
                break;
            }
        }
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    grundy();
    while(t--)
    {
        int n, ans, a;
        scanf("%d", &n);
        scanf("%d", &ans);
        ans = val[ans];
        for( int i = 1; i < n; i++)
        {
            scanf("%d", &a);
            ans = ans^val[a];
        }
        if( ans > 0 )
        {
            printf("Case %d: Alice\n", caseno++);
        }
        else
        {
            printf("Case %d: Bob\n", caseno++);
        }
    }
    return 0;
}
