#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long N;
	cin>>N;
	while(N--)
	{
		long long a,b;
		cin>>a>>b;
		long long C[a];
		long long F[5*b][a];
		memset(F,0,sizeof(F));
		long long key;
		for (long long i=0; i<a; i++) 
		{
			cin>>C[i];
			F[0][i] = C[i];
		}
		for (long long i=1; i<a; i++)
		{
			F[0][i] = max(F[0][i], F[0][i-1]);
		}
		for (long long i=1; i<5*b; i++)
		{
			key = i%5 + 1;
			if (key%2==0) key = 0 - key;
			F[i][i]= F[i-1][i-1] + C[i]*key;
			for (long long j=i+1; j<=a-5*b+i; j++)
			{
				F[i][j] = max(F[i][j-1],F[i-1][j-1]+C[j]*key);
			}
		}
		cout<<F[5*b-1][a-1]<<endl;
		// for (long long i=0; i<a; i++)
		// {
		// 	for (long long j=0; j<a; j++) cout<<F[i][j]<<' ';
		// 	cout<<endl;
		// }
	}
}
