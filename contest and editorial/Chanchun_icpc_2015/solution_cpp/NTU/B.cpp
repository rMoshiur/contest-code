#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<assert.h>
using namespace std;

#define FZ(i,n) for(int i=0;i<(n);i++)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define FIR first
#define SEC second
typedef long long int lnt;
int isp[100000],pp[100000],ppt;
void make_pp(){
	const int n=31622;
	ppt=0;
	for(int i=2;i<n;i++){
		if(isp[i]==0){
			pp[ppt++]=i;
			for(int j=i;j<n;j+=i){
				isp[j]=1;
			}
		}
	}
}
lnt p[30],c[30],pt;
unsigned long long sum;
void dfs(int i,lnt n,lnt fn){
	if(i==pt){
		sum+=(n*n-fn);
		return;
	}
	dfs(i+1,n,fn);
	FZ(j,c[i]){
		 n*=p[i];
		fn*=p[i];
		dfs(i+1,n, (fn/p[i])*((p[i]-1)*(j+1)+p[i]) );
	}
}
unsigned long long sol(int n){
	pt=0;
	int t=n;
	for(int i=0;i<ppt&&pp[i]*pp[i]<=n&&t!=1;i++){
		int&tp=pp[i];
		if(t%tp==0){
			c[pt]=1;
			for(t/=tp;t%tp==0;t/=tp)c[pt]++;
			p[pt++]=tp;
		}
	}
	if(t!=1){
		c[pt]=1;
		p[pt++]=t;
	}
	sum=0;
	dfs(0,1,1);
	return sum;
}
#include<time.h>
int main(){
	int t;scanf("%d",&t);
	assert(1<=t&&t<=20000);
	int allt=clock();
	make_pp();
	for(int ti=0;ti<t;ti++){
		int n;
		cin>>n;
		assert(1<=n&&n<=1000000000);
		unsigned long long ans=sol(n);
		cout<<ans<<endl;
	}
	assert(scanf("%*s")==EOF);
	return 0;
}

