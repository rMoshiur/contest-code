#include<bits/stdc++.h>
#define rep(i,s,t) for (ll i=(s); i<=(t); ++i)
#define dep(i,t,s) for (ll i=(t); i>=(s); --i)
#define i first
#define j second
#define pb push_back
#define pp pop_back
#define pf pop_front
#define sz(x) ll((x).size())
#define p(i) (1LL<<((i)-1))
#define w(x,i) ((x)&p(i))

using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }
template<class T> inline T sqr(T x) { return x*x; }

template<class T>
inline void get(T &n) {
	char c = getchar();
	while (c!='-' && (c<'0' || c>'9')) c = getchar();
	n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
	while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
	n *= s;
}

const ll maxn = 110;
ll n;

struct vec {
    ll x,y,i;
    vec(ll x=0,ll y=0,ll i=0):x(x),y(y),i(i) {}
    bool operator < (const vec& b) const {
        return std::make_pair(x,y) < std::make_pair(b.x,b.y);
    }
    bool operator == (const vec& b) const { return x==b.x && y==b.y; }
    vec operator + (vec b) { return vec(x+b.x,y+b.y); }
    vec operator - (vec b) { return vec(x-b.x,y-b.y); }
    ll operator * (vec b) { return x*b.y - y*b.x; }
    ll mod() { return x*x+y*y; }
    double ang() { return atan2(y,x); }
};

std::vector<vec> cvx,a;
bool vis[maxn];
void convex(std::vector<vec>& a) {
    if (sz(a)==1) { cvx = a; return; }
    sort(a.begin(),a.end());
    memset(vis,0,sizeof(vis));
    cvx.clear();
    for (ll i=0; i<sz(a); ++i) {
        while (sz(cvx)>=2 && (cvx.back()-cvx[sz(cvx)-2]) * (a[i]-cvx.back())<=0 )
            cvx.pop_back();
        cvx.push_back(a[i]);
    }
    for (vec &x:cvx) vis[x.i] = true; vis[cvx[0].i] = false;
    for (ll i=sz(a)-2; i>=0; --i) if (!vis[a[i].i]) {
        while (sz(cvx)>=2 && (cvx.back()-cvx[sz(cvx)-2]) * (a[i]-cvx.back())<=0 )
            cvx.pop_back();
        cvx.push_back(a[i]);
    }
    cvx.pop_back();
}

int main() {
    ll i,j,k,t,tt,Test;
    get(Test);
    rep(Ti,1,Test) {
        get(n);
        a.clear();
        rep(k,1,n) {
            get(i); get(j);
            a.pb(vec(i,j,k));
        }
        convex(a);
        //for (auto x:cvx) printf("(%lld,%lld) ",x.x,x.y); puts("");
        if (cvx.size()!=n) { puts("NO"); continue; }
        cvx.pb(cvx.front());
        ll edge = (cvx[1]-cvx[0]).mod();
        rep(i,2,sz(cvx)-1) {
            if ((cvx[i]-cvx[i-1]).mod()!=edge) {
                edge = -1;
                break;
            }
        }
        if (edge<0) { puts("NO"); continue; }
        puts("YES");
    }

    return 0;
}

