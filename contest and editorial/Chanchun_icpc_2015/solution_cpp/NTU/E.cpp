#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))

#define FZ(i,n) for(int i=0;i<(n);i++)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define FIR first
#define SEC second
#define pritnf printf
#define N 10514
typedef long long int lnt;
typedef double dou;
const dou pi=acos(-1);
int n;
typedef struct{lnt x,y;}dot;
dot operator-(dot a,dot b){return(dot){a.x-b.x,a.y-b.y};}
lnt operator%(dot a,dot b){return a.x*b.x+a.y*b.y;}
dot d[N];
///////////////////
lnt sa0,sa1,sa2;
lnt xl,xr;
void add(lnt a1,lnt a0,lnt bound){
	assert(a1==1||a1==-1);
	sa2+=a1*a1;
	sa1+=2ll*a1*a0;
	sa0+=a0*a0;
	if(a1==1){
		//0<=x+a0<=bound
		xl=max(xl,-a0);
		xr=min(xr,bound-a0);
	}
	else{
		//0<=-x+a0<=bound
		xl=max(xl,a0-bound);
		xr=min(xr,a0);
	}
}
///////////////////
lnt sr[N],r[N];
dou dr[N];
int sol_odd(){
	lnt t=sr[n-1];
	for(int i=0;i*2+1<n;i++){
		t+=sr[i*2+1]-sr[i*2+0];
	}
	r[n-1]=t;
	if(r[n-1]<0)return 0;
	for(int i=n-2;i>=0;i--){
		r[i]=sr[i]*2-r[i+1];
		if(r[i]<0)return 0;
	}
	for(int i=0;i<n;i++)dr[i]=0.5*r[i];
	return 1;
}
int sol_even(){
	lnt t=0;
	for(int i=0;i*2<n;i++){
		t+=sr[i*2+1]-sr[i*2+0];
	}
	if(t)return 0;
	sa0=sa1=sa2=0;
	xl=-(1ll<<30);
	xr=+(1ll<<30);
	lnt a1=1,a0=0;
	for(int i=0;i<n;i++){
		add(a1,a0,min(sr[(i+n-1)%n],sr[i]));//(a1x+a0)^2
		a1=-a1;
		a0=sr[i]-a0;	
	}
	//2sa2x+sa1=0
	//x=-sa1/sa2/2
	//xl<=x<=xr
	lnt fu=-sa1,fd=sa2*2;
	lnt ggg=abs(__gcd(fu,fd));
	fu/=ggg,fd/=ggg;
	assert(fd>0);
	//fprintf(stderr,"%I64d %I64d %I64d/%I64d\n",xl,xr,fu,fd);
	if(xl>xr)return 0;
	if(xl*fd<=fu&&fu<=xr*fd){
		//assert( 1000%fd!=0 || fu*(1000/fd)%10!=5 );
		dr[0]=(dou(fu))/fd;
	}
	else if(abs(xl*fd-fu)<abs(xr*fd-fu)){
		dr[0]=xl;
	}
	else{
		dr[0]=xr;
	}
	for(int i=1;i<n;i++){
		dr[i]=sr[i-1]-dr[i-1];
	}
	return 1;
}
unordered_map<int,int>sqrtmp;
void sol(int uuu){
	assert(RI(n)!=EOF);
	assert(3<=n&&n<=10000);
	for(int i=0;i<n;i++){
		int x,y;
		assert(RII(x,y)!=EOF);
		assert(abs(x)<=10000);
		assert(abs(y)<=10000);
		d[i]=(dot){(lnt)x,(lnt)y};
	}
	d[n]=d[0];
	for(int i=0;i<n;i++){
		dot dd=d[i+1]-d[i];
		sr[i]=sqrtmp[dd%dd];
		assert(sr[i]);
	}
	int res=(n&1)?sol_odd():sol_even();
	if(res==0){
		puts("IMPOSSIBLE");
		return;
	}
	dou ans=0;
	for(int i=0;i<n;i++){
		ans+=dr[i]*dr[i];
	}
	printf("%.2f\n",ans*pi);
	dr[n]=dr[0];
	for(int i=0;i<n;i++){
		printf("%.2f\n",dr[i]);
		assert(dr[i]>=0);
		assert(fabs(dr[i]+dr[i+1]-sr[i])<1e-12);
	}
}
int main(){
	//freopen("data.in"  ,"r",stdin );
	//freopen("myout.txt","w",stdout);
	int t;
	assert(RI(t)!=EOF);
	assert(1<=t&&t<=100);
	int allt=clock();
	for(int i=0;i<20001;i++)sqrtmp[i*i]=i;
	for(;t;t--){
		int ttt=clock();
		sol(t);
		//fprintf(stderr,"time: %d\n",(int)clock()-ttt);
	}
	fprintf(stderr,"total time=%d\n",(int)clock()-allt);
	assert(scanf("%*s")==EOF);
	return 0;
}
