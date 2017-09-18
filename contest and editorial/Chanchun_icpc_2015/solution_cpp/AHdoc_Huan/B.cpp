#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxP (31625)
using namespace std;

int T,N,M,nn;
int prime[maxP];
int p[35],k[35];
bool vis[maxP];
unsigned long long ans;

void prepare(){
	memset(vis,true,sizeof(vis));
	M=0;
	prime[M++]=2;
	for (int i=4;i<=maxP;i+=2)
		vis[i]=false;
	for (int i=3;i<=maxP;i+=2) if (vis[i]){
		prime[M++]=i;
		if (i>maxP/i)
			continue;
		for (int j=i*i;j<=maxP;j+=2*i)
			vis[j]=false;
	}
}
void dfs(int i,int m,unsigned long long hm){
	if (i==nn){
		ans+=((unsigned long long)m*m-hm);
		return;
	}
	dfs(i+1,m,hm);
	int pm=1;
	for (int c=1;c<=k[i];c++){
		pm*=p[i];
		unsigned long long phm=(unsigned long long)pm/p[i]*(c*(p[i]-1)+p[i]);
		dfs(i+1,m*pm,hm*phm);
	}
}	
void solve(int N){
	nn=0;
	for (int i=0;i<M && prime[i]*prime[i]<=N;i++) if (N%prime[i]==0){
		p[nn]=prime[i];
		k[nn]=1;
		for (N/=prime[i];N%prime[i]==0;k[nn]++,N/=prime[i]);
		nn++;
	}
	if (N>1){
		p[nn]=N;
		k[nn++]=1;
	}
//	for (int i=0;i<nn;i++)
//		printf("%d^%d*",p[i],k[i]);
//	puts("");
	ans=0;
	dfs(0,1,1);
	cout<<ans<<endl;
}
int main(){
	//freopen("i.txt","r",stdin);
	scanf("%d",&T);
	prepare();
	for (;T--;){
		scanf("%d",&N);
		solve(N);
	}
	return 0;
}

