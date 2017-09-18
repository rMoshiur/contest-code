#include<cstdio>
#include<algorithm>
using namespace std;
int c[9],ex[9],sum[9],v[9]={0,1,5,10,20,100,200,1000,2000},c50,c500;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int p,ans=-1;
		scanf("%d",&p);
		for(int i=1;i<=4;i++) scanf("%d",&c[i]);
		scanf("%d",&c50);
		for(int i=5;i<=6;i++) scanf("%d",&c[i]);
		scanf("%d",&c500);
		for(int i=7;i<=8;i++) scanf("%d",&c[i]);
		for(int i=0;i<=min(1,c50);i++){
			for(int j=0;j<=min(1,c500);j++){
				int tp=p-i*50-j*500;
				if(tp<0) continue;
				int res=i+j;
				ex[5]=(c50-i)/2;
				ex[7]=(c500-j)/2;
				c[5]+=ex[5];
				c[7]+=ex[7];
				for(int k=1;k<=8;k++){
					sum[k]=sum[k-1]+v[k]*c[k];
				}
				for(int k=8;k>=1;k--){
					if(sum[k-1]<tp%v[k]){
						res=-1;
						break;
					}
					int mx=max((tp-tp%v[k])/v[k]-(sum[k-1]-tp%v[k])/v[k],0);
					if(mx>c[k]){
						res=-1;
						break;
					}
					res+=mx+min(mx,ex[k]);
					tp-=mx*v[k];
				}
				ans=max(ans,res);
				c[5]-=ex[5];
				c[7]-=ex[7];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
