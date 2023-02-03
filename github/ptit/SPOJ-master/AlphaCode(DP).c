#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char c[5000];
long long cnt[5000];
int main(void) {
	long long d,i=0,len;
	char c1;
	while(1)
	{
    i=0;
    c1=getchar();
	while(c1!='\n')
	{
	    c[i]=c1;
	    i++;
	    c1=getchar();
	}
	if(c[0]=='0')
	exit(0);
	len=i;
    cnt[0]=1;
    cnt[1]=1;
    for(i=1;i<len;i++)
    {
        if(((c[i]-'0'+(c[i-1]-'0')*10)>26)||(c[i-1]=='0'))
            cnt[i+1]=cnt[i];
        else if (c[i]=='0')
            cnt[i+1]=cnt[i-1];
        else
            cnt[i+1]=cnt[i]+cnt[i-1];
    }
		printf("%lld\n",cnt[i]);
	}
	return 0;
}


