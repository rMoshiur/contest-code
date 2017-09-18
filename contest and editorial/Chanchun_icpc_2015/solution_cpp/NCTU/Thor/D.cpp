#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Q=998244353; //2^23*119+1
const int P=1000000007;
const int G=3;
const int MAXPOW=23;
const int M=1<<16;
int N;
const int X=512;
int rt[MAXPOW+1],invrt[MAXPOW+1],ta[M],tb[M];
inline int inv(int x){
	int y=Q-2,r=1;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
void build_root(){
	int rem=(Q-1)>>MAXPOW;
	rt[MAXPOW]=1;
	for(int i=0;i<rem;i++){
		rt[MAXPOW]=1LL*rt[MAXPOW]*G%Q;
	}
	for(int i=MAXPOW-1;i>=0;i--){
		rt[i]=1LL*rt[i+1]*rt[i+1]%Q;
	}
	for(int i=0;i<=MAXPOW;i++) invrt[i]=inv(rt[i]);
}
void FFT(int x[], bool pos){
    // reverse bit and replace
    for (int i=1, j=0; i<N; ++i){
        for (int k=N>>1; !((j^=k)&k); k>>=1) ;
        if (i>j) swap(x[i], x[j]);
    }
    for (int k=2; k<=N; k<<=1){
        int om = pos?rt[__lg(k)]:invrt[__lg(k)];
        // 每k個做一次FFT
        for (int j=0; j<N; j+=k){
            int mul = 1;
            for (int i=j; i<j+k/2; i++){
                int a = x[i], b = 1LL*x[i+k/2]*mul%Q;
                x[i]     = (a + b)%Q;
                x[i+k/2] = (a + Q - b)%Q;
                mul = 1LL*mul*om%Q;
            }
        }
    }
}
void poly_mul(int a[],int b[],int c[]){
	memcpy(ta,a,sizeof(ta));
	memcpy(tb,b,sizeof(tb));
	FFT(a,true);
	FFT(b,true);
	for(int i=0;i<N;i++){
		c[i]=1LL*a[i]*b[i]%Q;
	}
	memcpy(a,ta,sizeof(ta));
	memcpy(b,tb,sizeof(tb));
	int mul=inv(N);
	FFT(c,false);
	for(int i=0;i<N;i++){
		c[i]=1LL*c[i]*mul%Q;
	}
}
int p1[M/X][M],p3[M/X][M],p2[M],s[M],cnt[M/X];
int main(){
	build_root();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,l=0,r=0,mul=1;
		scanf("%d",&n);
		s[0]=0;
		memset(p1,0,sizeof(p1));
		memset(p2,0,sizeof(p2));
		for(int i=1;i<=n;i++) scanf("%d",&s[i]),s[i]+=s[i-1];
		for(int i=0;i<=n;i++){
			for(int j=i/X;j<=n/X;j++){
				p1[j][s[i]]++;
			}
			p2[s[n]-s[i]]++;
		}
		N=1;
		while(N<s[n]*2+1)N<<=1;
		FFT(p2,true);
		int tmp=inv(N);
		for(int j=0;j<=n/X;j++){
			FFT(p1[j],true);
			for(int i=0;i<N;i++){
				p3[j][i]=1LL*p1[j][i]*p2[i]%Q*tmp%Q;
			}
			FFT(p3[j],false);
		}
		for(int i=1;i<=s[n];i++){
			mul=233LL*mul%P;
			for(int j=0;j<=n/X;j++){
				cnt[j]=p3[j][s[n]-i];
			}
			int k=(cnt[n/X]+1)/2-1;
			if(k<0){
				continue;
			}
			int seg=upper_bound(cnt,cnt+n/X+1,k)-cnt;
			if(seg) k-=cnt[seg-1];
			for(int j=seg*X;j<(seg+1)*X&&j<=n;j++){
				int num=upper_bound(s,s+n+1,s[j]+i)-lower_bound(s,s+n+1,s[j]+i);
				if(k<num){
					int fst=lower_bound(s,s+n+1,s[j]+i)-s;
					l=(l+1LL*(j+1)*mul)%P;
					r=(r+1LL*(fst+k)*mul)%P;
					break;
				}
				k-=num;
			}
		}
		printf("%d %d\n",l,r);
	}
	return 0;
}
