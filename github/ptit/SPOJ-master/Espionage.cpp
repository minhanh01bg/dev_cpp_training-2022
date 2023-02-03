#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	int T,i=1,j;
	scanf("%d",&T);
	while(T--)
	{
		int N, R;
		scanf("%d%d",&N,&R);
		bool spying = true;
		set<int> S, C;
		for(j=0;j<R;j++)
		{
			int R1, R2;
			scanf("%d%d",&R1,&R2);
			C.insert( R1 );
			S.insert( R2 );
		}
		for(j=0;j<N;j++)
		{
			if( C.count( j ) > 0 && S.count( j ) > 0 )
			{
				spying = false;
				break;
			}
		}
		printf("Scenario #%d:",i++);
		if( spying )
            printf(" spying\n");
		else
            printf(" spied\n");
	}
}
