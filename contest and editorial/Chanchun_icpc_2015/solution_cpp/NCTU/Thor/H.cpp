#include<cstdio>
#include<algorithm>
#define N 2050
using namespace std;
int dp[N][N],a[N];
bool check[N][N];
int f(int n,int m){
	if(check[n][m]) return dp[n][m];
	check[n][m]=true;
	if(n==0) return dp[n][m]=0;
	if(m==0) return dp[n][m]=-1023456789;
	if(n>=m) return dp[n][m]=max(f(n-m,m)+a[m],f(n,m-1));
	return dp[n][m]=f(n,m-1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n-1;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				check[i][j]=false;
			}
		}
		for(int i=1;i<n-1;i++) a[i]-=a[0];
		printf("%d\n",n*a[0]+f(n-2,n-2));
	}
	return 0;
}
