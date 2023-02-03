#include <stdio.h>
#include <string.h>
char v[1100000];
long d[1000001];
int main() {
   long q;
   long i,j,a,b,c;
   long non_self = 0;
   for(i=3;i<=1000;i=i+2)
    {
            for(j=i*i;j<1000000;j+=2*i )
            {
                v[j]=1;
            }
    }
    c=1;d[0]=1;
    v[1]=1;
  for(i=1; i < 1000000; ++i) {
      if(i%2==0)
      v[i]=1;
      if(!v[i])
          ++c;
      d[i]=c;
    non_self = i + (i%10) + (i/10)%10 + (i/100)%10 + (i/1000)%10 + (i/10000)%10 +(i/100000)%10;
    v[non_self] = 1;
  }
  d[1000000]=c;

scanf("%ld",&q);
while(q--)
{
c=0;
scanf("%ld %ld",&a,&b);
if(a==0)
a=1;
printf("%ld\n",d[b]-d[a-1]);
}
   return 0;
}
