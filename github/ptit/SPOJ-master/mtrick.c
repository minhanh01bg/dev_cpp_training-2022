#include <stdio.h>
long long a,b,c,arr[1002],val,str,end,k,add;
int d;
char s[1002];
long long multiply(long long a,long long b,long long c)
{
	long long x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
        x=(x+y)%c;
		y=(y+y)%c;
		b=b/2;
	}
	return x%c;
}
int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
		scanf("%lld %lld %lld",&a,&b,&c);
		scanf("%s",&s);
		d=1,str=0,end=n-1,k=1,add=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='R')
              d=-d;
            else if(s[i]=='A')
                add=(add+a%c)%c;
            else
            {
                k=multiply(k,b,c);
                add=multiply(add,b,c);
            }
            if(d==1)
            {
                val=arr[str];
                str++;
            }
            else
            {
                val=arr[end];
                end--;
            }
            val=(multiply(val,k,c)+add)%c;
            printf("%lld ",val);
        }
		printf("\n");
	}
	return 0;
}
