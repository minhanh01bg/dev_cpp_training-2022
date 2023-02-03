#include <stdio.h>
char stat[10001];
int main() {
    int i,j;
    stat[2]=1;
    for (i=3;i<=100;i+=2)
    {
        if(stat[i]==0 )
        {
            for(j=i*i;j<=10000;j+=2*i )
            {
                stat[j] = 1;
            }
        }
    }

    printf("2\n");
    for(i=3;i<=10000;i+=2)
    {
        if(stat[i]==0)
        printf("%d\n",i);
    }
    return 0;
}

