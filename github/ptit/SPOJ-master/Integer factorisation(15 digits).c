#include <stdio.h>

int main(void) {
	long long n,i,d,c;
	scanf("%lld",&n);
	while(n!=0)
	{
		for(i=2;i*i<=n;i++)
		{
               c=0;
			if(n%i==0)
			{
				while(n%i==0)
				{
					c++;
					n=n/i;
				}
			printf("%lld^%lld ",i,c);
			}
			if(n==1)
			break;
		}
		if(n>1)printf("%lld^1",n);
        printf("\n");
		scanf("%lld",&n);
	}
	return 0;
}
