#include<cstdio>
#include<algorithm>
#define N 1010
using namespace std;
int a[N],id[N];
int ni,nj;
bool cmp(int i,int j){
	return a[i]<a[j];
}
inline bool check(int l,int r){
	if(r-l>=3) return true;
	for(int i=l;i<r;i++){
		if(id[i]!=ni&&id[i]!=nj) return true;
	}
	return false;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int ans=0,n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			id[i]=i;
		}
		sort(id,id+n,cmp);
		id[n]=n;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ni=i,nj=j;
				int sum=a[i]+a[j],l=0,r=n;
				a[n]=0;
				for(int k=29;k>=0;k--){
					a[n]^=1<<k;
					int m=lower_bound(id+l,id+r,n,cmp)-id;
					if(!check(l,m)){
						l=m;
					}
					else if(!check(m,r)){
						r=m;
						a[n]^=1<<k;
					}
					else{
						if(sum&(1<<k)){
							r=m;
							a[n]^=1<<k;
						}
						else{
							l=m;
						}
					}
				}
				if((sum^a[id[l]])>ans) ans=sum^a[id[l]];
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
