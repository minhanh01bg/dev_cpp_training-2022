#include <stdio.h>
long long a[65];
int main(void)
 {
    long long i,j,k,t,n;
	for(i=1;i<=64;i++)
    {
     a[i]=1;
     for(j=1;j<=i;j++)
     {
      a[i]=a[i]*(j+9)/j;
     }
    }
    scanf("%lld",&t);
    while(t--)
    {
     scanf("%lld %lld",&k,&n);
     printf("%lld %lld\n",k,a[n]);
    }
	return 0;
}
