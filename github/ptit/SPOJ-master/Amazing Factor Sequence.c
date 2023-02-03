#include <stdio.h>
#include<math.h>
long long stat[1000001];
long long a[1000000];
int main() {
    long t;
    long long i,j;
    long long n;
    a[0]=0;
    a[1]=0;
    for (i=1;i<1000000;i++)
    {
        a[i]=a[i-1]+stat[i];
            for(j=2*i;j<1000000;j+=i )
            {
                stat[j]+=i;
            }
        }
    scanf("%ld",&t);
    while(t--)
    {
     scanf("%lld",&n);
     printf("%lld\n",a[n]);
    }

    return 0;
}

