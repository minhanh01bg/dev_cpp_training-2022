#include <stdio.h>

int main(void) {
	long long t,n,k,t1,f;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&n,&k,&t1,&f);
		t1=((f*k)-n)/(k-1);
		printf("%lld\n",t1);
	}
	return 0;
}
