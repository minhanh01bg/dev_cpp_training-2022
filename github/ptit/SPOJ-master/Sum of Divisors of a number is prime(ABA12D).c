#include<stdio.h>
#include<math.h>
long flag[]={0,2,4,9,16,25,64,289,729,1681,2401,3481,4096,5041,7921,10201,15625,17161,27889,28561,29929,65536,83521,85849,146689,262144,279841,458329,491401,531441,552049,579121,597529,683929,703921,707281,734449,829921,1190281};
long binary(long a[],long m,long l,long u){
     long mid;
     if(l<=u)
     {
          mid=(l+u)/2;
          if(a[mid]<=m && a[mid+1]>m)
              return mid;
          else if(a[mid]>m && a[mid-1]<=m)
              return (mid-1);
          else if(a[mid]>m)
              return binary(a,m,l,mid-1);
          else
              return binary(a,m,mid+1,u);
     }
       return 0;
}
long bin(long a[],long m,long l,long u){
     long mid;
     if(l<=u)
     {
          mid=(l+u)/2;
          if(a[mid]==m)
          return (mid-1);
          else if(a[mid]<m && a[mid+1]>m)
              return mid;
          else if(a[mid]>m && a[mid-1]<m)
              return (mid-1);
          else if(a[mid]>m)
              return bin(a,m,l,mid-1);
          else
              return bin(a,m,mid+1,u);
     }
       return 0;
}
int main()
{
 int t;
 long a,b,d;
scanf("%d",&t);
while(t--)
{
  scanf("%ld %ld",&a,&b);
  d=binary(flag,b,0,38)-bin(flag,a,0,38);
  printf("%ld\n",d);
}
  return(0);
}
