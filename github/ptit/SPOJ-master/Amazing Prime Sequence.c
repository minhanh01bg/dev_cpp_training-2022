#include <stdio.h>
#include<math.h>
long long stat[10000001];
long long a[10000000];
int main() {
    long t;
    long long i,j;
    long long n;
    a[0]=0;
    a[1]=0;
    for (i=3;i<sqrt(10000001);i+=2)
    {
        if(stat[i]==0)
        {
            for(j=i*i;j<10000001;j+=2*i )
            {
                if(stat[j]==0)
                stat[j]=i;
            }
        }
    }
    scanf("%ld",&t);
    for(i=3;i<10000000;i+=2)
    {
       if(stat[i]==0)
       a[i]=a[i-2]+2+i;
       else
       a[i]=a[i-2]+2+stat[i];
    }
    while(t--)
    {
     scanf("%lld",&n);
     if(n%2==0)
     printf("%lld\n",(a[n-1]+2));
     else
     printf("%lld\n",a[n]);
    }

    return 0;
}

