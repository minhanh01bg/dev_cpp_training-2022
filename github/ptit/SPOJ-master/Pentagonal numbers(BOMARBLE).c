#include <stdio.h>

int main(void) {
	int n;
	long long d;
	scanf("%d",&n);
	while(n!=0)
	{
		d=((3*(n+1)*(n+1))-(n+1))/2;
		printf("%lld\n",d);
		scanf("%d",&n);
	}
	return 0;
}
