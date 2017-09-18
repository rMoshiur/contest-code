#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
#include<ctime>
#define N 40010
#define M 10010
using namespace std;
struct node{
	node *flink,*nxt[26];
	bitset<250> mat;
	int big[50];
	int sz;
	void add_big(int x){
		big[sz++]=x;
	}
	node(){
		flink=NULL;
		sz=0;
		memset(nxt,0,sizeof(nxt));
	}
};
node *root,*que[M];
char s[N],p[M];
bitset<N> win[N],fail[N];
void addPattern(){
	node *now=root;
	int i=0;
	for(i=0;p[i];i++){
		if(!now->nxt[p[i]-'a']) now->nxt[p[i]-'a']=new node();
		now=now->nxt[p[i]-'a'];
	}
	if(i>=250) now->add_big(i);
	else now->mat[i]=true;
}
void build(){
	int qf=0,qt=1;
	que[0]=root;
	while(qf<qt){
		node *now=que[qf],*fnode=now->flink;
		if(fnode){
			now->mat|=fnode->mat;
			memcpy(now->big+now->sz,fnode->big,sizeof(int)*fnode->sz);
			now->sz+=fnode->sz;
		}
		for(int i=0;i<26;i++){
			if(now->nxt[i]){
				fnode=now->flink;
				while(fnode&&!fnode->nxt[i]) fnode=fnode->flink;
				if(fnode) now->nxt[i]->flink=fnode->nxt[i];
				else now->nxt[i]->flink=root;
				que[qt++]=now->nxt[i];
			}
		}
		++qf;
	}
}
void match(){
	node *now=root;
	for(int i=0;s[i];i++){
		while(now&&!now->nxt[s[i]-'a']) now=now->flink;
		if(now) now=now->nxt[s[i]-'a'];
		else now=root;
		for(int j=0;j<250;j++){
			if(now->mat[j]) fail[j][i+1]=true;
		}
		for(int j=0;j<now->sz;j++){
			fail[now->big[j]][i+1]=true;
		}
	}
}
void del(node *now){
	for(int i=0;i<26;i++){
		if(now->nxt[i]) del(now->nxt[i]);
	}
	delete now;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		root=new node();
		int n,q,m;
		scanf("%d%d%d",&n,&m,&q);
		scanf("%s",s);
		for(int i=0;i<m;i++){
			scanf("%s",p);
			addPattern();
		}
		build();
		match();
		for(int i=1;i<=n;i++){
			win[i]=(~fail[i])&(~win[i-1]|~win[i-1]<<1);
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			if(win[y-x+1][y]) puts("1");
			else puts("0");
		}
		for(int i=1;i<=n;i++){
			fail[i].reset();
			win[i].reset();
		}
		del(root);
	}
	fprintf(stderr,"%.2f seconds\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
