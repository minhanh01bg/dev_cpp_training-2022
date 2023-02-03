#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define lli long long int

lli dp[51][51][51];

lli bar(int n, int k, int m);

int main()
{
    memset(dp,-1,sizeof dp);

    int te, ti, n, k, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d %d", &n, &k, &m);
        printf("Case %d: %lld\n", te, bar(n,k,m));
    }
    return 0;
}

lli bar(int n, int k, int m)
{
    if(k<0) return 0;
    if(n == 0)
    {
        if(k==0) return 1;
        return 0;
    }

    lli & res = dp[n][k][m];
    if(res != -1) return res;
    lli ret = 0;

    for(int i = 1; i <= m && i <= n; i++)
        ret += bar(n-i,k-1,m);
    return res = ret;
}

