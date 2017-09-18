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
typedef pair<int,int> P;
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
map<int,int>mp;
unsigned long long sum;
template<class T>
void dfs(T s,T e,int p,int phip,int n){
	if(s==e){
		sum+=1llu*phip*(n-n/p);
		return;
	}
	dfs(s+1,e,p,phip,n);
	FZ(i,s->SEC){
		p*=s->FIR;
		phip*=(s->FIR-(i==0));
		dfs(s+1,e,p,phip,n);
	}
}
template<class T>
void dfs2(T s,T e,vector<P>&a,int p){
	if(s==e){
		dfs(ALL(a),1,1,p);
		return;
	}
	dfs2(s+1,e,a,p);
	a.push_back(P(s->FIR,0));
	FZ(i,s->SEC){
		p*=s->FIR;
		a.back().SEC++;
		dfs2(s+1,e,a,p);
	}
	a.pop_back();
}
unsigned long long sol(int n){
	mp.clear();
	int t=n;
	for(int i=0;i<ppt&&pp[i]*pp[i]<=n&&t!=1;i++){
		int&tp=pp[i];
		for(;t%tp==0;t/=tp)mp[tp]++;
	}
	if(t!=1)mp[t]++;
	vector<P>fac=vector<P>(ALL(mp));
	vector<P>fac2;
	sum=0;
	dfs2(ALL(fac),fac2,1);
	return sum;
}
#include<time.h>
int main(){
	int t;scanf("%d",&t);
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

