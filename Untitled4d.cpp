#include<stdio.h>
int main()
{
	long long int l,r,k;
	scanf("%lld%lld%lld",&l,&r,&k);
	long long int pow=1,count=0;
	if(l==1)
	{
		printf("1 ");
		count++;
	}
	while(r>=pow && pow < 1000000000000000000)
	{
		pow=pow*k;
		if(pow>=l && r>=pow)
		{
			printf("%lld ",pow);
			count++;
		}
	}
	if(count!=0)
		printf("\n");
	if(count==0)
		printf("-1\n");
	return 0;
}
