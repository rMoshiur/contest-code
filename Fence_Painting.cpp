#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d, ans = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if( a > c )
    {
        if( a <= d && b <= d)
        {
            ans = d - c;
        }
        else if( a <= d )
        {
            ans = b - c;
        }
        else
        {
            ans = d - c + b - a;
        }
    }
    else
    {
        if( c <= b && d <= b )
        {
            ans = b - a;
        }
        else if(c <= b)
        {
            ans = d - a;
        }
        else
            ans = d - c + b - a;
    }

    printf("%d\n", ans);

}
