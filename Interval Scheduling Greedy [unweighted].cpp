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


bool comp( pii a, pii b )
{
    return a.yy < b.yy;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;        //number of interval

    vector<pii> iv(n);
    for( int i = 0; i < n; i++ ) cin >> iv[i].xx >> iv[i].yy;  //data input

    sort( iv.begin(), iv.end(), comp );  ///sort by assending ending time

    queue<pii>ans;  //save the answers
    ans.push(iv[0]);
    int te = iv[0].yy; // te - previous works end time

    for( int i = 1; i < n; i++ )
    {
        if( iv[i].xx >= te )
        {
            ans.push(iv[i]);
            te = iv[i].yy;
        }
    }

    cout << "best choice of work: \n";

    while( !ans.empty() )
    {
        cout << setw(4) << ans.front().xx << "  " << setw(4) << ans.front().yy << endl;
        ans.pop();
    }

    return 0;
}



