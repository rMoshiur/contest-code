#include <stdio.h>
#include <string.h>


struct node
{
	int c,v;
};

int f[2100];
int cost[2100];
int pre[2100];
int dp[2100];

node good[2100];

int main()
{
	int cas;
	int n;
	int ans;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		for(int i=1; i<n; i++){
			scanf("%d",&f[i]);
		}
		ans=f[1]*2+f[2]*(n-2);
		for(int i=2; i<n-1; i++){
			cost[i]=f[1]+f[i+1]-f[2]-f[i];
		}
		pre[1]=0;
		for(int i=2; i<n-1; i++){
			pre[i]=cost[i]+pre[i-1];
			good[i-2].c=i;
			good[i-2].v=pre[i];
		}
		memset(dp,0,sizeof(dp));
		int mmax=0;
		for(int i=0; i<n-3; i++){
			for(int j=good[i].c; j<=n-2; j++){
				if(dp[j]<dp[j-good[i].c]+good[i].v)
					dp[j]=dp[j-good[i].c]+good[i].v;
				if(mmax<dp[j])
					mmax=dp[j];
			}
		}
		ans+=mmax;
		printf("%d\n",ans);
	}
	return 0;
}
