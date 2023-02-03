#include <stdio.h>
#include<string.h>
int main()
{
	long ret,j;
	char buf[256];
    gets(buf);
    int t=atoi(buf);
	while(t--)
	{
		gets(buf);
		ret=1;
		for(j=1;j<strlen(buf);j++)
		{
         if(buf[j]==buf[j-1])
            ret*=2;
		}
		 printf("%ld\n", ret);
	}
	return 0;
}
