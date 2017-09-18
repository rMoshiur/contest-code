#include <bits/stdc++.h>

using namespace std;
int ara[10000001];

int main()
{
    freopen("input.txt", "r", stdin);
    int n,a ;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        ara[a]++;
    }
    return 0;
}
