#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<assert.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))

#define FZ(i,n) for(int i=0;i<(n);i++)
#define PA(a,n) FZ(_1,n)printf("%d%c",(a)[_1],_1==(n)-1?10:32)
#define ePA(a,n) FZ(_2,n)fprintf(stderr,"%d%c",(a)[_2],_2==(n)-1?10:32)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define FIR first
#define SEC second
#define pritnf printf
#define N 40514
typedef long long int lnt;
typedef unsigned long long int unt;
typedef double dou;
typedef pair<int,int> P;
///////////////////////////////////////////////////
void make_z(int*z,char*s,int l){
	int j=z[0]=0;
	for(int i=1;i<l;i++){
		z[i]=(i>j+z[j]-1)?0:min(z[i-j],j+z[j]-i);
		for(;i+z[i]<l&&s[z[i]]==s[i+z[i]];z[i]++);
		if(i+z[i]>j+z[j])j=i;
	}
}
///////////////////////////////////////////////////
int n,m,q,l;
char s[N];
char ts[N*2];
vector<int>e[N];
int z[N*2];
///////////////////////////////////////////////////
typedef struct{int l,r,id;}ele;
vector<ele>qq[N];
unt dp[2][N];
unt *dpa=dp[0],*dpb=dp[1];
int ans[N];
int sol(int uuu){
	if(RI(n)==EOF)return 0;
	RII(m,q);
	assert(1<=n&&n<=40000);
	assert(1<=m&&m<=10000);
	assert(1<=q&&q<=40000);
	scanf("%s",s);
	assert(n==(int)strlen(s));
	////////
	int toll=0;
	for(int i=0;i<m;i++){
		scanf("%s",ts);
		int l=0;for(;ts[l];l++);
		toll+=l;
		for(int j=l;j<=l+n;j++){
			ts[j]=s[j-l];
		}
		make_z(z,ts,l+n);
		for(int j=l;j<l+n;j++){
			if(z[j]>=l){
				e[l].push_back(j-l);
			}
		}
	}
	assert(1<=toll&&toll<=10000);
	//////////////
	for(int i=0;i<q;i++){
		int l,r;
		RII(l,r);
		qq[r-l+1].push_back((ele){l-1,r-1,i});
	}
	//////////////
	int nn=n/64+(n%64!=0);
	for(int j=0;j<=nn;j++){
		dpa[j]=0;
	}
	for(int i=1;i<=n;i++){
		nn=(n-i+1)/64+((n-i+1)%64!=0);
		for(int j=0;j<nn+1;j++){
			dpa[j]=~dpa[j];
		}
		for(int j=0;j<nn;j++){
			dpb[j]=( ( dpa[j] | (dpa[j]>>1) | ((dpa[j+1]&1)<<63) ) );
		}
		for(int j=0;j<SZ(e[i]);j++){
			dpb[e[i][j]>>6]&=( ~(unt)(0) ) - ( ((unt)1)<<(e[i][j]&63) );
		}
		swap(dpa,dpb);
		for(int j=0;j<SZ(qq[i]);j++){
			int x=qq[i][j].l;
			ans[qq[i][j].id]=(dpa[x>>6]>>(x&63))%2;
		}
		e[i].clear();
		qq[i].clear();
	}
	for(int i=0;i<q;i++)printf("%d\n",ans[i]);
	return 1;
}
#include<time.h>
int main(){
	int t;
	scanf("%d",&t);
	int allt=clock();
	for(;t;t--){
		int ttt=clock();
		sol(0);
	}
	assert(scanf("%*s")==EOF);
	return 0;
}

