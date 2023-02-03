#include<stdio.h>
#include<math.h>
int main()
{
 int a[101];
 int t;
  int n,d,max,qmax,i,j;
scanf("%d",&t);
while(t--)
{
    for(i=0;i<101;i++)
    a[i]=0;
    max=0;
    qmax=-1;
  scanf("%d",&n);
  int b[n];
  i=0;
  j=n;
  while(j--)
  {
      scanf("%d",&d);
      if(a[d]==0)
      {
        b[i]=d;
         i++;
      }
      ++a[d];
  }
    for(j=0;j<i;j++)
    {
        if(a[b[j]]%b[j]==0)
        {
            if(a[b[j]]>max)
            {
               max=a[b[j]];
               qmax=b[j];
            }
            else if(a[b[j]]==max && b[j]<qmax)
             qmax=b[j];

        }
    }
    printf("%d\n",qmax);
}
  return(0);
}
