#include <stdio.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases, caseno = 0, n, m, x, y, z;
    char a, b, c;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &n, &m);
        int ara[n];
        for(x = 0; x < n; x++){
            scanf("%d", &ara[x]);
        }
        while(m--){
            scanf("%c", &a);
            if(a == 'S'){
                scanf("%d", &y);
                for(x = 0; x < n; x++){
                    ara[x] = ara[x] + y;
                }
            }
            else if(a == 'M'){
                scanf("%d", &y);
                for(x = 0; x < n; x++){
                    ara[x] = ara[x] * y;
                }
            }
            else if(a == 'D'){
                scanf("%d", &y);
                for(x = 0; x < n; x++){
                    ara[x] = ara[x] / y;
                }
            }
            else if(a == 'R'){
                for(x = 0, y = n - 1; x < n; x++, y--){
                    z = ara[x];
                    ara[x] = ara[y];
                    ara[y] = z;
                }
            }
            else if(a == 'P'){
                scanf("%d %d", &y, &z);
                z = ara[x];
                ara[x] = ara[y];
                ara[y] = z;
            }
            cout << " m " << m << endl;
        }
        printf("Case %d:\n", ++caseno);
        for(x = 0; x < n; x++){
            printf("%d ", ara[x]);
        }
        printf("\n");
    }
    return 0;
}
