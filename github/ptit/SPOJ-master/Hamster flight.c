#include <stdio.h>
#include<math.h>
#define pi2 1.57079632679

int main(void) {
	int t;
	int v,k1,k2;
	double ang,d,f,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&v,&k1,&k2);
		if(k2==0)
		ang=(double)(pi2-pi2/2.0);
		else
		{
		ang=(double)(4.0*k1/k2);
		ang=(double)(pi2-(0.5*atan(ang)));
		}
		d=(double)(16.0*k1*k1)/(sqrt((k2*k2)+(16.0*k1*k1)));
		f=(double)(k2*k2)/(sqrt((k2*k2)+(16.0*k1*k1)));
		s=(v*v/40.0)*(k2+d+f);
		printf("%.3lf %.3lf\n",ang,s);
	}
	return 0;
}
