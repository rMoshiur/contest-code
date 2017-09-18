#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double INF = 1.0/0.0;
const double SIDE = 10000;
const double PI = acos(-1.0);
const int MAXN = 500000 + 10;
struct PT{
	double x,y;
	PT(){}
	PT(double x,double y):x(x),y(y){}
	PT operator + (const PT& p)const{
		return PT(x+p.x,y+p.y);
	}
	PT operator - (const PT& p)const{
		return PT(x-p.x,y-p.y);
	}
	PT operator * (double c)const{
		return PT(x*c,y*c);
	}
	PT operator / (double c)const{
		return PT(x/c,y/c);
	}
	double operator *(const PT& p)const{
		return x*p.x+y*p.y;
	}
	double operator ^(const PT& p)const{
		return x*p.y-y*p.x;
	}
	bool operator ==(const PT& p)const{
		return fabs(x-p.x)<eps&&fabs(y-p.y)<eps;
	}
}poi[MAXN],stk[MAXN];
int top;
inline int ori(const PT& p1,const PT& p2,const PT& p3){
	double a=(p2-p1)^(p3-p1);
	if(a>-eps&&a<eps)return 0;
	return a>0 ? 1:-1;
}
inline bool btw(const PT& p1,const PT& p2,const PT& p3){
	return (p2-p1)*(p3-p1)<eps;
}
inline bool intersection(const PT& p1,const PT& p2,const PT& p3,const PT& p4){
	int a123=ori(p1,p2,p3);
	int a124=ori(p1,p2,p4);
	int a341=ori(p3,p4,p1);
	int a342=ori(p3,p4,p2);
	if(a123==0&&a124==0)return btw(p1,p3,p4)||btw(p2,p3,p4)||btw(p3,p1,p2)||btw(p4,p1,p2);
	return a123*a124 <= 0 && a341*a342 <= 0;
}
inline double dist(const PT& p1,const PT& p2){
	return sqrt((p2-p1)*(p2-p1));
}
inline double tri(const PT& p1,const PT& p2,const PT& p3){
	return fabs((p2-p1)^(p3-p1));
}
inline bool cmp_convex(const PT &a,const PT &b){
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
inline void convex_hull(PT a[],int &n){
	top=0;
	sort(a,a+n,cmp_convex);
	for(int i=0;i<n;i++){
		while(top>=2&&ori(stk[top-2],stk[top-1],a[i])>=0)top--;
		stk[top++]=a[i];
	}
	for(int i=n-2,t=top+1;i>=0; i--){
		while(top>=t&&ori(stk[top-2],stk[top-1],a[i])>=0)top--;
		stk[top++]=a[i];
	}
	top--;
	for(int i=0;i<top;i++)poi[i]=stk[i];
}
bool check(){
	poi[top]=poi[0];
	double si=dist(poi[0],poi[1]);
	for(int i=0;i<top;i++){
		//printf("%.6f\n",dist(poi[i],poi[i+1]));
		if(fabs(dist(poi[i],poi[i+1])-si)>eps)return 0;
	}
	poi[top+1]=poi[1];
	double an=(poi[0]-poi[1])*(poi[2]-poi[1]);
	for(int i=0;i<top;i++){
		double tmp=(poi[i]-poi[i+1])*(poi[i+2]-poi[i+1]);
		//printf("%.6f\n",an);
		if(fabs(tmp-an)>eps)return 0;
	}
	return 1;
}
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lf%lf",&poi[i].x,&poi[i].y);
		convex_hull(poi,n);
		if(n!=top){
			puts("NO");
			continue;
		}
		if(check())puts("YES");
		else puts("NO");
	}
	return 0;
}
