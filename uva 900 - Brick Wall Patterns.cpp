#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    int n;
    int ara[100];
    ara[1] = 1;
    ara[2] = 2;
    for( int i = 3; i <= 50; i++ )
    {
        ara[i] = ara[i-1] + ara[i-2];
    }
    scanf("%d", &n);
    while( n!= 0 )
    {
        printf("%d\n", ara[n]);
        scanf("%d", &n);
    }
    return 0;
}
