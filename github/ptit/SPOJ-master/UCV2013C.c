#include <stdio.h>
int main()
{
    long long d,f,b,m;
    scanf("%lld %lld %lld %lld", &d, &f, &b, &m);
    while (d!=0 && f!=0 && b!=0 && m!=0)
     {
        long long p=1+f*(f+1)/2;
        if (d>(b*p+m))
            printf("Farmer Cream will have %lld Bsf to spend.\n", d-b*p);
        else
            printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", b*p+m-d);
        scanf("%lld %lld %lld %lld", &d, &f, &b, &m);
    }
    return 0;
}
