#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *pat;
int *lps;
int main(void)
{
	long l,len,i,j;
	char c;
	while(scanf("%ld",&l)!=EOF)
	{
		pat=(char*)malloc(l*sizeof(char));
		lps=(int*)malloc(l*sizeof(int));
		scanf("%s",pat);
		len=0;
        lps[0]=0;
        i = 1;
    while(i<l)
    {
       if(pat[i]==pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if( len!=0 )
         {
           len = lps[len-1];
         }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
        i=0;
        j=0;
        getchar();
        c=getchar();
		while(c!='\n')
		{
         if(pat[j]==c)
        {
          j++;
          i++;
          c=getchar();
         }
        if (j==l)
        {
        printf("%ld\n",(i-j));
        j=lps[j-1];
        }
       else if(pat[j]!=c)
        {
        if(j != 0)
        {
         j = lps[j-1];
        }
        else
        {
           i=i+1;
           c=getchar();
        }
        }
    }
    printf("\n");
	}
	return 0;
}
