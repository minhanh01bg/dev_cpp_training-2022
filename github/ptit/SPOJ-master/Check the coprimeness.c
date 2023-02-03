#include <stdio.h>
long long gcd(long long m,long long n)
{
    if(m==0)
    return n;
    if(n==0)
    return m;
    return gcd(n,m%n);
}
int main(void) {
	int t;
	long long n,i,j;
	int flag;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%lld",&n);
         if(n==1)
         printf("0\n");
         else
         {
		for(i=n/2;i>0;i--)
		{
			if(n%i!=0)
			{
			j=gcd(n,i);
			if(j==1)
			{
			    printf("%lld\n",i);
				break;
			}
			}
			if(i==1)
			printf("%lld\n",i);

		}
         }


	}

	return 0;
}
