#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long gcd(long m,long n)
{
    if(m==0)
    return n;
    if(n==0)
    return m;
    return gcd(n,m%n);
}
int main()
{
    long t,m,n,d,i,j,c;
    scanf("%ld",&t);
    while(t--)
    {
        c=0;
      scanf("%ld %ld",&m,&n);
      d=gcd(m,n);
      for(i=1;i<=sqrt(d);i++)
      {
          if(d%i == 0)
          {
          c=c+2;
          if(i==(d/i))
          c--;
          }
      }
      printf("%ld\n",c);
    }
    return(0);
}
