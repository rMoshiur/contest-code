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

int ara[505], n;
int mx[505], mn[505];

/*int dpinc( int s )
{
    set<int>ss;
    set<int>::iterator it;
    int ans = -1;
    for( int i = s; i < n; i++ )
    {
        ss.insert(ara[i]);
        it = ss.find(ara[i]);
        it++;
        if( it != ss.end() )
        {
            it--;
            if( it == ss.begin() )
            {
                ss.erase(it);
            }
            else
            {
                it++;
                ss.erase(it);
            }

        }
        ans = max( ans, (int)ss.size() );
    }
    return ans;
}

int dpdec( int s )
{
    multiset<pii, greater<pii> >ss;
    multiset<pii, greater<pii> >::iterator it;
    int c = 10000;
    int ans = -1;
    for( int i = s; i < n; i++ )
    {
        ss.insert( mp(ara[i], c--));
        it = ss.find( mp(ara[i], c+1));
        it++;
        if( it != ss.end() )
        {
            it--;
            if( it == ss.begin() )
            {
                ss.erase(it);
            }
            else
            {
                it++;
                ss.erase(it);
            }

        }
        ans = max( ans, (int)ss.size() );
    }
    return ans;
}
*/
int main()
{
    //ios::sync_with_stdio(false);
    filein;
    scanf("%d", &n);
    while(n!=0)
    {
        int ans = 1;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &ara[i]);
        }
        mx[n-1] = mn[n-1] = 1;
        for( int i = n-2; i >= 0; i-- )
        {
            int mxt = 0, mnt = 0;
            for( int j = i+1; j < n; j++ )
            {
                if( ara[j] > ara[i] )
                    mxt = max( 1+mxt, mx[j] );
                else
                    mnt = max( 1+mnt, mn[j] );
            }
            mx[i] = mxt;
            mn[i] = mnt;
            ans = max( ans, mxt+mnt-1 );
        }
        //what_is(n);
        cout << ans << endl;
        scanf("%d", &n);

    }

    return 0;
}




