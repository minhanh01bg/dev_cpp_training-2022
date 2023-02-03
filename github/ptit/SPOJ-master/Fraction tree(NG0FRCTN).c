#include <stdio.h>
long long fusc(long long n)   //Dijstra's algo to find fusc(n)
{
long long k=n,a=1,b=0;
while(k>0)
{
  if(k%2==0)
  {
    k=k/2;
    a=a+b;
  }
  else
  {
    k=(k-1)/2;
    b=a+b;
  }
}
return b;
}
int main(void)
{
	long long n,p,q;
	while(scanf("%lld", &n)==1 && n)
	{
		p=fusc(n);
		q=fusc(n+1);
		printf("%lld/%lld\n", p, q);
	}
	return 0;
}
