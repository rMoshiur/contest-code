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

const ll maxn = 65536+10,maxs = 178,mo = ll(1e9)+7;
ll n,m,tot,S,g[maxn],s[maxn],ans,N;
int cnt[maxs][maxn],amt[maxn],sum[maxn];
vector<ll> v[maxn];

typedef complex<double> comp;
const double PI = 2*acos(0);
const comp I(0,1);
const ll maxp = (1<<16)+10;
comp tmp[maxp],a[maxp],b[maxp],c[maxp];

//exist p that n == 2^p
void DFT(comp* a,ll n,ll rev) {
	ll i; comp omega,x;
	if (n==1) return;
	memmove(tmp,a,sizeof(comp)*n);
	for (i=0; i<n; i++)
		if (!(i&1)) a[i/2] = tmp[i]; else a[n/2+i/2] = tmp[i];
	DFT(a,n/2,rev); DFT(a+n/2,n/2,rev);
	x = 1;
	omega = exp(rev * 2*PI/n * I);
	for (i=0; i<n/2; i++) {
		tmp[i] = a[i] + x*a[n/2+i];
		tmp[i+n/2] = a[i] - x*a[n/2+i];
		x *= omega;
	}
	memmove(a,tmp,sizeof(comp)*n);
}

int main() {
    ll i,j,k,t,tt,Test;
    get(Test);
    rep(Ti,1,Test) {
        get(n);
        if (n==0) { puts("0 0"); continue; }
        rep(i,1,n) {
            get(s[i]);
            s[i] += s[i-1];
        }
        tot = s[n];
        rep(k,0,tot) v[k].clear();
        rep(i,0,n) v[s[i]].pb(i);
        rep(k,0,tot) sort(v[k].begin(),v[k].end());

        S = max((ll)sqrt(n),n/10); m = n/S+1;
        for (N=1; tot*2>=N; N<<=1);

        rep(k,0,tot) sum[k] = 0;
        rep(i,0,n) ++sum[s[i]];

        rep(k,0,tot) b[tot-k] = comp(sum[k],0);
        rep(k,tot+1,N) b[k] = comp(0,0);
        DFT(b,N,1);

        rep(k,0,N) amt[k] = 0;
        rep(si,1,m) {
            ll l = si*S-S,r = min(si*S-1,n);
            rep(i,l,r) ++amt[s[i]],--sum[s[i]];

            rep(k,0,N) a[k] = comp(amt[k],0);
            DFT(a,N,1);

            rep(k,0,N) c[k] = a[k]*b[k];
            DFT(c,N,-1);
            rep(k,0,N) c[k] /= N;

            rep(k,0,tot) {
                cnt[si][k] = int(c[tot-k].real() + 0.5);
            }
        }

        ll al = 0,ar = 0,pr = 1,l,r,mid,L,R;
        rep(k,1,tot) {
            pr = pr*233%mo;
            tt = cnt[m][k];
            tt = (tt+1)/2;
            if (!tt) continue;
            rep(ki,1,m) {
                if (cnt[ki][k]>=tt) {
                    tt -= cnt[ki-1][k];
                    l = ki*S-S; r = min(ki*S-1,n);
                    rep(i,l,r) if (s[i]+k<=tot) {
                        if (sz(v[s[i]+k])>=tt) {
                            L = i+1; R = v[s[i]+k][tt-1];
                            break;
                        }
                        else tt -= sz(v[s[i]+k]);
                    }
                    break;
                }
            }
            al = (al+pr*L)%mo;
            ar = (ar+pr*R)%mo;
        }
        printf("%d %d\n",(int)al,(int)ar);
    }

    return 0;
}
