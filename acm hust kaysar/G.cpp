#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, pii>
#define ldb        long double

int n, x1, y1, x2, y2;
pii tree[4*20005];
int lazy[4*20005], flag[4*20005];

bool comp( piii a, piii b )
{
    return a.yy.xx < b.yy.xx;
}

void relax( int cn, int l, int r )
{
    if( l == r )
    {
        tree[cn].xx += lazy[cn];
        tree[cn].yy = 1;
        lazy[cn] = flag[cn] = 0;
        return;
    }
    int lf=cn*2,rf = cn*2+1;
    lazy[lf] += lazy[cn];
    lazy[rf] += lazy[cn];
    flag[lf] = flag[rf] = 1;
    tree[lf].xx += lazy[cn];
    tree[rf].xx += lazy[cn];
    lazy[cn] = flag[cn] = 0;
    /*if( tree[lf].xx == tree[rf].xx )
        tree[cn].yy = tree[lf].yy + tree[rf].yy;
    else if( tree[lf].xx < tree[rf].xx )
        tree[cn].yy = tree[lf].yy;
    else
        tree[cn].yy = tree[rf].yy;*/
}

void init( int cn, int l, int r )
{
    if(l==r)
    {
        tree[cn].xx = 0;
        tree[cn].yy = 1;
        flag[cn] = lazy[cn] = 0;
        return;
    }
    int lf = cn*2, rf = cn*2+1;
    init( lf, l, (r+l)/2 );
    init( rf, (l+r)/2+1, r );
    tree[cn].xx = min( tree[lf].xx, tree[rf].xx );
    if( tree[lf].xx == tree[rf].xx )
        tree[cn].yy = tree[lf].yy + tree[rf].yy;
    else if( tree[lf].xx < tree[rf].xx )
        tree[cn].yy = tree[lf].yy;
    else
        tree[cn].yy = tree[rf].yy;
}

void update( int cn, int l, int r, int s, int e, int val )
{
    if( flag[cn] == 1 ) relax(cn, l, r);
    if( l > e || r < s ) return;
    if( l >= s && r <= e )
    {
        lazy[cn] += val;
        relax(cn, l, r);
        if( l == r )
            return;
        int lf = cn*2, rf = cn*2+1;
        tree[cn].xx = min( tree[lf].xx, tree[rf].xx );
        if( tree[lf].xx == tree[rf].xx )
            tree[cn].yy = tree[lf].yy + tree[rf].yy;
        else if( tree[lf].xx < tree[rf].xx )
            tree[cn].yy = tree[lf].yy;
        else
            tree[cn].yy = tree[rf].yy;
        return;
    }
    int mid = (l+r)/2, lf = cn*2, rf = cn*2+1;
    update( lf, l, mid, s, e, val );
    update( rf, mid+1, r, s, e, val );
    tree[cn].xx = min( tree[lf].xx, tree[rf].xx );
    if( tree[lf].xx == tree[rf].xx )
        tree[cn].yy = tree[lf].yy + tree[rf].yy;
    else if( tree[lf].xx < tree[rf].xx )
        tree[cn].yy = tree[lf].yy;
    else
        tree[cn].yy = tree[rf].yy;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    vector<piii>vec;
    vector<pii>left;
    vector<pii>right;
    vector<bool>avl(10005,1);
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> x1 >> y1 >> x2 >> y2;
        //x1 += 10000; y1 += 10000; x2 += 10000; y2 += 10000;
        vec.pb( mp( mp(y1, y2), mp(x1, 1) ) );
        vec.pb( mp( mp(y1, y2), mp(x2, -1) ) );
    }
    sort( vec.begin(), vec.end(), comp );
    int ans = 0;
    init( 1,1, 20001 );
    for( int i = 0; i < 2*n; i++ )
    {
        printf("%d %d %d %d\n", vec[i].xx.xx+1,vec[i].xx.yy,vec[i].yy.xx,vec[i].yy.yy);
        int val;
        if( tree[1].xx == 0 )
            val = tree[1].yy;
        else
            val = 0;
        what_is(val);
        int y = 20001-val;
        if( i > 0 )
        ans += 2*abs( vec[i].yy.xx - vec[i-1].yy.xx )+2*y;
        what_is(ans);
        update(1,1,20001, vec[i].xx.xx+1, vec[i].xx.yy, vec[i].yy.yy );
    }

    cout << ans << endl;

    return 0;
}




