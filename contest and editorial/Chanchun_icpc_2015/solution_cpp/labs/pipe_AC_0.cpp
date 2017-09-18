#include<bits/stdc++.h>
using namespace std;
#define FZ(i,n) for(int i=0;i<(n);i++)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))

#define RS(x) scanf("%s",x)
#define PS(x) printf("%s",x)
#define ePS(x) fprintf(stderr,"%s",x)

#define FIR first
#define SEC second
#define pritnf printf
typedef long long int lnt;
typedef double dou;
const int lgn = 16;
const int P = (1<<lgn);
////////////
const int X = 2048;
const int XX= X*2;
////////////
const lnt mod=(1005ll<<20)+1;//=(127ll<<24)+1;
const lnt phi=(1005ll<<20)+0;//=(127ll<<24)+0;
const lnt proot=7ll;//5ll;
lnt nrp[P],irp[P],g[P];
void FFT(lnt*f,lnt*rp,int n){
    if(n==1)return;
    int nn=n/2,gt=0;
	for(int i=0;i<n;i+=2)g[gt++]=f[i];
	for(int i=1;i<n;i+=2)g[gt++]=f[i];
	FZ(i,n)f[i]=g[i];
	FFT(f+00,rp,nn);
	FFT(f+nn,rp,nn);
	int step=P/n;
	for(int i=0;i<nn;i++){
		lnt u=f[i]>=mod?f[i]-mod:f[i];
		lnt v=f[i+nn]*rp[i*step]%mod;
		f[i+00]=u+v;
		f[i+nn]=u-v+mod;
	}
}
lnt ppp(lnt a,lnt x){
	lnt ans=1;
	for(;x;x/=2){
		if(x&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
	}
	return ans;
}
void ini(){
	lnt nproot=ppp(proot,phi/P);
	nrp[0]=1;
	for(int i=1;i<P;i++)
		nrp[i]=1ll*nrp[i-1]*nproot%mod;
	lnt iproot=ppp(nproot,phi-1);
	irp[0]=1;
	for(int i=1;i<P;i++)
		irp[i]=1ll*irp[i-1]*iproot%mod;
}
//////////////////////////////////////////////
int gethash(int*lj,int mx){
	const lnt amod=1000000007;
	lnt sum=0,tmp=233ll;
	for(int i=1;i<mx;i++){
		sum=(sum+tmp*lj[i])%amod;
		tmp=tmp*233ll%amod;
	}
	return (int)sum;
}
////////////
#define S 65536
#define Ss (S-1)
int C[S*2],D[S*2];
lnt E[S*4],F[S*4],G[S*4];
int ans1[S];
int lj[S],rj[S];
#define N S
int n;
int a[N],s[N];
void sol(int uuu){
	int mx=s[n-1]+1;
	int pn=X;for(;pn<mx;pn*=2);
	int nn=pn/X;
	FZ(i,pn*2)E[i]=F[i]=0;
	E[0]=F[pn-1]=1;
	FZ(i,n){
		E[s[i]]++;
		F[pn-1-s[i]]++;
	}
	/////////////
	FFT(E,nrp,pn*2);
	FFT(F,nrp,pn*2);
	{
		lnt moni=ppp(pn*2,phi-1);
		FZ(i,pn*2)G[i]=E[i]*F[i]%mod*moni%mod;
	}
	FFT(G,irp,pn*2);
	FZ(i,pn*2)if(G[i]>=mod)G[i]-=mod;
	FZ(i,pn)ans1[pn-1-i]=(G[i]+1)/2;
	//////////////////////
	FZ(i,mx)lj[i]=rj[i]=0;
	FZ(i,pn*2)C[i]=D[i]=0;
	for(int i=n-1;i>=0;i--)C[s[i]]=i+2;
	C[0]=1;
	D[0]=1;
	FZ(i,n)D[s[i]]++;
	//////////////////////
	FZ(i,nn){
		int st=(i+0)*X;
		int ed=(i+1)*X;
		FZ(j,pn)E[j]=F[j]=0;
		for(int j=st;j<ed;j++){
			E[X-1-(j-st)]=D[j];
		}
		for(int j=ed;j<pn;j++){
			F[j-ed]=D[j];
		}
		FFT(E,nrp,pn);
		FFT(F,nrp,pn);
		lnt moni=ppp(pn,phi-1);
		FZ(j,pn)G[j]=E[j]*F[j]%mod*moni%mod;
		FFT(G,irp,pn);
		FZ(j,pn)if(G[j]>=mod)G[j]-=mod;
		for(int j=st;j<ed;j++){
			if(D[j]){
				for(int k=j+1;k<ed;k++){
					G[k-j-1]+=1ll*D[j]*D[k];
				}
			}
		}
		FZ(j,mx)if(j){
			if(ans1[j]==0)continue;
			else if(ans1[j]>G[j-1]){
				ans1[j]-=G[j-1];
			}
			else{
				for(int k=st;k<ed;k++){
					lnt tmp=1ll*D[k]*D[k+j];
					if(ans1[j]>tmp){
						ans1[j]-=tmp;
					}
					else{
						lj[j]=C[k+0]-0+(ans1[j]-1)/D[k+j];
						rj[j]=C[k+j]-1+(ans1[j]-1)%D[k+j];
						ans1[j]=0;
						break;
					}
				}
			}
		}
	}
	////////////
	int ha=gethash(lj,mx);
	int hb=gethash(rj,mx);
	printf("%d %d\n",ha,hb);
}
////////////////////////////////////////////////////////////////////////////////
void input(){
	RI(n);
	assert(1<=n&&n<=30000);
	FZ(i,n){
		RI(a[i]);
		assert(0<=a[i]&&a[i]<=30000);
		s[i]=(i?s[i-1]:0)+a[i];
	}
	assert(1<=s[n-1]&&s[n-1]<=30000);
}
#define MAXT 100000
#include<time.h>
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data4.out","w",stdout);
	ini();
	int allt=0;
	int t;
	assert(RI(t)!=EOF);
	assert(1<=t&&t<=MAXT);
	for(int ti=1;ti<=t;ti++){
		int ssst=clock();
		input();
		sol(ti);
		fprintf(stderr,"end %d with %d\n",ti,(int)(clock()-ssst));
		allt+=(int)(clock()-ssst);
	}
	fprintf(stderr,"allt=%d\n",allt);
	return 0;
}

