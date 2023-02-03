#include<stdio.h>
#include <math.h>
#define pi 3.1415926
int main()
{
    int l;
    double ret;
    scanf("%d",&l);
    while(l>0)
    {
        ret=(double)(l*l)/(pi*2.0);
        printf("%.2f\n",ret);
        scanf("%d",&l);
    }
	return 0;
}
