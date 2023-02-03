#include<stdio.h>
#include<math.h>
long long seq_dp(long n,long x)
{
long long y;
if(n==0)
return 0;
if(n==1)
return 1;
if(x==2 || x==0)
y=seq_dp(n-1,1) + seq_dp(n-1,0);
else
y=seq_dp(n-1,1) + seq_dp(n-1,2) + seq_dp(n-1,0);
return y;
}
int main()
{
 long n;
 long long d=0;
scanf("%ld",&n);
  d=d + seq_dp(n,2) +seq_dp(n,1) + seq_dp(n,0);
  printf("%lld\n",d);
  return(0);
}
