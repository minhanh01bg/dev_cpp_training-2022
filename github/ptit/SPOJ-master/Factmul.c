#include <stdio.h>
#define MOD 109546051211LL;
long long f=1;
long long multmod(long long a,long long b)
{
long long x=0,y=a;
while(b>0)
{
if(b%2 == 1)
{
x = (x+y)%MOD;
}
y = (y*2)%MOD;
b /= 2;
}
return x%MOD;
}
int main(void)
{
long long i,k=1,n;
scanf("%lld",&n);
    if( n>=587117)
    printf("0\n");
    else
{
    for(i=2;i<=n;i++)
{
        f=multmod(f,i);
        k=multmod(k,f);
}
    printf("%lld\n",k);
}
	return 0;
}
