#include<iostream>
#include<stdio.h>
using namespace std;
int a[100100];
int main()
{
	int n,t;
	int inow,dnow;
	int i,j,k;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",a+i);
		}
		int fr,back;
		fr=0;
		back=n-1;
		while(fr<n-1)
		{
			if(a[fr]>a[fr+1])break;
			fr++;
		}
		while(back>0)
		{
			if(a[back]<a[back-1])break;
			back--;
		}
		if(fr==n-1)
		{
			cout<<"YES\n";
			continue;
		}
		if(fr+1==back)
		{
			if(back==n-1 || a[fr]<=a[back+1])
			{
				cout<<"YES\n";
				continue;
			}else if(fr==0 || a[fr-1]<=a[back])
			{
				cout<<"YES\n";
				continue;
			}
		}
		fr=0;
		back=n-1;
		while(fr<n-1)
		{
			if(a[fr]<a[fr+1])break;
			fr++;
		}
		while(back>0)
		{
			if(a[back]>a[back-1])break;
			back--;
		}
		if(fr==n-1)
		{
			cout<<"YES\n";
			continue;
		}
		if(fr+1==back)
		{
			if(back==n-1 || a[fr]>=a[back+1])
			{
				cout<<"YES\n";
				continue;
			}else if(fr==0 || a[fr-1]>=a[back])
			{
				cout<<"YES\n";
				continue;
			}
		}
		cout<<"NO\n";
	}
}
