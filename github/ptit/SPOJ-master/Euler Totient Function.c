#include <stdio.h>
long fi(long n)
     {
       long i,result = n;
       for(i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }
int main(void) {
	int t;
	long n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("%ld\n",fi(n));
	}
	return 0;
}
