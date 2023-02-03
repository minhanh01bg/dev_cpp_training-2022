#include <stdio.h>
#include<math.h>
long flag[10000001];
int main()
 {
    long i,j,c,n;
    for (i=3;i<=sqrt(10000000);i+=2)
    {
        if(!flag[i])
        {
            flag[i]=i;
            for(j=i*i;j<=10000000;j+=2*i )
            {
                if(!flag[j])
                flag[j]=i;
            }
        }
    }
    while(scanf("%ld",&n)!=EOF)
    {
       printf("1");
       if(n%2==0)
       {
           while(n%2==0)
           {
               printf(" x 2");
               n=n/2;
           }
       }

               while(n>1 && flag[n] && (n%flag[n])==0)
               {
                  printf(" x %ld",flag[n]);
                  n=n/flag[n];
               }
               if(n>1 && !flag[n])
               printf(" x %ld",n);
           printf("\n");
       }
       return 0;
    }



