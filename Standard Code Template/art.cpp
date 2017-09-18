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




int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);
    filein;
    int v, e, a, b;
    cin >> v >> e;
    for( int i = 0; i < e; i++ )
    {
        scanf("%d %d", &a, &b);
        edge[a].pb(b);
        edge[b].pb(a);
    }



    return 0;
}




