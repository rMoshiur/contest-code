#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxN (10005)
#define eps (1e-7)
#define SQR(x) ((x)*(x))
using namespace std;

const double PI=acos(-1.0);
int T,N,px[maxN],py[maxN];
int d[maxN];
int a[maxN],b[maxN];
double r[maxN];

int getDist(int x1,int y1,int x2,int y2){
	return (int)sqrt(SQR(x1-x2)+SQR(y1-y2));
}
int sgn(double x){
	if (x>eps) return 1;
	if (x<-eps) return -1;
	return 0;
}
int main(){
	//freopen("E.in","r",stdin);
	//freopen("E.me.out","w",stdout);
	scanf("%d",&T);
	for (;T--;){
		scanf("%d",&N);
		for (int i=0;i<N;i++)
			scanf("%d%d",&px[i],&py[i]);
		for (int i=0;i<N;i++)
			d[i]=getDist(px[i],py[i],px[(i+1)%N],py[(i+1)%N]);
		if (N%2==1){
			int tot1=0,tot2=0;
			for (int i=0;i<N;i++){
				tot1+=d[i];
				if (i%2==1)
					tot2+=d[i];
			}
			bool ok=true;
			double sum=0.0;
			r[0]=(double)tot1/2.0-tot2;
			sum+=SQR(r[0]);
			if (sgn(r[0])<0 || sgn(r[0]-d[0])>0)
				ok=false;
			else{
				for (int i=1;i<N;i++){
					r[i]=d[i-1]-r[i-1];
					sum+=SQR(r[i]);
					if (sgn(r[i])<0){
						ok=false;
						break;
					}
				}
			}
			if (!ok) puts("IMPOSSIBLE");
			else{
				printf("%.2lf\n",PI*sum);
				for (int i=0;i<N;i++)
					printf("%.2lf\n",r[i]);
			}	
		}
		else{
			bool ok=true;
			double sum=0;
			a[0]=1;
			b[0]=0;
			for (int i=1;i<N;i++){
				a[i]=-a[i-1];
				b[i]=d[i-1]-b[i-1];
			}
			if (d[N-1]-b[N-1]!=0)
				ok=false;
			else{
				int left=0,right=d[0];
				int up,down;
				up=0;
				for (int i=1;i<N;i++){
					//0<=a[i]*r0+b[i]<=min(d[i-1],d[i])
					int tmp=min(d[i-1],d[i]);
					if (a[i]==1){
						//0<=r0+b[i]<=tmp
						left=max(left,-b[i]);
						right=min(right,tmp-b[i]);
					}
					else{
						//0<=-r0+b[i]<=tmp
						left=max(left,b[i]-tmp);
						right=min(right,b[i]);
					}
					up+=-a[i]*b[i];
				}
				if (sgn(left-right)>0)
					ok=false;
				down=N;
				double x0=(double)up/down;
				//printf("%.2lf %d %d\n",x0,left,right);
				if (sgn(left-x0)<=0 && sgn(x0-right)<=0){
					r[0]=x0;
				}
				else{
					if (sgn(left-x0)>0)
						r[0]=left;
					else
						r[0]=right;
				}
				sum+=SQR(r[0]);
				for (int i=1;i<N;i++){
					r[i]=d[i-1]-r[i-1];
					sum+=SQR(r[i]);
				}
			}
			if (!ok) puts("IMPOSSIBLE");
			else{
				printf("%.2lf\n",PI*sum);
				for (int i=0;i<N;i++)
					printf("%.2lf\n",r[i]);
			}
		}
	}
	return 0;
}
