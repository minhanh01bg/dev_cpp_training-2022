#include<stdio.h>
long long MOD=1000000007;
long long f[1000001];
long long power(long long a,long long b)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%MOD;
        y =(y*y)%MOD;
        b/= 2;
    }
    return x;
}
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n)
{
    return power(n,MOD-2);
}

long long Comb(long long n,long long r)
{
    return (f[n]*((InverseEuler(f[r])*InverseEuler(f[n-r])) % MOD)) % MOD;
}
int main()
{
    long long i,r,n;
    int t;
    f[0]=1,f[1]=1;
    for(i=2;i<=1000000;i++)
     f[i]=(f[i-1]*i)%MOD;
     scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&r);
        printf("%lld\n",Comb(n+r-2,n-1));
    }
return 0;
}

