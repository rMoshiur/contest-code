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
#define sizz N
int  nx[sizz][26],spt;
int  fl[sizz],efl[sizz],ed[sizz],ll[sizz];
int trinewnode(){
	for(int i=0;i<26;i++)
		nx[spt][i]=0;
	ed[spt]=0;
	ll[spt]=0;
	return spt++;
}
void add(const char*s,int p){
	for(int i=0;s[i];i++){
		int a=s[i]-'a';
		if(nx[p][a]==0){
			nx[p][a]=trinewnode();
			ll[nx[p][a]]=ll[p]+1;
		}
		p=nx[p][a];
	}
	ed[p]=1;
}
int space[sizz],qs,qe;
void make_fl(int root){
	int*q=space;
	 fl[root]=0;
	efl[root]=0;
	qs=qe=0;
	q[qe++]=root;
	for(;qs!=qe;){
		int p=q[qs++];
		for(int i=0;i<26;i++){
			int t=nx[p][i];
			if(t==0)
				continue;
			int tmp=fl[p];
			for(;tmp&&nx[tmp][i]==0;tmp=fl[tmp]);
			 fl[t]=tmp?nx[tmp][i]:root;
			efl[t]=ed[fl[t]]?fl[t]:efl[fl[t]];
			q[qe++]=t;
		}
	}
	for(int i=0;i<26;i++){
		if(nx[root][i]==0)nx[root][i]=root;
	}
	for(qs=1;qs!=qe;){
		int p=q[qs++];
		for(int i=0;i<26;i++){
			if(nx[p][i]==0)nx[p][i]=nx[fl[p]][i];
		}
	}
}
int n,m,q;//,nn;
char s[N];
char ts[N];
vector<int>e[N];
void adde(int p,int end){
	if(ed[p]==0)p=efl[p];
	for(;p;p=efl[p]){
		e[ll[p]].push_back(end-ll[p]+1);
	}
}
typedef struct{int l,r,id;}ele;
vector<ele>qq[N];
int dp[2][N];
int *dpa=dp[0],*dpb=dp[1];
int ans[N];
int sol(int uuu){
	if(RI(n)==EOF)return 0;
	RII(m,q);
	assert(1<=n&&n<=40000);
	assert(1<=m&&m<=10000);
	assert(1<=q&&q<=40000);
	scanf("%s",s);
	assert(n==(int)strlen(s));
	//nn=n/64+(n%64!=0);
	////////
	spt=1;
	int root=trinewnode();
	int toll=0;
	for(int i=0;i<m;i++){
		scanf("%s",ts);
		int l=0;for(;ts[l];l++);
		toll+=l;
		add(ts,root);
	}
	assert(1<=toll&&toll<=10000);
	make_fl(root);
	////////
	int p=root;
	for(int i=0;i<n;i++){
		int a=s[i]-'a';
		p=nx[p][a];
		adde(p,i);
	}
	//////////////
	for(int i=0;i<q;i++){
		int l,r;
		RII(l,r);
		qq[r-l+1].push_back((ele){l-1,r-1,i});
	}
	//////////////
	for(int j=0;j<=n;j++){
		dpa[j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-i+1;j++){
			dpb[j]=(dpa[j]==0||dpa[j+1]==0);
		}
		for(int j=0;j<SZ(e[i]);j++){
			dpb[e[i][j]]=0;
		}
		swap(dpa,dpb);
		for(int j=0;j<SZ(qq[i]);j++){
			ans[qq[i][j].id]=dpa[qq[i][j].l];
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

