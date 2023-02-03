#include<stdio.h>
#include<math.h>
long long seq_dp(long n)
{
long long y=0;
long i;
if(n<=1)
return 1;
for(i=2;i<=n;i++)
y+=seq_dp(n-i);
return y;
}
int main()
{
 int t;
 long n,i;
 long long d=0;
scanf("%d",&t);
while(t--)
{
  d=0;
  scanf("%ld",&n);
  for(i=1;i<=n;i++)
  d=d+seq_dp(i);
  d=d+1;
  printf("%lld\n",d);

}
   return(0);
}
