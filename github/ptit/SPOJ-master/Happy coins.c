#include <stdio.h>
#include<string.h>
char s[3];
int main(void) {
long t,n,i,j;
scanf("%ld",&t);
while(t--)
{
j=0;
scanf("%ld",&n);
for(i=0;i<n;i++)
{
scanf("%s",&s);
if(strcmp(s,"lxh")==0)
j=j^1;
else
j=j^0;
}
if(j==1)
printf("lxh\n");
else
printf("hhb\n");
}
	return 0;
}
