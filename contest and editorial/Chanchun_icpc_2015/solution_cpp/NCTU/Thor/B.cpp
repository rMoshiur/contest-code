#include<cstdio>
#define N 40010
using namespace std;
int notp[N],prm[N],pcnt;
int main(){
	for(int i=2;i<N;i++){
		if(!notp[i]) prm[pcnt++]=i;
		for(int j=0;j<pcnt&&i*prm[j]<N;j++){
			notp[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
	int T,n,tn;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		tn=n;
		unsigned long long x=1,y=1;
		for(int i=0;i<pcnt&&n>1;i++){
			unsigned long long tt=1,add=1,cnt=1;
			while(n%prm[i]==0){
				add=add*prm[i]*prm[i];
				tt+=add;
				cnt++;
				n/=prm[i];
			}
			x*=tt;
			y*=cnt;
		}
		if(n>1){
			x*=(1+1LLU*n*n);
			y*=2;
		}
		printf("%llu\n",x-y*tn);
	}
	return 0;
}
