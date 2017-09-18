#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxN (40005)
#define maxNodes (10005)
using namespace std;

typedef pair<int,int> Tpair;
char str[maxN],temp[maxN];
int T,N,M,Q,NODES;
unsigned long long f[2][700],isA[700];
int _next[maxNodes][26],fail[maxNodes],len[maxNodes];
bool word[maxNodes];
vector<int>occ[maxN];
vector<Tpair>query[maxN];
int ans[maxN];

void insert(char *s){
	int now=0;
	for (;*s;s++){
		int c=*s-'a';
		if (_next[now][c]==-1){
			len[NODES]=len[now]+1;
			_next[now][c]=NODES++;
		}
		now=_next[now][c];
	}
	word[now]=true;
}
void build(){
	queue<int>Q;
	fail[0]=0;
	for (int i=0;i<26;i++){
		if (_next[0][i]==-1){
			_next[0][i]=0;
		}
		else{
			Q.push(_next[0][i]);
			fail[_next[0][i]]=0;
		}
	}
	for (;!Q.empty();Q.pop()){
		int now=Q.front();
		for (int i=0;i<26;i++){
			if (_next[now][i]==-1){
				_next[now][i]=_next[fail[now]][i];
			}
			else{
				fail[_next[now][i]]=_next[fail[now]][i];
				Q.push(_next[now][i]);
			}
		}
	}
}
void getIndex(int pos,int &x,int &y){
	x=pos/64;
	y=pos%64;
}
void setIsA(int pos){
	int x,y;
	getIndex(pos,x,y);
	isA[x]|=(unsigned long long)(1)<<y;
}
int main(){
	//freopen("C.in","r",stdin);
	//freopen("C.me.out","w",stdout);
	scanf("%d",&T);
	for (;T--;){
		scanf("%d%d%d",&N,&M,&Q);
		scanf("%s",str);
		memset(_next,-1,sizeof(_next));
		memset(word,false,sizeof(word));
		NODES=1;
		len[0]=0;
		for (int i=0;i<M;i++){
			scanf("%s",temp);
			insert(temp);
		}
		memset(query,0,sizeof(query));
		for (int i=0;i<Q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			l--;
			r--;
			query[r-l+1].push_back(make_pair(l,i));
		}
		build();
		memset(occ,0,sizeof(occ));
		int t=0;
		for (int i=0;i<N;i++){
			t=_next[t][str[i]-'a'];
			int tmp=t;
			for (;tmp!=0;tmp=fail[tmp]){
				if (word[tmp]){
					//printf("%d %d\n",i-len[tmp]+1,i);
					occ[len[tmp]].push_back(i-len[tmp]+1);
				}
			}
		}
		int tot=N/64;
		if (N%64!=0)
			tot++;
		int pre=0,now=1;
		memset(f,0,sizeof(f));
		for (int l=1;l<=N;l++){
			pre^=1;
			now^=1;
			memset(isA,0,sizeof(isA));
			int size=occ[l].size();
			for (int i=0;i<size;i++){
				setIsA(occ[l][i]);
			}
			for (int i=0;i<tot;i++){
				if (i*64+l>N)
					break;
				f[now][i]=~isA[i];
				if (l==1) continue;
				f[now][i]&=~(f[pre][i]&((f[pre][i]>>1)+((f[pre][i+1]&1)<<63)));
			}
			size=query[l].size();
			for (int i=0;i<size;i++){
				int pos=query[l][i].first;
				int id=query[l][i].second;
				int x,y;
				getIndex(pos,x,y);
				ans[id]=(f[now][x]>>y)&1;
			}
		}
		for (int i=0;i<Q;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
