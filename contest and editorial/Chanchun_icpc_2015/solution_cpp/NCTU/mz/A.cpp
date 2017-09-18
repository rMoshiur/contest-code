#include<cstdio>
#include<algorithm>

using namespace std;

int v[10]={1,5,10,20,50,100,200,500,1000,2000};
int w[10]={1,5,10,20,100,100,200,1000,1000,2000};

int greedy(int x, int *c)
{
	int work[10]={c[0]}, r[10]={}, take[10]={};
	int ret=0;
	if(x<0) return -5;
	for(int i = 0; i < 9; i++)
	{
		r[i]=x%(w[i+1]/w[i]);
		x/=w[i+1]/w[i];
	}
	r[9]=x;
	for(int i = 1; i < 10; i++)
	{
		if(i==4 || i==7) c[i+1]+=c[i]>>1;
		else if(i==5 || i==8) 
			work[i]=c[i]+(work[i-2]-r[i-2])/(v[i]/v[i-2]);
		else work[i]=c[i]+(work[i-1]-r[i-1])/(v[i]/v[i-1]);
	}
	for(int i = 0; i < 10; i++) if(r[i]>work[i]) return -5;
	for(int i = 9; i > 0; i--)
	{
		int diff=max(0,r[i]-(work[i]-c[i])), rest=r[i]-diff;
		ret+=diff;
		take[i]=diff;
		if(i==5 || i==8)
		{
			i--;
			int take_half=min(diff,c[i]>>1);
			take[i]=take_half<<1;
			take[i+1]-=take_half;
			ret+=take_half;
			r[i-1]+=rest*5;
		}
		else
		{
			r[i-1]+=(rest)*(v[i]/v[i-1]);
		}
	}
	take[0]=r[0];
	ret+=r[0];
	return ret;
}

int solve()
{
	int ret=-1, p, c[10],copy[10];
	scanf("%d",&p);
	for(int i = 0; i < 10; i++) scanf("%d",&c[i]);
	for(int i = 0; i <= (c[4]?50:0); i+=50)
	{
		for(int j = 0; j <= (c[7]?500:0); j+=500)
		{
			for(int k=0; k < 10; k++) copy[k]=c[k];
			c[4]-=i?1:0;
			c[7]-=j?1:0;
			ret=max(ret,greedy(p-i-j,c)+(i?1:0)+(j?1:0));
			for(int k=0; k < 10; k++) c[k]=copy[k];
		}
	}
	return ret<0?-1:ret;
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	while(ncases--) printf("%d\n",solve());
	return 0;
}
