#include <stdio.h>
int a[10000];
int main(void) {
	int n,d,m,b,c,s;
	scanf("%d",&n);
	d=n;
	c=0;
	while(d--)
	{
		scanf("%d",&b);
		if(a[b]==1)
		c--;
		else
		a[b]=1;
		scanf("%d",&m);
		b=m;
		while(b--)
		{
			scanf("%d",&s);
			if(a[s]!=1)
			{
				a[s]=1;
				c++;
			}
		}
	}
	printf("%d\n",c);

	return 0;
}
