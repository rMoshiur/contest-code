#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, flag = 0;
        scanf("%d", &n);
        int ara[n];
        for( int i = 0; i < n; i++ ) scanf("%d", &ara[i]);
        for( int i = 2; i < n; i++ )
        {
            if( ara[i-2] == ara[i-1] && ara[i-1] == ara[i] )
            {
                flag =1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}



