#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#define N 1010
#define eps 1e-8
using namespace std;
inline bool zero(double x){
	return x<eps&&x>-eps;
}
struct point{
	int num;
	double x,y;
	point(){}
	point(double _x,double _y,int _num=0):x(_x),y(_y),num(_num){}
	point operator+(const point& rhs)const{return point(x+rhs.x,y+rhs.y);}
	point operator-(const point& rhs)const{return point(x-rhs.x,y-rhs.y);}
	point operator*(double c)const{return point(x*c,y*c);}
	point operator/(double c)const{return point(x/c,y/c);}
	double operator^(const point& rhs)const{return x*rhs.y-y*rhs.x;}
	double operator*(const point& rhs)const{return x*rhs.x+y*rhs.y;}
	bool operator<(const point& rhs)const{return x<rhs.x-eps||x<rhs.x+eps&&y<rhs.y-eps;}
	void print()const{fprintf(stderr,"(%f,%f)\n",x,y);}
};
struct line{
	point p1,p2;
	point inter(const line &rhs)const{
		double a1=(rhs.p1-p1)^(rhs.p2-p1),a2=(rhs.p1-p2)^(rhs.p2-p2);
		return p1+(p2-p1)*a1/(a1-a2);
	}
	bool par(const line& rhs)const{
		return zero((p2-p1)^(rhs.p2-rhs.p1));
	}
}l[N];
vector<point> lp[N],all;
point p[N*N];
vector<int> g[N*N];
int col[N*N];
bool setc(int u,int c){
	if(col[u]!=-1) return col[u]==c;
	col[u]=c;
	for(int i=0;i<g[u].size();i++){
		if(!setc(g[u][i],3-c)) return false;
	}
	return true;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		all.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf %lf",&l[i].p1.x,&l[i].p1.y,&l[i].p2.x,&l[i].p2.y);
			lp[i].clear();
			for(int j=i+1;j<n;j++) col[i*n+j]=-1,g[i*n+j].clear();
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(!l[i].par(l[j])){
					point tmp=l[i].inter(l[j]);
					tmp.num=i*n+j;
					p[i*n+j]=tmp;
					lp[i].push_back(tmp);
					lp[j].push_back(tmp);
					all.push_back(tmp);
				}
			}
			sort(lp[i].begin(),lp[i].end());
			for(int j=0;j+1<lp[i].size();j++){
				g[lp[i][j].num].push_back(lp[i][j+1].num);
				g[lp[i][j+1].num].push_back(lp[i][j].num);
			}
		}
		sort(all.begin(),all.end());
		if(all.size()<=1){
			printf("%d\n",(int)all.size());
			for(int j=0;j<all.size();j++) col[all[j].num]=1;
		}
		else if(setc(all[0].num,1)){
			printf("2\n");
		}
		else{
			printf("3\n");
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					col[i*n+j]=-1;
				}
			}
			for(int i=0;i<all.size();i++){
				bool used[5]={};
				int c=1;
				for(int j=0;j<g[all[i].num].size();j++){
					if(col[g[all[i].num][j]]!=-1){
						used[col[g[all[i].num][j]]]=true;
					}
				}
				while(used[c]) c++;
				col[all[i].num]=c;
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				printf("%d ",col[i*n+j]);
			}
			puts("");
		}
	}
	return 0;
}
