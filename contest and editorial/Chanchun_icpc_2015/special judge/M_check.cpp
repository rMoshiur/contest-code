#include<bits/stdc++.h>
#include "testlib.h"
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

int t,n,m;
int mx_sol, mx_out;
int sol[M][M],out[M][M];
int a[M*M],b[M*M],c[M*M],d[M*M];
Pi st[M], ed[M];
vector<P> p[M];

void genEdges()
{
	P aa,bb,cc,dd,inter;
	n = inf.readInt();
	m = 0;
	REP(i,1,n)
	{
		st[i].F = inf.readInt();
		st[i].S = inf.readInt();
		ed[i].F = inf.readInt();
		ed[i].S = inf.readInt();
		p[i].clear();
	}

	REP(i,1,n)REP(j,i+1,n)
	{
		aa = P(st[i].F, st[i].S);
		bb = P(ed[i].F, ed[i].S);
		cc = P(st[j].F, st[j].S);
		dd = P(ed[j].F, ed[j].S);

		inter = jiao(aa,bb,cc,dd);
		if(inter.x==INF) continue;

		inter.l1 = i;
		inter.l2 = j;
		p[i].PB(inter);
		p[j].PB(inter);
	}

	REP(i,1,n) sort(p[i].begin(), p[i].end());
	REP(i,1,n) REP(j,1,(int)p[i].SZ-1)
	{
		++m;
		a[m] = p[i][j].l1;
		b[m] = p[i][j].l2;
		c[m] = p[i][j-1].l1;
		d[m] = p[i][j-1].l2;
	}
}
int main(int argc,char *argv[])
{
	if(argc==5)
	{
		argc++;
		argv[5] = new char[7];
		strcpy(argv[5], "-appes");
	}
	registerTestlibCmd(argc, argv);

	t = inf.readInt();
	while(t--)
	{
		genEdges();

		mx_sol = ans.readInt();
		REP(i,1,n)REP(j,i+1,n) sol[i][j] = ans.readInt();
		////

		mx_out = ouf.readInt(mx_sol, mx_sol);
		REP(i,1,n) REP(j,i+1,n)
		{
			out[i][j] = ouf.readInt();
			ensuref(out[i][j]==-1 || (out[i][j]>=1&&out[i][j]<=mx_out), "output = -1 or 1~color");

			if(out[i][j]==-1) ensuref(sol[i][j]==-1, "except a color, but output no edge");
			if(out[i][j]!=-1) ensuref(sol[i][j]!=-1, "except no edge, but output a color");
		}
		/////

		REP(i,1,m) ensuref(out[a[i]][b[i]] != out[c[i]][d[i]], "adjacent but same color %d %d %d %d",a[i],b[i],c[i],d[i]);
	}
	quitf(_ok, "OK");
	return 0;
}

