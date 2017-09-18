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
int n,m,q,l;
char s[N],ts[N];
vector<int>e[N];
void adde(int p,int end){
	if(ed[p]==0)p=efl[p];
	for(;p;p=efl[p]){
		e[ll[p]].push_back(end-ll[p]+1);
	}
}
typedef struct{int l,r,id;}ele;
vector<ele>qq[N];
unt dp[2][N];
unt *dpa=dp[0],*dpb=dp[1];
int ans[N];
int cnt5000=0,toln=0;
void sol(int uuu){
	assert(RI(n)!=EOF);
	toln+=n;
	RII(m,q);
	assert(1<=n&&n<=40000);
	assert(1<=m&&m<=10000);
	assert(1<=q&&q<=40000);
	if(n>5000)cnt5000++;
	assert(scanf("%s",s)!=EOF);
	assert(n==(int)strlen(s));
	//////////////
	spt=1;
	int root=trinewnode();
	int toll=0;
	for(int i=0;i<m;i++){
		assert(scanf("%s",ts)!=EOF);
		int l=0;for(;ts[l];l++);
		toll+=l;
		add(ts,root);
	}
	assert(1<=toll&&toll<=10000);
	make_fl(root);
	//////////////
	int p=root;
	for(int i=0;i<n;i++){
		int a=s[i]-'a';
		p=nx[p][a];
		adde(p,i);
	}
	//////////////
	for(int i=0;i<q;i++){
		int l,r;
		assert(RII(l,r)!=EOF);
		qq[r-l+1].push_back((ele){l-1,r-1,i});
		assert(1<=l&&l<=r&&r<=n);
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
}
int main(){
	int t;
	assert(RI(t)!=EOF);
	assert(1<=t&&t<=21);
	int allt=clock();
	for(;t;t--){
		int ttt=clock();
		sol(0);
		//fprintf(stderr,"Case %03d spent %d\n",t,(int)clock()-ttt);
	}
	//fprintf(stderr,"All spent %d\n",(int)clock()-allt);
	assert(cnt5000<=6);
	assert(scanf("%*s")==EOF);
	return 0;
}

