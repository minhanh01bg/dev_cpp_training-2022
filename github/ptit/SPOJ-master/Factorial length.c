#include <stdio.h>
#include<math.h>
int main(void)
{
int t;
long long n1;
double n,d;
double pi= 3.14159265358979323;
double e=2.71828182845904523536; //use high precision
scanf("%d",&t);
while(t--)
{
    scanf("%lf",&n);
    if(n==0)
    printf("1\n");
    else
    {
    d=(double)(n*log10((double)(n/e)));
    d=d+(double)(log10(sqrt((double)(2*pi*n))));
    n1=(long long)(d)+1;
    printf("%lld\n",n1);
    }
}
	return 0;
}
