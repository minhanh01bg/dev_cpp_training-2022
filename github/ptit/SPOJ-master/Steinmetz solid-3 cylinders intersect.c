#include <stdio.h>

int main(void) {
	int t;
	double r,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&r);
		d=16.0-(8.0*sqrt(2.0));
		printf("%.4lf\n",d*r*r*r);
	}
	return 0;
}
