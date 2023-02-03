#include <stdio.h>
int color[101];
int sum[101][101];
int dp[101][101];
const int INF = 0x7f7f7f7f;
int solve(int a, int b)
{
    int i,smoke,ret=INF;
    if(dp[a][b]>-1)
    return dp[a][b];
        for(i=a;i<b;++i)
        {
            smoke= sum[a][i] * sum[i+1][b] + solve(a,i) + solve(i+1,b);
            if(smoke<ret)
            ret=smoke;
        }
        return dp[a][b]=ret;
    }

int main(void) {
	int n,d,i,j;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
		scanf("%d",&color[i]);
        sum[i][i]=color[i];
		}

		for(i=0;i<n;i++)
		{
		    dp[i][i]=0;
		    for(j=i+1;j<n;j++)
		    {
		        sum[i][j]=(sum[i][j-1]+color[j])%100;
		        dp[i][j]=-1;
		    }

		}
		d=solve(0,n-1);
		printf("%ld\n",d);
	}

	return 0;
}
