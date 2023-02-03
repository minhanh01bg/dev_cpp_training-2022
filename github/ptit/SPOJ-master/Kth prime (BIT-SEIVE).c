#include <stdio.h>
#include<math.h>
int flag[100000001>>6];
#define isc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isf(x) (flag[x>>6] |=(1<<((x>>1)&31)))
int a[5000001];
int main()
 {
    int i,j;
    int  c,q,k;
    for (i=3;i<=10000;i+=2)
    {
        if(!isc(i))
            for(j=i*i;j<=100000000;j+=2*i )
            isf(j);
    }
    c=1;
    a[1]=2;
    for(i=3;i<=100000000;i+=2)
    {
        if(!isc(i))
        {
        ++c;
        a[c]=i;
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&k);
        printf("%d\n",a[k]);
    }
    return 0;
}

