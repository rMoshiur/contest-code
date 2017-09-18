#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxN (1005)

using namespace std;

int T,N,maxlen,nodes,s[maxN],node[maxN],nxt[maxN*35][2];
int exist[maxN*35];
int num[35];

int getLen(int s){
	int len=0;
	for (;s;s>>=1,len++);
	return len;
}
void cut(int s,int len){
	for (;len--;s>>=1){
		num[len]=s&1;
	}
}
int insert(int s,int len){
	cut(s,len);
//	printf("insert %d:",s);
//	for (int i=0;i<len;i++)
//		printf("%d",num[i]);
//	puts("");
	int now=0;
	for (int i=0;i<len;i++){
		if (nxt[now][num[i]]==-1){
			nxt[now][num[i]]=nodes++;
		}
		now=nxt[now][num[i]];
	}
	exist[now]++;
	return now;
}	
bool dfs(int i,int now,int tmp,int &ans){
	if (now==-1)
		return false;
	if (i==maxlen){
		if (!exist[now])
			return false;
		if (tmp>ans)
			ans=tmp;
		return true;
	}
	if (dfs(i+1,nxt[now][1^num[i]],tmp|(1<<(maxlen-i-1)),ans))
		return true;
	return dfs(i+1,nxt[now][num[i]],tmp,ans);
}
int main(){
	scanf("%d",&T);
	for (;T--;){
		scanf("%d",&N);
		maxlen=1;
		nodes=1;
		memset(nxt,-1,sizeof(nxt));
		memset(exist,0,sizeof(exist));
		for (int i=0;i<N;i++){
			scanf("%d",&s[i]);
			int tmp=getLen(2*s[i]);
			if (tmp>maxlen)
				maxlen=tmp;
		}
		for (int i=0;i<N;i++)
			node[i]=insert(s[i],maxlen);
		int ans=0;
		for (int i=0;i<N;i++)
			for (int j=i+1;j<N;j++){
				cut(s[i]+s[j],maxlen);
				exist[node[i]]--;
				exist[node[j]]--;
				dfs(0,0,0,ans);
				exist[node[i]]++;
				exist[node[j]]++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
