#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
double me[11000];
int x[11000],y[11000];
double dis[11000];
double r[11000];
double two(double r)
{
	return r*r;
}
int main()
{
	int i,j,k;
	int n,T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		for(i=0;i<n;i++)
		{
			j=(i+1)%n;
			dis[i]=sqrt(two(x[i]-x[j]) + two(y[i]-y[j]));
			//cout<<dis[i]<<' ';
		}
		//cout<<endl;
		for(i=0;i<n;i++)
		{
			me[i] = min(dis[i],dis[(i+n-1)%n]); 
		}
		if(n%2 == 1)
		{
			double sum=0;
			for(i=0;i<n;i++)
			{
		//		cout<<dis[i]<<' ';
				sum+=dis[i];
			}
		//	cout<<endl;
			sum/=2.0;
//			cout<<sum<<endl;
			for(i=1;i<n;i+=2)
			{
				sum-=dis[i];
			}
			r[0]=sum;
//			cout<<sum<<endl;
			bool f=(r[0]>=0);
			for(i=1;i<n;i++)
			{
				r[i]=dis[i-1]-r[i-1];
				if(r[i] < -0.001)
				{	
					//cout<<i<<" dfd "<<r[i]<<endl;
					f=false;break;
				}
			}
			if(f)
			{
				double ans=0;
				for(i=0;i<n;i++)
				{
					ans+=two(r[i]);
				}
				printf("%.2lf\n",(ans*acos(0.0)));
				for(i=0;i<n;i++)
				{
					printf("%.2lf\n",r[i]);
				}
			}else
			{
				cout<<"IMPOSSIBLE\n";
			}
		}else
		{
			double sum=0;
			for(i=0;i<n;i+=2)
			{
				sum+=dis[i];
			}
			for(i=1;i<n;i+=2)
			{
				sum-=dis[i];
			}
			if(sum!=0)
			{
				cout<<"IMPOSSIBLE\n";
				continue;
			}
			sum=0;
			double u = me[0];
			double d = 0;
			double now = 0 ;
			for(i=1;i<n;i++)
			{
				if(i%2==1)
				{
					u = min(u,dis[i-1]+now);
					d = max(d,dis[i-1]+now-me[i]);
					now+=dis[i-1];
				}else
				{
					u = min(u,now-dis[i-1]+me[i]);
					d = max(d,now-dis[i-1]);
					now-=dis[i-1];
				}
			}
			//cout<<u<<' '<<d<<endl;
			if(u<d-0.00001)
			{
				cout<<"IMPOSSIBLE\n";
				continue;
			}
			double ans=0;
			for(i=0;i<n-1;i++)
			{
				double tmp = (n-1-i)*dis[i];
				if(i%2==0)
				{
					ans-=tmp;
				}else
				{
					ans+=tmp;
				}
			}
			ans/=(double)n;ans=-ans;
			//cout<<ans<<endl;
			if(ans>d && ans<u)
			{
				r[0]=ans;
			}else
			{
				if(ans<d)
				{
					r[0]=d;
				}else
				{
					r[0]=u;
				}
			}
			double area=two(r[0]);
			bool f=true;
			for(i=1;i<n;i++)
			{
				r[i]=dis[i-1]-r[i-1];
				if(r[i]<-0.0001)f=false;
				
				area+=two(r[i]);
			}
			if(!f)
			{
				cout<<"IMPOSSIBLE\n";
				continue;
			}
			printf("%.2lf\n",area*acos(0));
			//cout<<(area/2.0)*3.1415926<<endl;
			for(i=0;i<n;i++)
			{
				
				printf("%.2lf\n",r[i]);
			}
		}
	}
}




