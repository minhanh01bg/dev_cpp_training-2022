#include <stdio.h>

int main(void) {
	long n,m;
	double d;
	scanf("%ld %ld",&n,&m);
	while(n!=0 || m!=0)
	{
		if(n>m)
		printf("0.000000\n");
		else
		{
		d=(double)(1.0-(n/(m+1.0)));
		printf("%.6lf\n",d);
		}
		scanf("%ld %ld",&n,&m);
	}
	return 0;
}
