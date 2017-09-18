// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 110
struct P {
    int x,y;
    void read() { scanf("%d%d",&x,&y); }
    int len2() { return x*x+y*y; }
} p[N];

bool operator <( P a, P b ) { return tie(a.x,a.y)<tie(b.x,b.x); }
bool operator ==( P a, P b ) { return a.x==b.x && a.y==b.y; }
P operator +( P a, P b ) { return P{a.x+b.x,a.y+b.y}; }
P operator -( P a, P b ) { return P{a.x-b.x,a.y-b.y}; }
int dis2( P a, P b ) { return (a-b).len2(); }
int dot( P a, P b ) { return a.x*b.x+a.y*b.y; }

int n;
void input() {
    RI(n);
    assert(3<=n && n<=100);
    REP(i,n) p[i].read();
    REP(i,n) {
        assert(abs(p[i].x)<=10000);
        assert(abs(p[i].y)<=10000);
    }
}

bool check() {
    REP(i,4) p[i+4]=p[i];
    int d2=dis2(p[0],p[1]);
    REP(i,4) if ( dis2(p[i],p[i+1])!=d2 ) return 0;
    REP(i,4) if ( dot(p[i+1]-p[i],p[i+2]-p[i+1])!=0 ) return 0;
    return 1;
}

bool _solve() {
    if ( n!=4 ) return 0;
    sort(p,p+4);
    REP(i,3) if ( p[i]==p[i+1] ) return 0;
    do {
        if ( check() ) return 1;
    } while ( next_permutation(p,p+4) );
    return 0;
}

void solve() {
    puts(_solve() ? "YES" : "NO");
}

int main() {
    int t;
    RI(t);
    assert(1<=t && t<=300);
    while ( t-- ) {
        input();
        solve();
    }
    return 0;
}
