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

const ll maxn = 100010;
ll n,a[maxn],pf[maxn],sf[maxn];

bool check() {
    rep(i,1,n) sf[i] = pf[i] = 0;
    pf[0] = sf[n+1] = 1;
    rep(i,1,n) {
        if (a[i-1]>a[i]) break;
        pf[i] = 1;
    }
    dep(i,n,1) {
        if (a[i]>a[i+1]) break;
        sf[i] = 1;
    }
    rep(k,1,n) {
        ll i = k-1,j = k+1;
        if (a[i]<=a[j] && pf[i] && sf[j]) return true;
    }
    return false;
}

int main() {
    ll i,j,k,t,tt,test;
    get(test);
    rep(Ti,1,test) {
        get(n);
        rep(i,1,n) get(a[i]);
        a[0] = 0; a[n+1] = ll(1e6);
        if (check() || (reverse(a+1,a+n+1),check()))
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
