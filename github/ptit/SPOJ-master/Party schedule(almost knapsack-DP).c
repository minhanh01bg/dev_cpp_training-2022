#include<stdio.h>
long V[101];
long W[101];
long pack[101][501];
long max(long a,long b)
{
    return (a>b)?a:b;
}
int main()
{
    long K,N,i,j;
    while(scanf("%ld %ld", &K, &N)==2)
    {
    if(K==0 && N==0)
    break;
    for (i=0;i<N;i++)
        scanf("%ld %ld",&W[i],&V[i]);
    for (i=0; i<=N; i++)
    {
        for (j=0; j<=K; j++)
        {
            if(i==0 || j==0)
               pack[i][j]=0;
            else if (W[i-1]<=j)
                pack[i][j]=max(pack[i-1][j],(V[i-1] + pack[i-1][j-W[i-1]]));
            else
                pack[i][j]=pack[i-1][j];
        }
    }
    j=pack[N][K];
    for(i=K;i>0;i--)
    {
        if(pack[N][i]<j)
        break;
    }
    printf("%ld %ld\n",i+1,pack[N][K]);
    }
    return 0;
}
