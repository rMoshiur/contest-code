#include <cmath>
#include <cstdio>

int n, cnt, p[30], c[30];
unsigned long long ans = 0;
void dfs(int i,long long n,long long fn){
	if(i==cnt){
		ans+=(n*n-fn);
		return;
	}
	dfs(i+1,n,fn);
	for(int j=1;j<=c[i];j++){
		 n*=p[i];
		fn*=p[i];
		dfs(i+1,n, (fn/p[i])*((p[i]-1)*j+p[i]) );
	}
}
#include <ctime>
#include <cassert>
int main()
{
	int t;scanf("%d",&t);
	int allt=clock();
	for(int ti=0;ti<t;ti++)
	{
		scanf("%d", &n);
		int x = n;
		cnt=0;
		for (int i = 2; i*i <= x; ++i)
		if (x % i == 0)
		{
			c[cnt]=0;
			for (; x % i == 0; x /= i) ++c[cnt];
			p[cnt++] = i;
		}
		if (x > 1) c[cnt] = 1, p[cnt++] = x;
		ans=0;
		dfs(0, 1, 1);
		printf("%llu\n", ans);
	}
	assert(scanf("%*s")==EOF);
	return 0;
}
