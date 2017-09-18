#include<bits/stdc++.h>
using namespace std;
#define FZ(i,n) for(int i=0;i<(n);i++)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define PA(a,n) FZ(_1,n)printf("%d%c",(a)[_1],_1==(n)-1?10:32)
#define ePA(a,n) FZ(_2,n)fprintf(stderr,"%d%c",(a)[_2],_2==(n)-1?10:32)

#define RS(x) scanf("%s",x)
#define PS(x) printf("%s",x)
#define ePS(x) fprintf(stderr,"%s",x)

#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define PA64(a,n) FZ(_1,n)printf("%I64d%c",(a)[_1],_1==(n)-1?10:32)
#define ePA64(a,n) FZ(_2,n)fprintf(stderr,"%I64d%c",(a)[_2],_2==(n)-1?10:32)

#define FIR first
#define SEC second
#define pritnf printf
#define N (1<<16)
typedef long long int lnt;
typedef double dou;
int gethash(int*lj,int mx){
	const lnt amod=1000000007;
	lnt sum=0,tmp=233ll;
	for(int i=1;i<mx;i++){
		sum=(sum+tmp*lj[i])%amod;
		tmp=tmp*233ll%amod;
	}
	return (int)sum;
}
////////////
int n;
int lj[N],rj[N];
int a[N],s[N],box[N],C[N];
int stk[N]={-2};
void sol(int uuu){
	s[0]=a[0];
	FZ(i,n)if(i)s[i]=s[i-1]+a[i];
	a[n]=1;
	int mx=s[n-1]+1;
	FZ(i,mx)box[i]=0;
	box[0]=1;
	FZ(i,n)box[s[i]]++;
	for(int i=n-1;i>=0;i--){
		C[s[i]]=i+2;
	}
	C[0]=1;
	{
		int j=0;
		FZ(i,n){
			if(a[i]){
				a[j++]=a[i];
			}
		}
		a[j]=1;
	}
	for(int i=1;i<mx;i++){
		lnt ans1=0;
		{
			int j=-1,sss=0;
			for(;sss+i<mx;){
				ans1+=1ll*box[sss]*box[sss+i];
				sss+=a[++j];
			}
		}
		if(ans1==0){
			lj[i]=rj[i]=0;
			continue;
		}
		ans1=(ans1+1)/2;
		{
			int j=-1,sss=0;
			for(;sss+i<mx;){
				if(ans1>1ll*box[sss]*box[sss+i]){
					ans1-=1ll*box[sss]*box[sss+i];
				}
				else{
					lj[i]=C[sss+0]-0+(ans1-1)/box[sss+i];
					rj[i]=C[sss+i]-1+(ans1-1)%box[sss+i];
					break;
				}
				sss+=a[++j];
			}
		}
	}
	//FZ(i,mx)fprintf(stderr,"%d%c",lj[i],i==mx-1?10:32);
	//////////////
	int ha=gethash(lj,mx);
	int hb=gethash(rj,mx);
	printf("%d %d\n",ha,hb);
}
void input(){
	RI(n);
	FZ(i,n)RI(a[i]);
}
#define MAXT 1000000000
#include<time.h>
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data5.out","w",stdout);
	int allt=0;
	int t;
	if(RI(t)!=EOF){
		assert(1<=t&&t<=MAXT);
		for(int ti=1;ti<=t;ti++){
			int ssst=clock();
			input();
			sol(ti);
			fprintf(stderr,"end %d with %d\n",ti,(int)(clock()-ssst));
			allt+=(int)(clock()-ssst);
		}
	}
	fprintf(stderr,"allt=%d\n",allt);
	return 0;
}

