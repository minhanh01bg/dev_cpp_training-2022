#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		long long C[5], F[5];
		memset(C,0,sizeof(C));
		for (long long i=0; i<5; i++) 
		{
			cin>>C[i];
			F[i]=C[i];
		}
		long long k = C[0]-C[4];
		long long k1 = C[1]-C[4];
		long long sum1=1;
		long long sum2=1;
		long long pressF=C[4];
		if (k1>=C[3]) sum1=k1*C[0];
		else
		{
			pressF-=(C[1]-C[3]);
			C[0]=max(C[2],C[0]-pressF);
			sum1=C[0]*C[3];
		}
		pressF=F[4];
		if (k>=F[2]) sum2=k*F[1];
		else
		{
			pressF-=(F[0]-F[2]);
			F[1]=max(F[3],F[1]-pressF);
			sum2=F[1]*F[2];
		}
		long long final=min(sum2,sum1);
		cout<<final<<endl;
	}
}
