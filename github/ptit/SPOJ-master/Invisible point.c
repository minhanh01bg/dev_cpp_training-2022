#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    double m;
    scanf("%d",&n);
    while (n--) {
        scanf("%lf",&m);
        printf("%d\n", (int)(ceil((double)(log2(m)))+1.0));
    }
    return 0;
}
