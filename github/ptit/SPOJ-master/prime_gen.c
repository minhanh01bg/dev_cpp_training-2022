#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long prime[10000];
void pre_primes(){
     long long isprime[32000],primes;
     long long i,j;
     for(i=2;i<32000;i++) isprime[i]=1;
     for(i=2;i*i < 32000;i++)if(isprime[i])
     {
         for(j=2*i;j<32000;j+=i) isprime[j]=0;
     }
     primes=0;
     for(i=2;i<32000;i++)
        if(isprime[i])
            prime[primes++]=i;
}
int main()
{
    int t;
    long long m,n,i,j,flag;
    scanf("%d",&t);
    pre_primes();
    while(t--)
    {
        flag=0;
        scanf("%lld %lld",&m,&n);
        if(m==1)
        m++;
        for(i=m;i<=n;i=i++)
         {
             flag=0;
                for(j=0;prime[j]<=sqrt(i);j++)
                {
                    if((i%prime[j])==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                printf("%lld\n",i);
          }
        }
    return(0);
}
