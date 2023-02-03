#include <stdio.h>
#include<math.h>
#define pi 3.14159265359
long stirling(long b,long a)
{
	long i;
	double fac,pow;
	for(i=b;;i--)
	{
		fac=i*log(i)-i+(log(2*pi*i))/2;
        pow=i*log(a);
        if(fac<pow)
        return (i+1);
	}
	return 0;
}
int main(void) {
	long t;
	double a,b;
	long n,d;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%lf",&a);
		b=(double)(a*2.71828182846);
		d=(long)b;
		n=stirling(d,a);
		printf("%ld\n",n);
	}
	return 0;
}
