#include <stdio.h>
#include <math.h>
#define pi acos(-1)
int main()
{
    double r, n;
    scanf("%lf %lf", &r, &n);
    while(r!=0 && n!=0)
    {
        printf("%.2lf\n", (r)/(double)(sin(pi/2.0/n)));
        scanf("%lf %lf", &r, &n);
    }
    return 0;
}
