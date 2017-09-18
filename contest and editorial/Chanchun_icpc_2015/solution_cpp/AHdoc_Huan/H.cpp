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

const ll maxn = 5010;
ll n,a[maxn],f[maxn];

int main() {
    ll i,j,k,t,tt,Test;
    get(Test);
    while (Test--) {
        get(n);
        rep(i,1,n-1) get(a[i]);
        rep(i,2,n-1) a[i] -= a[1];
        f[0] = 0;
        rep(i,1,n-2) {
            f[i] = 1<<31;
            rep(j,0,i-1) {
                f[i] = max(f[i],f[j]+a[i-j+1]);
            }
        }
        printf("%lld\n",f[n-2]+a[1]*n);
    }

    return 0;
}
