#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int main()
{
    int tN;
    double p0,p1,t,p;
    scanf("%d", &tN);
    for (int i=0; i<tN; i++)
    {
        scanf("%lf %lf %lf %lf", &p0, &p1, &t, &p);
        printf("Scenario #%d: %.2lf\n", i+1,((double)log(p)-(double)log(p0))*t/((double)log(p1)-(double)log(p0)));
    }
    return 0;
}
