#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ(x) ((int)x.size())
#define M 1005
#define L (cur<<1)
#define R (L+1)
#define MOD 1000000007
#define INF 2147483647
using namespace std;
typedef long long LL;
struct Ask
{
	int x1, x2, y1, y2, c;
	void read()
	{
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
	}
}ask[M];
struct Dsj
{
	int _n, fa[M*M];
	void init(int __n)
	{
		_n = __n;
		REP(i,0,_n) fa[i]=i;
	}
	int find(int x)
	{
		return fa[x]==x ? x:fa[x]=find(fa[x]);
	}
	void con(int x,int y)
	{
		x = find(x);
		y = find(y);
		if(x!=y) fa[x]=y;
	}
}dsj;
struct Edge
{
	int s,t,c;
	Edge (){}
	Edge (int _s,int _t,int _c)
	{
		s=_s, t=_t, c=_c;
	}
	bool operator < (const Edge& a) const
	{
		return c > a.c;
	}
}edg[M*M*4],edg2[M*M*4],edg3[M*M*4];
int t,n,m,q,cnt[M][M],id[M][M],c1[M][M],c2[M][M],c3[M][M];
bool upd2[M][M], upd3[M][M];
void init()
{
	vector<int> ix, iy;
	scanf("%d",&q);
	REP(i,1,q)
	{
		ask[i].read();
		ix.PB(ask[i].x1), ix.PB(ask[i].x2+1),
		iy.PB(ask[i].y1), iy.PB(ask[i].y2+1);
	}

	sort(ALL(ix)); ix.resize( unique(ALL(ix)) - ix.begin() );
	sort(ALL(iy)); iy.resize( unique(ALL(iy)) - iy.begin() );

	n = SZ(ix)-1;
	m = SZ(iy)-1;
	REP(i,1,n) REP(j,1,m) id[i][j] = (i-1)*m + j;
	REP(i,1,n) REP(j,1,m) c1[i][j] = c2[i][j] = c3[i][j] = -1;

	REP(i,1,q)
	{
		ask[i].x1 = lower_bound(ALL(ix), ask[i].x1) - ix.begin() + 1;
		ask[i].y1 = lower_bound(ALL(iy), ask[i].y1) - iy.begin() + 1;
		ask[i].x2 = upper_bound(ALL(ix), ask[i].x2) - ix.begin();
		ask[i].y2 = upper_bound(ALL(iy), ask[i].y2) - iy.begin();
	}

	REP(i,1,n)REP(j,1,m)
	{
		cnt[i][j] = (1LL * (ix[i]-ix[i-1]) * (iy[j]-iy[j-1]) - 1) % MOD; //#edges
		if(cnt[i][j] < 0) cnt[i][j]+=MOD;
	}
}
void work()
{
	int e=0, e2=0, e3=0;
	LL ans=0;
	REP(t,1,q)
	{
		REP(i,ask[t].x1,ask[t].x2) REP(j,ask[t].y1,ask[t].y2) if(ask[t].c > c1[i][j])
			c1[i][j] = ask[t].c;
		REP(i,ask[t].x1,ask[t].x2-1) REP(j,ask[t].y1,ask[t].y2) if(ask[t].c > c2[i][j])
			c2[i][j] = ask[t].c, upd2[i][j]=true;
		REP(i,ask[t].x1,ask[t].x2) REP(j,ask[t].y1,ask[t].y2-1) if(ask[t].c > c3[i][j])
			c3[i][j] = ask[t].c, upd3[i][j]=true;

		ans = 0;
		dsj.init(n*m);

		e3 = 0;
		REP(i,1,n-1) REP(j,1,m) if(upd2[i][j]) edg3[e3++] = Edge(id[i][j], id[i+1][j], c2[i][j]), upd2[i][j]=false;
		REP(i,1,n) REP(j,1,m-1) if(upd3[i][j]) edg3[e3++] = Edge(id[i][j], id[i][j+1], c3[i][j]), upd3[i][j]=false;
		sort(edg3, edg3+e3);

		merge(edg2,edg2+e2, edg3,edg3+e3, edg);
		e = e2+e3;

		REP(i,1,n)REP(j,1,m) if(c1[i][j] > 0)
		{
			ans += 1LL * c1[i][j] * cnt[i][j];
			if(ans>=MOD) ans %= MOD;
		}

		e2 = 0;
		REP(i,0,e-1) if(dsj.find(edg[i].s) != dsj.find(edg[i].t))
		{
			dsj.con(edg[i].s, edg[i].t);
			ans += edg[i].c;
			edg2[e2++] = edg[i];
		}

		if(ans>=MOD) ans %= MOD;
		printf("%d\n", (int)ans );
	}
}
int main()
{
	double st=clock();
	scanf("%d",&t);
	while(t--)
	{
		init();
		work();
	}
	fprintf(stderr,"time = %f\n",(double)(clock()-st)/CLOCKS_PER_SEC);
	return 0;
}


