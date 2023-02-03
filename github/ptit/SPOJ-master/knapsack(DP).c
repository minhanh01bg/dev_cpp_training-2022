#include<stdio.h>
long V[500];
long W[500];
long pack[500][2000];
long max(long a,long b)
{
    return (a>b)?a:b;
}
int main()
{
    long K,N,i,j;
    scanf("%ld %ld", &K, &N);
    for (i=0;i<N;i++)
        scanf("%ld %ld",&V[i],&W[i]);
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
    printf("%ld\n",pack[N][K]);
    return 0;
}
