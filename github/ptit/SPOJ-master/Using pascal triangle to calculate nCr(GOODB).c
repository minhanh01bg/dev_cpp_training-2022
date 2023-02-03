#include <stdio.h>
#define MOD 1000000007
long long pas[302][302];
int main(void) {
	long long d;
	int i,j,n,w,t,r;
	pas[0][0]=1;
	pas[1][0]=1;
	pas[1][1]=1;
	for(i=2;i<=300;i++)
	  {
        pas[i][0] = 1;
        for(j=1;j<=i;j++)
        {
           pas[i][j] =(pas[i-1][j-1])%MOD + (pas[i-1][j])%MOD;
        }
    }
    scanf("%d %d %d %d",&n,&w,&t,&r);
    d=(((pas[n][w]*pas[n-w][t])%MOD)*pas[n-(w+t)][r])%MOD;
    printf("%lld\n",d);
	return 0;
}
