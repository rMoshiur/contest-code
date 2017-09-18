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
#define M 
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int t,n,m,in[55][55];
int ans;
int main()
{
	RI(t);
	while(t--)
	{
		ans = 0;
		MSET(in, 0);
		RI(n,m);
		REP(i,1,n)REP(j,1,m) RI(in[i][j]);

		//TOP
		REP(i,1,n)REP(j,1,m) if(in[i][j]) ans++; 

		//LEFT
		REP(i,1,n)REP(j,1,m)
			if(in[i][j] > in[i][j-1])
				ans += in[i][j] - in[i][j-1];

		//RIGHT
		REP(i,1,n)FORD(j,m,1)
			if(in[i][j] > in[i][j+1])
				ans += in[i][j] - in[i][j+1];

		//FRONT
		FORD(i,n,1)REP(j,1,m)
			if(in[i][j] > in[i+1][j])
				ans += in[i][j] - in[i+1][j];

		//BACK
		REP(i,1,n)REP(j,1,m)
			if(in[i][j] > in[i-1][j])
				ans += in[i][j] - in[i-1][j];

		printf("%d\n", ans);
	}
	return 0;
}

