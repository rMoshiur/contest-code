#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define inf (100000000)
#define maxN (105)
#define maxNodes (10005)
#define maxEdges ((maxNodes)*10)
using namespace std;

const int dx[]={1,1,-1,-1};
const int dy[]={1,-1,1,-1};
queue<int>Q;
int testcase,maxflow,T,N,M,A,B,ret,NODES,S,size;
int List[maxNodes],e[maxNodes*10],cap[maxEdges],_next[maxEdges];
int dist[maxNodes];
int pre[maxNodes];
int color[maxN][maxN];
int belong[maxNodes];
char str[maxN][maxN];
vector<int>E[maxNodes],RE[maxNodes];

int getID(int x,int y){
	return x*M+y;
}
void dfs(int x,int y,int c){
	color[x][y]=c;
	for (int i=0;i<4;i++){
		int tx=x+dx[i]*A,ty=y+dy[i]*B;
		if (tx<0 || tx>=N || ty<0 || ty>=M) continue;
		if (color[tx][ty]) continue;
		dfs(tx,ty,3-c);
	}
}
void addEdge(int u,int v,int w)
{
	//printf("addEdge:%d %d %d\n",u,v,w);
	e[size]=v;_next[size]=List[u];List[u]=size;cap[size++]=w;
	e[size]=u;_next[size]=List[v];List[v]=size;cap[size++]=0;
}
bool bfs()
{
	memset(dist,-1,sizeof(dist));
	memset(pre,-1,sizeof(pre));
	ret=T;
	dist[S]=0;
	Q.push(S);
	for (;!Q.empty();)
	{
		int u=Q.front();
		Q.pop();
		for (int p=List[u];p!=-1;p=_next[p])
		{
			if (cap[p] && dist[e[p]]==-1)
			{
				dist[e[p]]=dist[u]+1;
				Q.push(e[p]);
			}
		}
	}
	return dist[T]!=-1;
}
void pushflow()
{
	int flow=inf;
	for (int oo=pre[T];oo!=-1;oo=pre[e[oo^1]])
		if (cap[oo]<flow) flow=cap[oo];
	maxflow+=flow;
//	printf("push flow:%d\n",flow);
	for (int oo=pre[T];oo!=-1;oo=pre[e[oo^1]])
	{
		cap[oo]-=flow;
		cap[oo^1]+=flow;
		if (!cap[oo]) ret=e[oo^1];
	}
}
void dinic(int u)
{
	if (u==T) pushflow();
	else
	{
		for (int p=List[u];p!=-1;p=_next[p])
		{
			if (cap[p] && dist[e[p]]==dist[u]+1)
			{
				pre[e[p]]=p;
				dinic(e[p]);
				if (dist[ret]<dist[u]) return;
				ret=T;
			}
		}
		dist[u]=-1;
	}
}
void mark(int u,int c,vector<int> E[]){
	belong[u]=c;
	for (int i=0;i<E[u].size();i++){
		int v=E[u][i];
		if (!belong[v])
			mark(v,c,E);
	}
}
int main(){
	//freopen("I.in","r",stdin);
	//freopen("I.me.out","w",stdout);
	scanf("%d",&testcase);
	for (;testcase--;){
		scanf("%d%d%d%d",&N,&M,&A,&B);
		for (int i=0;i<N;i++)
		       scanf("%s",str[i]);
		memset(color,0,sizeof(color));
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++){
				if (!color[i][j])
					dfs(i,j,1);
			}
		//for (int i=0;i<N;i++,puts(""))
		//	for (int j=0;j<M;j++)
		//		printf("%d ",color[i][j]);
		size=0;
		memset(List,-1,sizeof(List));
		int ans=0;
		NODES=N*M+2;
		S=NODES-2;
		T=S+1;
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++){
				int u=getID(i,j);
				if (color[i][j]==1){
					if (str[i][j]=='B')
						addEdge(S,u,inf);
					if (str[i][j]=='W')
						addEdge(u,T,inf);
				}
				else{
					if (str[i][j]=='B')
						addEdge(u,T,inf);
					if (str[i][j]=='W')
						addEdge(S,u,inf);
				}
				for (int k=0;k<4;k++){
					int tx=i+dx[k]*A,ty=j+dy[k]*B;
					if (tx<0 || tx>=N || ty<0 || ty>=M) continue;
					ans++;
					int v=getID(tx,ty);
					addEdge(u,v,1);
				}
			}
		ans/=2;
		maxflow=0;
		for (;bfs();dinic(S));
		ans-=maxflow;
		printf("%d\n",ans);
		for (int i=0;i<NODES;i++){
			E[i].clear();
			RE[i].clear();
		}
		for (int i=0;i<NODES;i++){
			for (int p=List[i];p!=-1;p=_next[p]){
				if (cap[p]>0){
					E[i].push_back(e[p]);
					RE[e[p]].push_back(i);
				}
			}
		}
		memset(belong,0,sizeof(belong));
		mark(S,1,E);
		mark(T,2,RE);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++){
				int id=getID(i,j);
				if (belong[id]) continue;
				if (color[i][j]==1){
					mark(id,1,E);
				}
				else{
					mark(id,2,RE);
				}
			}
		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				int id=getID(i,j);
				if (color[i][j]==1 && belong[id]==1 || color[i][j]==2 && belong[id]==2) putchar('B');
				else putchar('W');
			}
			puts("");
		}
	}
	return 0;
}
