#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int max(int x,int y)
{
    return (x>y)?x:y;
}
int min(int x,int y)
{
    return (x<y)?x:y;
}
int main(void) {
	int t;
    int r1x1,r1y1,r1x2,r1y2,r2x1,r2y1,r2x2,r2y2,x5,x6,y5,y6;
    long area;
    scanf("%d",&t);
    while(t--)
    {
     scanf("%d %d %d %d",&r1x1,&r1y1,&r1x2,&r1y2);
     scanf("%d %d %d %d",&r2x1,&r2y1,&r2x2,&r2y2);
     area=abs((r1x2-r1x1)*(r1y2-r1y1))+abs((r2x2-r2x1)*(r2y2-r2y1));
     area=area-max(0, min(r1x2,r2x2) - max(r1x1,r2x1)) * max(0, min(r1y2,r2y2) - max(r1y1,r2y1));
     printf("%ld\n",area);
    }
	return 0;
}
