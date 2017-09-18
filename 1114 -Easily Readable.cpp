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

struct trie
{
    bool word;
    int d;
    int next[52];
};

trie tr[10010];
int node = 1;

int idd( char c )
{
    return (c >= 'a')? 26 + c - 'a': c - 'a';
}

void init( int cn )
{
    tr[cn].word = false;
    tr[cn].d = 0;
    for( int i = 0; i < 52; i++ )
        tr[cn].next[i] = -1;
    return;
}

void insert( const string &s )
{
    int cn = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        int id = idd(s[i]);
        if( tr[cn].next[id] == -1 )
            cn = tr[cn].next[id] = node++;
        else
            cn = tr[cn].next[id];
        init(cn);
    }
    tr[cn].word = true;
    tr[cn].d++;
    return;
}

int query( const string &s )
{
    int cn = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        int id = idd(s[i]);
        if( tr[cn].next[id] == -1 )
            return 0;
        cn = tr[cn].next[id];
    }
    return tr[cn].d;
}


int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, m;
        string s;
        for( int i = 0; i < n; i++ )
        {
            cin >> s;
            sort( s.begin() + 1, s.end() - 1 );
            insert(s);
        }
        cin >> m;
        cin.ignore();
        cout << "Case " << caseno++ << ":\n";
        for( int i = 0; i < m; i++ )
        {
            long long ans = 1, d;
            getline( cin, s );
            stringstream ss(s);
            while( ss >> s )
            {
                cout << s << endl;
                sort( s.begin() + 1, s.end() - 1 );
                d = query(s);
                ans *= d;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}



