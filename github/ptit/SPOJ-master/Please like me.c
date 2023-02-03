#include <stdio.h>
#include<math.h>
int main(void) {
	int t;
	double l,d,s,c,a,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %lf %lf",&l,&d,&s,&c);
		if(d==1)
		p=s;
		else
		{
		a=(double)(pow((c+1),(d-1)));
		p=(double)(a*s);
		}
		if(p<l)
		printf("DEAD AND ROTTING\n");
		else
		printf("ALIVE AND KICKING\n");
	}
	return 0;
}
