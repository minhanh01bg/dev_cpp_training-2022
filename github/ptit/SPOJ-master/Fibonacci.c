#include<stdio.h>
long long a[100];
int bin(long long a[],long long m,int l,int u){

     int mid,c=0;
     if(l<=u)
     {
          mid=(l+u)/2;
          if(m==a[mid])
              return 1;
          else if(m<a[mid])
              return bin(a,m,l,mid-1);
          else
              return bin(a,m,mid+1,u);
     }
       return 0;
}
int main()
{
    int flag,i;
    long t;
    long long n;
    a[0]=0;
    a[1]=1;
    i=2;
    while(a[i-1]<=10000000000LL)
    {
      a[i]=a[i-1]+a[i-2];
      ++i;
    }
    scanf("%lld",&t);
    while(t--)
    {
      scanf("%lld",&n);
      flag=bin(a,n,0,i-1);
      if(flag==1)
      printf("IsFibo\n");
      else
      printf("IsNotFibo\n");
    }

}
