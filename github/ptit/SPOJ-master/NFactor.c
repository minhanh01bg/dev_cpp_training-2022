#include<stdio.h>
long prime[1000001];
long nfac[11][1000001];
int main()
{
    long i,j,t,a,b,n;
    for(i=2;i<=1000000;i+=2)
    prime[i]=1;
    for (i=3;i<=1000000;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i;j<=1000000;j+=i )
            {
                prime[j]++;
            }
        }
    }
    for(i=1;i<=1000000;i++)
    {
     for(j=0;j<11;j++)
     {
         if(prime[i]==j)
          nfac[j][i]=nfac[j][i-1]+1;
          else
          nfac[j][i]=nfac[j][i-1];
     }
    }
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld %ld",&a,&b,&n);
        printf("%ld\n",nfac[n][b]-nfac[n][a-1]);
    }

    return 0;
}

