#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long n;
        scanf("%ld", &n);
        printf("%.8f\n", sqrt(4.0*double(n+1)/n+1.0/n/n));
    }
    return 0;
}
