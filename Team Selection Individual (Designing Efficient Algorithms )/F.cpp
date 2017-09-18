#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

char s1[150005], s2[150005];
int ara[150005], sum[150005];


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, p;
    scanf("%d %d", &n, &p);
    while( n != 0 )
    {
        sum[0] = 0;
        scanf("%s %s", s1, s2);
        for( int i = 0; i < n; i++ )
        {
            if( s1[i] == s2[i] ) ara[i] = 1;
            else ara[i] = 0;
            sum[0] = ara[0];
            if( i>0 )
                sum[i] = sum[i-1] + ara[i];
        }

        int l = 0, h = 1

        scanf("%d %d", &n, &p);
    }

    return 0;
}





