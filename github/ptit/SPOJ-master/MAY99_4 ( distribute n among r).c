#include<stdio.h>
long mod=10000007;
long long s[101][101];
long long Comb(long long n,long long r)
{
long long ans;
if(n<r)
return 0;
if(s[n][r]!=0)
return s[n][r];
ans=(Comb(n-1,r)+Comb(n-1,r-1))%mod;
s[n][r]=ans;
return ans;
}
int main()
{
    long long n,i,r;
    scanf("%lld %lld", &n, &r);
    if(n<r)
        printf("-1\n");
    else if((n==r)||(r==1))
        printf("1\n");
    else
    {
        for(i=0;i<n;i++)
        s[i][1]=i;
        printf("%lld\n",Comb(n-1,r-1));
    }

return 0;
}

