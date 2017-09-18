#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        unsigned long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

vector<intl>vec;
intl c = 0;
map<intl, intl>mm;

intl dfs( intl a )
{
    //what_is(a);
    //c++;
    if( a == 1 )
        return 1;
    if( mm.count(a) > 0 )
        return vec[mm[a]];
    mm[a] = c++;
    intl temp;
    if( a%2 == 0 )
    {
        temp = dfs(a/2)*dfs(a/2) + 1;
        vec[mm[a]] = temp ;
    }
    else
    {
        temp = dfs(a/2+1)*dfs(a/2) + 2;
        vec[mm[a]] =  temp ;
    }
    //return temp;
    return vec[mm[a]];
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl t, caseno=1;
    cin >> t;
    while(t--)
    {
        vec.resize(100000);
        c = 0;
        intl x;
        cin >> x;
        intl ans = dfs(x);
        //what_is(c);
        cout << "Case " << caseno++ << ": " << ans << endl;
        vec.clear();
        mm.clear();
    }

    return 0;
}



