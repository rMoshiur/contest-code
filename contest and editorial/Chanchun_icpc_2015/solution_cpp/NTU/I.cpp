#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin(); x!=y.end(); x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 305
#define INF 2000000000
using namespace std;
typedef long long LL;
struct edge{int t,opp,r,next;}in[20*M*M];
int st,ed,NODE,first[M*M],gap[M*M],dis[M*M],arc[M*M],out[M*M];
vector<int> ee[M*M], er[M*M];
int t,n,m,e,ans,aa,bb,ar[M][M],col[M][M],dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1};
void add(int x,int y,int z)
{
	in[e].t=y;
	in[e].r=z;
	in[e].opp=e+1;
	in[e].next=first[x];
	first[x]=e++;

	in[e].t=x;
	in[e].r=0;
	in[e].opp=e-1;
	in[e].next=first[y];
	first[y]=e++;
}
inline int id(int x,int y)
{
	return (x-1)*m+y;
}
bool inside(int x,int y)
{
	return x>=1 && y>=1 && x<=n && y<=m;
}
bool bfs()
{
	int cur;
	queue<int> q;
	REP(i,0,NODE) gap[i]=dis[i]=0, arc[i]=first[i];
	dis[ed] = 1;
	gap[1] = 1;
	q.push(ed);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(int i=first[cur]; ~i; i=in[i].next)
			if( in[in[i].opp].r && !dis[in[i].t] )
			{
				dis[in[i].t] = dis[cur]+1;
				gap[dis[in[i].t]]++;
				q.push(in[i].t);
			}
	}
	return dis[st];
}
int sap(int cur,int f)
{
	if(cur==ed)return f;

	int re=0, tmp;
	for(int i=arc[cur]; ~i; i=arc[cur]=in[i].next)
		if(dis[in[i].t] == dis[cur]-1 && in[i].r)
		{
			tmp = sap(in[i].t, min(f,in[i].r));
			re += tmp;
			f -= tmp;
			in[i].r -= tmp;
			in[in[i].opp].r += tmp;
			if(!f) return re;
		}
		
	gap[dis[cur]]--;
	if(!gap[dis[cur]]) dis[st]=-1000;
	dis[cur] = -1000;
	return re;
}
void dfs(int x,int y,int c)
{
	col[x][y]=c;

	c*=-1;
	REP(i,0,3)
		if(inside(x+dx[i]*aa, y+dy[i]*bb) && !col[x+dx[i]*aa][y+dy[i]*bb])
			dfs(x+dx[i]*aa, y+dy[i]*bb, c);
}
void draw(int cur,int c,vector<int> E[M])
{
	out[cur] = c;
	FOR(i,E[cur]) if(!out[*i]) draw(*i, c, E);
}
void work()
{
	int x,y;
	char buf[M];
	scanf("%d %d %d %d",&n,&m,&aa,&bb);
	REP(i,1,n)
	{
		scanf("%s", buf+1);
		REP(j,1,m)
		{
			if(buf[j]=='B') ar[i][j] = -1;
			else if(buf[j]=='.') ar[i][j] = 0;
			else ar[i][j] = 1;
		}
	}

	ans = e = 0;
	NODE = n*m+2;
	st = 0;
	ed = n*m+1;
	REP(i,1,n)REP(j,1,m) col[i][j] = 0;
	REP(i,0,NODE) first[i]=-1;
	
	REP(i,1,n)REP(j,1,m)
		if(!col[i][j])
			dfs(i,j,1);
	REP(i,1,n)REP(j,1,m)REP(k,0,3)
	{
		x=i+dx[k]*aa;
		y=j+dy[k]*bb;
		if(inside(x,y))
		{
			add(id(i,j), id(x,y), 1);
			ans++;
		}
	}
	ans/=2;

	REP(i,1,n)REP(j,1,m)
		if(ar[i][j])
		{
			if(col[i][j] == 1)
			{
				if(ar[i][j]==1)add(st,id(i,j),INF); //W=st
				else add(id(i,j),ed,INF); //B=ed
			}
			else
			{
				if(ar[i][j]==-1)add(st,id(i,j),INF); //B=st
				else add(id(i,j),ed,INF); //W=ed
			}
		}

	while(bfs()) ans-=sap(st,INF);
	
	//lex smallest
	REP(i,0,NODE) out[i]=0, ee[i].clear(), er[i].clear();
	REP(i,0,NODE)
		for(int j=first[i]; ~j; j=in[j].next) if(in[j].r)
			ee[i].PB(in[j].t), er[in[j].t].PB(i);

	draw(st, 1, ee);
	draw(ed, 2, er);
	REP(i,1,n)REP(j,1,m)
	{
		x = id(i,j);
		if( out[x] ) continue;
		if( col[i][j]==1 )
			draw(x, 2, er);
		else
			draw(x, 1, ee);
	}
}
int main()
{
	int x;
	scanf("%d",&t);
	while(t--)
	{
		work();
		printf("%d\n",ans);

		REP(i,1,n)
		{
			REP(j,1,m)
			{
				x = id(i,j);
				if(col[i][j]==1) putchar(out[x]==1 ? 'W':'B');
				else             putchar(out[x]==1 ? 'B':'W');
			}
			puts("");
		}
	}
	return 0;
}

