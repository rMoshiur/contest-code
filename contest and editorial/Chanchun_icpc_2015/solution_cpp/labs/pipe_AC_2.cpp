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
const int lgn = 10;
const int P = (1<<lgn);
////////////
const int X = P/2;
const int XX= P;
////////////
const lnt mod=(1005ll<<20)+1;//=(127ll<<24)+1;//
const lnt phi=(1005ll<<20)+0;//=(127ll<<24)+0;//
const lnt proot=7ll;//=5ll;//
lnt nrp[P],irp[P],g[P];
int lg2[P],rv[P];
void FFT(lnt*f,lnt*rp,int n){
	int l=0;
	for(;(1<<(l+1))<=n;l++);
	for(int i=0;i<n;i++){
		g[rv[i]>>(lgn-l)]=f[i];
	}
	memcpy(f,g,sizeof(lnt)<<l);
	for(int s=2;s<=n;s*=2){
		int nn=s>>1;
		int step=P/s;
		for(int h=0;h<n;h+=s){
			lnt*trp=rp;
			for(int i=0;i<nn;i++,trp+=step){
				lnt u=f[h+i+00]>=mod?f[h+i+00]-mod:f[h+i+00];
				lnt v=f[h+i+nn]*(*trp)%mod;
				f[h+i+00]=u+v;
				f[h+i+nn]=u-v+mod;;
			}
		}
	}
	FZ(i,n)if(f[i]>=mod)f[i]-=mod;
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
	lnt nproot=ppp(proot,phi>>lgn);
	for(int i=nrp[0]=1;i<(1<<lgn);i++)
		nrp[i]=1ll*nrp[i-1]*nproot%mod;
	lnt iproot=ppp(nproot,phi-1);
	for(int i=irp[0]=1;i<(1<<lgn);i++)
		irp[i]=1ll*irp[i-1]*iproot%mod;
	for(int i=0;i<lgn;i++)lg2[1<<i]=i;
	rv[0]=0;
	for(int i=1;i<(1<<lgn);i++)
		rv[i]=rv[i-(i&-i)]|(1<<(lgn-1-lg2[i&-i]));
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
#define N (1<<16)
#define Ns (N-1)
int C[N*2],D[N*2];
lnt E[N*2],F[N*2],G[N*2];
//////////////////////
int n;
int a[N],ssp[N*2];
int*s=ssp+1;
////////////
int ans1[N],lj[N],rj[N];
vector<int>box[2][N];
void sol(int uuu){
	int mx=s[n-1]+1;
	int pn=X;for(;pn<mx;pn*=2);
	int nn=pn/X;
	FZ(i,pn*2)C[i]=D[i]=0;
	D[0]=1;
	FZ(i,n)D[s[i]]++;
	for(int i=n-1;i>=0;i--)C[s[i]]=i+2;
	C[0]=1;
	//////////////////////
	FZ(i,nn){
		int st=(i+0)*X;
		FZ(j,X)E[i*XX+0+j]=F[i*XX+X-1-j]=D[st+j];
		FZ(j,X)E[i*XX+X+j]=F[i*XX+X+j]=0;
		FFT(E+i*XX,nrp,XX);
		FFT(F+i*XX,nrp,XX);
	}
	///////////////////////
	lnt moni=ppp(XX,phi-1);
	FZ(i,pn)ans1[i]=0;
	FZ(j,X){
		box[0][j].resize(nn,0);
		box[1][j].resize(nn,0);
		FZ(i,nn){
			int st=(i+0)*X;
			int ed=(i+1)*X;
			int os=ans1[j];
			for(int k=st;k+j<ed;k++){
				ans1[j]+= D[k]*D[k+j];
			}
			box[0][j][i]=ans1[j]-os;
		}
	}
	for(int j=1,dis=0,cr=0,nx=1;j<=nn;j++,dis+=X){
		/*[dis+1,dis+XX-1]*/
		for(int i=0;i+j<nn;i++){
			FZ(k,XX)G[k]=F[i*XX+k]*E[(i+j)*XX+k]%mod*moni%mod;
			FFT(G,irp,XX);
			for(int k=0  ;k<X-1 ;k++){
				ans1[dis+k+1]+=G[k];
				box[cr][k+1-0][i]+=G[k];
			}
			for(int k=X-1;k<XX-1;k++){
				ans1[dis+k+1]+=G[k];
				box[nx][k+1-X][i]=G[k];
			}
		}
		/*[dis,dis+X-1]*/
		for(int k=0;k<X;k++){
			int disk=dis+k;
			if(ans1[disk]==0){
				lj[disk]=rj[disk]=0;
				continue;
			}
			int bi=-1;
			int sss=(ans1[disk]+1)/2;
			{
				int i=0;
				for(; i<nn && sss>box[cr][k][i] ;i++){
					sss-=box[cr][k][i];
				}
				bi=i;
			}
			assert(bi!=nn);
			///////////
			{
				int i=(bi+0)*X;
				for(; i<(bi+1)*X && sss>(D[i]*D[i+disk]);i++){
					sss-=(D[i]*D[i+disk]);
				}
				lj[disk]=C[i     ]-0+(sss-1)/D[i+disk];
				rj[disk]=C[i+disk]-1+(sss-1)%D[i+disk];
			}
		}
		swap(cr,nx);
	}
	//FZ(i,mx)printf("%d%c",(int)ans1[i],i==mx-1?10:32);
	//FZ(i,mx)printf("%d%c",(int)lj[i],i==mx-1?10:32);
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
		s[i]=s[i-1]+a[i];
	}
	assert(1<=s[n-1]&&s[n-1]<=30000);
}
#define MAXT 100000
#include<time.h>
int main(){
	//freopen("data_ex.in","r",stdin);
	//freopen("data2.out","w",stdout);
	srand(514);
	ini();
	int allt=0;
	int t;
	if(RI(t)!=EOF){
		assert(1<=t&&t<=MAXT);
		for(int ti=1;ti<=t;ti++){
			int ssst=clock();
			input();
			sol(ti);
			fprintf(stderr,"end %d with %d\n",ti,(int)(clock()-ssst));
			allt+=(int)(clock()-ssst);
		}
	}
	fprintf(stderr,"allt=%d\n",allt);
	return 0;
}

