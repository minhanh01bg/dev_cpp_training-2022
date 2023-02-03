#include <stdio.h>
int main(void) {
	int t;
	long long i,n,temp,min,a,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
	min=0;
	temp=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		temp=temp+a;
		if(temp<=0 && temp<min)
			min=temp;
	}
	temp=-(min)+1;
	printf("Scenario #%lld: %lld\n",j,temp);
	}
	return 0;
}
