///LCA O(logn)
//create par[] = parent of a vertex via dfs,
//create depth[] = level of a vertex from root via dfs
//lca[i][j] = 2^i th ancestor of vertex j
const int factor = 18;
void create_lca( int par[], int n ) // n is number of vertex
{
    for( int i = 0; i <= n; i++ )
        lca[0][i] = par[i];
    for( int j = 1; j <= factor; j++ )
    {
        for( int i = 0; i <= n; i++ )
        {
            if( lca[j-1][i] != -1 )
                lca[j][i] = lca[j-1][ lca[j-1][i] ];
        }
    }
}

int find_lca( int u, int v )
{
    if( depth[u] < depth[v] )//after this u is deeper than v
    {
        int t = u;
        u = v;
        v = t;
    }
    int diff = depth[u] - depth[v];
    int c = 0;
    while( diff > 0 )
    {
        if( diff&1 )
            u = lca[c][u];
        diff/=2;
        c++;
    }
    if( v == u) return v; 
    for( int i = factor; i >= 0; i--  )
    {
        if( lca[i][u] != lca[i][v] )
        {
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}


///DISJOINT SET O(n)
//0 _ based index
const int n = 1000000;
int parent[n];
//make every node their own parent
void pre_process(int v)
{
    for( int i = 0; i < v; i++ )
        parent[i] = i;
}
//find the parent of a node
int find_parent( int x )
{
    if( x == parent[x] )
        return x;
    return parent[x] = find_parent( parent[x] );
}
//merge two set via an edge between x and y
void union_( int x, int y )
{
    int px = find_parent( x );
    int py = find_parent( y );
    //here an optimization is possible by considering depth
    if( px != py )
        parent[px] = py;
    return;
}


///TRIE O(word_length)
const int maxn = 100010; //max_word
//returns int value of a character
//memset N, t everytime
inline int code(char c)
{
    if (islower(c))
        return c - 'a' + 26;
    return c - 'A';
}

struct Trie
{
    bool is_word;//finish flag of a word
    int counter; //number of words
    int edges[52];
};

int N = 0;
Trie t[maxn];
//initialize a node
void init(int v)
{
    t[v].is_word = false;
    t[v].counter = 0;
    memset(t[v].edges, -1, sizeof t[v].edges);
    N++;
}
//add_word to the tree
void add_word(const string & s)
{
    int m = s.size();
    int v = 0;
    for (int i = 0; i < m; i++)
    {
        int c = code(s[i]);
        if (t[v].edges[c] == -1)
        {
            t[v].edges[c] = N;
            init(N);
        }
        v = t[v].edges[c];
    }
    t[v].is_word = true;
    t[v].counter++;
}
//how many string 's' was added
int get_count(string s)
{
    int v = 0;
    int m = s.size();
    for (int i = 0; i < m; i++)
    {
        int c = code(s[i]);
        v = t[v].edges[c];

        if (v == -1) return 0;
    }
    return t[v].counter;
}


///SEGMENT TREE WITH LAZY AND RELAX O(nlogn)
//lightoj computing fast average
//flag = is any lazy there?
//lazy = lazy value
//tree = segment tree node

void relax( int cn, int a, int b )
{
    tree[cn] = lazy[cn]*(b-a+1);
    if( a != b )
    {
        int l = cn<<1;
        int r = l+1;
        lazy[l] = lazy[r] = lazy[cn];
        flag[l] = flag[r] = 1;
    }
    flag[cn] = 0;
    return;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    if( flag[cn] )
        relax( cn, s, e );
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] = v;
        relax( cn, s, e );
        return;
    }
    int m = (s+e)>>1, l = cn<<1;
    int r = l+1;
    update( l, s, m, x, y, v );
    update( r, m+1, e, x, y, v );
    tree[cn] = tree[l] + tree[r];
    return;
}

intl query( int cn, int s, int e, int x, int y )
{
    if( flag[cn] )
        relax( cn, s, e );
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y ) return tree[cn];
    int m = (s+e)>>1;
    intl l1 = query( cn<<1, s, m, x, y );
    intl l2 = query( (cn<<1) + 1, m+1, e, x, y );
    return l1+l2;
}
