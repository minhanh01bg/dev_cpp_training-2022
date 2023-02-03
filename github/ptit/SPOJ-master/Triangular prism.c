#include<stdio.h>
#include<math.h>
int main()
{
    double v,s;
    int t;
     scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&v);
        s=3.0*sqrt(3.0)*0.5*pow((16.0*v*v),(1/3.0));
        printf("%.10lf\n",s);
    }
return 0;
}

