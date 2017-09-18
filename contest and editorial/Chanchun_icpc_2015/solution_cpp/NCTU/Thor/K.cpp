#include<cstdio>
#include<queue>
#include<vector>
#include<ctime>
#include<algorithm>
#include<cstring>
#define N 110
#define Q 1000000007
#define getp(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
using namespace std;
struct rect{
	int x1,x2,y1,y2,c;
	bool operator<(const rect& o)const{return c<o.c;}
	bool inter(const rect& o)const{return max(x1,o.x1)<min(x2,o.x2)&&max(y1,o.y1)<min(y2,o.y2);}
}r[N];
bool cmp(const rect& a,const rect& b){
	return a.x1<b.x1;
}
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool uni(int x,int y){
	if(find(x)!=find(y)){
		f[f[x]]=f[y];
		return true;
	}
	return false;
}
int val[N<<1][N<<1];
int main(){
	vector<int> vx,vy;
	vector<rect> vr; 
	int T;
	scanf("%d",&T);
	while(T--){
		int n,ans=0;
		memset(val,0,sizeof(val));
		scanf("%d",&n);
		vx.clear();
		vy.clear();
		vr.clear();
		for(int i=1;i<=n;i++){
			f[i]=i;
			scanf("%d%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2,&r[i].c);
			r[i].x2++;
			r[i].y2++;
			vx.push_back(r[i].x1);
			vx.push_back(r[i].x2);
			vy.push_back(r[i].y1);
			vy.push_back(r[i].y2);
		}
		sort(vx.begin(),vx.end());
		sort(vy.begin(),vy.end());
		vx.resize(unique(vx.begin(),vx.end())-vx.begin());
		vy.resize(unique(vy.begin(),vy.end())-vy.begin());
		for(int i=1;i<=n;i++){
			vr.push_back(r[i]);
			sort(vr.begin(),vr.end());
			int add=0;
			for(int j=0;j<vr.size();j++) f[j]=j;
			for(int j=(int)vr.size()-1;j>=0;j--){
				int coe=-1;
				for(int k=(int)vr.size()-1;k>j;k--){
					if(vr[k].inter(vr[j])){
						if(uni(j,k)) coe++;
					}
				}
				add=(add+1LL*coe*vr[j].c)%Q;
				if(add<0) add+=Q;
				else if(add>=Q) add-=Q;
			}
			int sx=getp(vx,r[i].x1),tx=getp(vx,r[i].x2),sy=getp(vy,r[i].y1),ty=getp(vy,r[i].y2);
			for(int j=sx;j<tx;j++){
				for(int k=sy;k<ty;k++){
					if(r[i].c>val[j][k]){
						ans+=1LL*(vx[j+1]-vx[j])*(vy[k+1]-vy[k])%Q*(r[i].c-val[j][k])%Q;
						val[j][k]=r[i].c;
						if(ans>=Q) ans%=Q;
					}
				}	
			}
			printf("%d\n",(ans+add)%Q);
		}
	}
	fprintf(stderr,"%.2f s\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
