#include <stdio.h>
#include<math.h>
#include<stdlib.h>
long b[6000000];
int flag[100000001>>6];
#define isc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isf(x) (flag[x>>6] |=(1<<((x>>1)&31)))
long binary(long a[],long m,long l,long u){

     long mid,c=0;

     if(l<=u){
          mid=(l+u)/2;
          if(m>=99999989)
          return u;
          if((m==a[mid]) || ((a[mid]<m) && (a[mid+1]>m))){
              return mid;
          }
          else if(a[mid]>m && a[mid-1]<m){
          return (mid-1);
          }
          else if(m<a[mid]){
              return binary(a,m,l,mid-1);
          }
          else
              return binary(a,m,mid+1,u);
     }
     else
       return 0;
}

int main()
 {
    long c,k,i,j;
    double temp,temp1;
    for (i=3;i<=10000;i+=2)
    {
        if(!isc(i))
            for(j=i*i;j<=100000000;j+=2*i )
            isf(j);
    }

    b[0]=0;
    b[1]=0;
    b[2]=1;
    c=1;
    for(i=3;i<=100000000;i+=2)
    {
        if(!isc(i))
        {
             ++c;
             b[c]=i;
        }
    }
    while(1)
    {
        scanf("%ld",&k);
        if(k==0)
        exit(0);
        temp=(double)(k/log(k));
        temp1=(double)(binary(b,k,0,c));
        if(temp>temp1)
        temp=(double)(temp-temp1);
        else
        temp=(double)(temp1-temp);
        temp=(double)((temp/temp1)*100.0);
        printf("%.1lf\n",temp);
    }
    return 0;
}

