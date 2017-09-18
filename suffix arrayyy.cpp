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

bool comp( pair<pii, int> a, pair<pii, int> b )
{
    if( a.xx.xx == b.xx.xx )
        return a.xx.yy < b.xx.yy;
    else
        return a.xx.xx < b.xx.xx;
}

void buildarray( string &s, int sa[] )
{
    int len = s.size();
    int temp[20][len];
    for( int i = 0; i < len; i++ )
        temp[0][i] = s[i] - 'a';
    pair<pii, int> ara[len];
    for( int i = 0, j = 1; j < len; i++, j*=2 )
    {
        for( int c = 0; c < len ; c++ )
        {
            ara[c].xx.xx = temp[i][c];
            ara[c].xx.yy = (c+j < len)? temp[i][c+j]: -1;
            ara[c].yy = c;
        }
        sort( ara, ara+len, comp );
        int r = 0;
        temp[i+1][ara[0].yy] = r;
        for( int c = 1; c < len; c++ )
        {
            if( ara[c].xx.xx != ara[c-1].xx.xx || ara[c].xx.yy != ara[c-1].xx.yy )
                r++;
            temp[i+1][ara[c].yy] = r;
        }
    }
    for( int i = 0; i < len; i++ )
    {
        sa[i] = ara[i].yy;
        cout << sa[i] << " ";
    }
}

void buildlcp( string &s, int sa[] )
{
    int len = s.size();
    int lcp[len];
    lcp[len-1] = 0;
    int temp[len];
    for( int i = 0; i < len; i++ )
        temp[sa[i]] = i;
    int k = 0;
    for( int i = 0; i < len; i++ )
    {
        int cur = temp[i];
        if( cur == len-1 )
        {
            k = 0;
            continue;
        }
        int next = sa[cur+1];
        while( i+k < len && next + k < len && s[i+k] == s[next+k] )
            k++;
        lcp[cur] = k;
        if( k > 0 )
            k--;
    }

    for( int i = 0; i < len; i++ ) cout << lcp[i] << " ";
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    int n = s.size();
    int sa[n];
    buildarray(s, sa);
    buildlcp(s, sa);
    return 0;
}


