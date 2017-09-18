#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100+10;
const int maxnode = 10000+10;
const int maxedge = 100000+10;
const int INF = 1000000000;
int node, src, dest, nedge;
int head[maxnode], point[maxedge], next[maxedge], flow[maxedge], capa[maxedge];
int dist[maxnode], Q[maxnode], work[maxnode];
void init(int _node, int _src, int _dest) {
    node = _node;
    src = _src;
    dest = _dest;
    nedge = 0;
    memset(point, -1, sizeof(point));
    for (int i = 0; i < node; i++) head[i] = -1;
    nedge = 0;
}
void add_edge(int u, int v, int c1, int c2) {
    point[nedge] = v, capa[nedge] = c1, flow[nedge] = 0, next[nedge] = head[u], head[u] = (nedge++);
    point[nedge] = u, capa[nedge] = c2, flow[nedge] = 0, next[nedge] = head[v], head[v] = (nedge++);
}
bool dinic_bfs() {
    memset(dist, 255, sizeof (dist));
    dist[src] = 0;
    int sizeQ = 0;
    Q[sizeQ++] = src;
    for (int cl = 0; cl < sizeQ; cl++)
        for (int k = Q[cl], i = head[k]; i >= 0; i = next[i])
            if (flow[i] < capa[i] && dist[point[i]] < 0) {
                dist[point[i]] = dist[k] + 1;
                Q[sizeQ++] = point[i];
            }
    return dist[dest] >= 0;
}
int dinic_dfs(int x, int exp) {
    if (x == dest) return exp;
    for (int &i = work[x]; i >= 0; i = next[i]) {
        int v = point[i], tmp;
        if (flow[i] < capa[i] && dist[v] == dist[x] + 1 && (tmp = dinic_dfs(v, min(exp, capa[i] - flow[i]))) > 0) {
            flow[i] += tmp;
            flow[i^1] -= tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic_flow() {
    int result = 0;
    while (dinic_bfs()) {
        for (int i = 0; i < node; i++) work[i] = head[i];
        while (1) {
            int delta = dinic_dfs(src, INF);
            if (delta == 0) break;
            result += delta;
        }
    }
    return result;
}
char ansg[MAXN][MAXN];
char g[MAXN][MAXN];
int col[MAXN][MAXN];
int dx[]={1,1,-1,-1},dy[]={1,-1,1,-1};
int n,m,a,b;
void draw(int x,int y,int c){
    col[x][y]=c;
    for(int i=0;i<4;i++){
        int nx=x+a*dx[i],ny=y+b*dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||col[nx][ny])continue;
        draw(nx,ny,-1*c);
    }
}
void draw_ans1(int now,int c){
    if(c==1)ansg[now/m][now%m]='W';
    else ansg[now/m][now%m]='B';
    for(int i=head[now];i>=0;i=next[i]){
        int nn=point[i];
        if(ansg[nn/m][nn%m]==0){
            if(capa[i]-flow[i]!=0)draw_ans1(nn,-1*c);
        }
    }
}
void draw_ans2(int now,int c){
    if(c==1)ansg[now/m][now%m]='W';
    else ansg[now/m][now%m]='B';
    for(int i=head[now];i>=0;i=next[i]){
        int nn=point[i];
        if(ansg[nn/m][nn%m]==0){
            if(capa[i^1]-flow[i^1]!=0)draw_ans2(nn,-1*c);
        }
    }
}
void draw_remain(int x,int y,int c){
    if(c==-1)ansg[x][y]='B';
    else ansg[x][y]='W';
    for(int i=0;i<4;i++){
        int nx=x+a*dx[i],ny=y+b*dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||ansg[nx][ny])continue;
        draw_remain(nx,ny,-1*c);
    }
}
void gen_ans(){
    memset(ansg,0,sizeof(ansg));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]!='.')ansg[i][j]=g[i][j];
        }
    }
    for(int i=head[src];i>=0;i=next[i]){
        int nx=point[i]/m,ny=point[i]%m;
        if(g[nx][ny]=='W')draw_ans1(point[i],1);
        else if(g[nx][ny]=='B')draw_ans1(point[i],-1);
    }
    for(int i=head[dest];i>=0;i=next[i]){
        int nx=point[i]/m,ny=point[i]%m;
        if(g[nx][ny]=='W')draw_ans2(point[i],1);
        else if(g[nx][ny]=='B')draw_ans2(point[i],-1);
    }
    for(int i=0;i<n;i++){
        ansg[i][m]='\0';
        for(int j=0;j<m;j++){
            if(ansg[i][j]==0)draw_remain(i,j,-1);
        }
    }
    for(int i=0;i<n;i++)printf("%s\n",ansg[i]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&a,&b);
        init(n*m+2,n*m,n*m+1);
        for(int i=0;i<n;i++)scanf("%s",g[i]);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int nx=i+a*dx[k],ny=j+b*dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=m)continue;
                    add_edge(i*m+j,nx*m+ny,1,0);
                    ans++;
                }
            }
        }
        ans/=2;
        memset(col,0,sizeof(col));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!col[i][j])draw(i,j,1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(col[i][j]==1){
                    if(g[i][j]=='B')add_edge(src,i*m+j,INF,0);
                    else if(g[i][j]=='W')add_edge(i*m+j,dest,INF,0);
                }
                else{
                    if(g[i][j]=='W')add_edge(src,i*m+j,INF,0);
                    else if(g[i][j]=='B')add_edge(i*m+j,dest,INF,0);
                }
            }
        }
        printf("%d\n",ans-dinic_flow());
        gen_ans();
    }
    return 0;
}
