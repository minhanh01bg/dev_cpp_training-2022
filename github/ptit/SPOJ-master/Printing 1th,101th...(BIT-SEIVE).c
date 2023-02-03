#include <stdio.h>
#include<math.h>
int flag[100000001>>6];
#define isc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isf(x) (flag[x>>6] |=(1<<((x>>1)&31)))
int main()
 {
    int i,j;
    int  c;
    for (i=3;i<=10000;i+=2)
    {
        if(!isc(i))
            for(j=i*i;j<=100000000;j+=2*i )
            isf(j);
    }
    printf("2\n");
    c=1;
    for(i=3;i<=100000000;i+=2)
    {
        if(!isc(i))
        {
        ++c;
        if(c%100==1)
        printf("%ld\n",i);
        }
    }
    return 0;
}

