#include <stdio.h>
long f[13];
int main(void) {
	int i,n,k,l;
    long s;
    f[0]=1;
    for(i=1;i<13;i++)
    f[i]=f[i-1]*i;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
     s=1;
     for(i=1;i<=k;i++)
     {
       scanf("%d",&l);
       s=s*f[l];
     }
      printf("%ld\n",(f[n]/s));
    }
	return 0;
}
