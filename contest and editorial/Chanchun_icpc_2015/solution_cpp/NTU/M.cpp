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
#define INF 1e100
using namespace std;
typedef long long LL;
typedef pair<int,int> Pi;
double eps = 1e-8;
struct P
{
	int l1,l2;
	double x,y;
	P(){}
	P(double a,double b)
	{
		x = a;
		y = b;
	}
	P operator + (const P& b)
	{
		return P(x+b.x, y+b.y);
	}
	P operator - (const P& b)
	{
		return P(x-b.x, y-b.y);
	}
	P operator * (const double& b)
	{
		return P(x*b, y*b);
	}
	bool operator < (const P& b) const
	{
		if( fabs(x-b.x) > eps ) return x<b.x;
		return y<b.y;
	}
	double X(P b)
	{
		return x*b.y - y*b.x;
	}
};
P jiao(P& a1,P& a2,P& b1,P& b2)
{
	P a=a2-a1, b=b2-b1, s=b1-a1;
	if( fabs(a.X(b)) < eps ) return P(INF, INF);
	return a1 + a * (s.X(b) / a.X(b));
}
int t,n,ans[M][M],col[M][M];
Pi st[M], ed[M];
vector<P> p[M], all;
vector<Pi> e[M][M];

bool dfs(int x,int y,int c)
{
	col[x][y] = c;
	FOR(i,e[x][y])
	{
		if(!col[i->F][i->S])
		{
			if( !dfs(i->F, i->S, 3-c) ) return false;
		}
		else if(col[i->F][i->S] == col[x][y])
			return false;
	}
	return true;
}
bool bipartite()
{
	REP(i,1,n)REP(j,i+1,n) if(col[i][j]==0)
		if( !dfs(i,j,1) )
			return false;
	return true;
}
int main()
{
	int x,y;
	bool vis[4];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d", &n);
		all.clear();
		REP(i,1,n) p[i].clear();
		REP(i,1,n) REP(j,i+1,n) col[i][j]=-1, ans[i][j]=-1, e[i][j].clear();
		REP(i,1,n)
		{
			scanf("%d %d",&st[i].F,&st[i].S);
			scanf("%d %d",&ed[i].F,&ed[i].S);
		}

		REP(i,1,n)REP(j,i+1,n)
		{
			P a = P(st[i].F, st[i].S);
			P b = P(ed[i].F, ed[i].S);
			P c = P(st[j].F, st[j].S);
			P d = P(ed[j].F, ed[j].S);

			P inter = jiao(a,b,c,d);
			if(inter.x==INF) continue;
			
			ans[i][j] = 0;
			col[i][j] = 0;
			inter.l1 = i;
			inter.l2 = j;
			all.PB(inter);
			p[i].PB(inter);
			p[j].PB(inter);
		}

		//build edge
		REP(i,1,n) sort(p[i].begin(), p[i].end());
		REP(i,1,n) REP(j,1,(int)p[i].SZ-1)
		{
			e[p[i][j].l1][p[i][j].l2].PB( MP(p[i][j-1].l1, p[i][j-1].l2) );
			e[p[i][j-1].l1][p[i][j-1].l2].PB( MP(p[i][j].l1, p[i][j].l2) );

//			printf("%d %d %d %d\n",p[i][j].l1,p[i][j].l2,p[i][j-1].l1,p[i][j-1].l2);
		}

		//outputEdges();

		if( bipartite() )
		{
			int num = 1;
			REP(i,1,n)REP(j,i+1,n) num=max(num, col[i][j]);

			printf("%d\n", num);
			REP(i,1,n-1)
			{
				REP(j,i+1,n)
				{
					if(j!=i+1) putchar(' ');
					printf("%d", col[i][j]);
				}
				puts("");
			}
		}
		else
		{
			sort(all.begin(), all.end());
			FOR(i,all)
			{
				x = i->l1;
				y = i->l2;
				if(ans[x][y]==0)
				{
					MSET(vis, false);
					FOR(j,e[x][y]) if(ans[j->F][j->S]>=1) vis[ans[j->F][j->S]] = true;
					REP(j,1,3) if(vis[j]==false)
					{
						ans[x][y] = j;
						break;
					}
				}
			}

			puts("3");
			REP(i,1,n-1)
			{
				REP(j,i+1,n)
				{
					if(j!=i+1) putchar(' ');
					printf("%d", ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}

