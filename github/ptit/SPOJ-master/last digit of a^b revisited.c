#include<stdio.h>
int ch[]={6,2,4,8,1,3,9,7,1,7,9,3,6,8,4,2,1,9,6,4};
int main()
{
 int t,a,i,j;
 long long b;
 char c,c1;
scanf("%d",&t);
while(t--)
{
  c=getchar();
  while((c=getchar())!=' ')
   c1=c;
   a=(int)(c1-'0');
  scanf("%lld",&b);
  a=a%10;
  i=b%4;
  j=b%2;
  if(b==0)
  printf("1\n");
  else if(a==0 || a==1 || a==5 || a==6 )
   printf("%d\n",a);
   else if(a==2)
    printf("%d\n",ch[i]);
   else if(a==3)
    printf("%d\n",ch[4+i]);
   else if(a==4)
    printf("%d\n",ch[18+j]);
   else if(a==7)
    printf("%d\n",ch[8+i]);
   else if(a==8)
   printf("%d\n",ch[12+i]);
   else
   printf("%d\n",ch[16+j]);
}
  return(0);
}
