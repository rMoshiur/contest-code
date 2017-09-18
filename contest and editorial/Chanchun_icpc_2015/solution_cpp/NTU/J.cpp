#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 1005
using namespace std;
typedef long long LL;
int t,n,ans,in[M];
int cnt[M*32], nxt[M*32][2], id;

int newid()
{
	cnt[id] = nxt[id][0] = nxt[id][1] = 0;
	return id++;
}
void add(int d,int cur,int num,int v)
{
	cnt[cur] += v;
	if(d==0) return;

	int lr = (1<<(d-1)) & num;
	if(lr) lr = 1;

	if( !nxt[cur][lr] ) nxt[cur][lr] = newid();
	add(d-1, nxt[cur][lr], num, v);
}
int ask(int d,int cur,int num,int re)
{
	if(d==0) return re;
	
	int lr = (1<<(d-1)) & num;
	if(lr) lr=0;
	else   lr=1;
	
	if( nxt[cur][lr] && cnt[nxt[cur][lr]]>0 )
	{
		return ask(d-1, nxt[cur][lr], num, re|(1<<(d-1)));
	}
	else
	{
		return ask(d-1, nxt[cur][lr^1], num, re);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		id = 1;
		nxt[0][0] = nxt[0][1] = cnt[0] = 0;

		scanf("%d",&n);
		REP(i,1,n) scanf("%d",&in[i]);
		
		REP(i,1,n) add(31, 0, in[i], 1);
		REP(i,1,n)REP(j,i+1,n)
		{
			add(31, 0, in[i], -1);
			add(31, 0, in[j], -1);

			ans = max(ans, ask(31,0,in[i]+in[j],0) );

			add(31, 0, in[i], 1);
			add(31, 0, in[j], 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}

