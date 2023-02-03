#include<stdio.h>
long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int t;
    long long a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &a, &b);
        c=gcd(a, b);
        printf("%lld %lld\n", b/c, a/c);
    }
    return 0;
}
