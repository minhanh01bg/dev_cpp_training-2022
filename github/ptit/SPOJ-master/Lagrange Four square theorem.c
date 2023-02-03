#include<stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 1 << 15;
int sqr[192], ways[1<<15];

int main()
{
	int n, i, j, k, l;
	for(i = 0; i < 192; i++)
        sqr[i] = i*i;
	for(i = 0; 4*sqr[i] < MAX; i++)
		for(j = i; sqr[i]+3*sqr[j] < MAX; j++)
			for(k = j; sqr[i]+sqr[j]+2*sqr[k] < MAX; k++)
				for(l = k; sqr[i]+sqr[j]+sqr[k]+sqr[l] < MAX; l++)
					ways[sqr[i]+sqr[j]+sqr[k]+sqr[l]]++;
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%d\n",ways[n]);
        scanf("%d",&n);
    }
	return 0;
}
