#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int C[a], F[a][a];
	for (int i=0; i<a; i++) cin>>C[i];
	for (int i=0; i<a; i++)
	{
		for (int j=0; j<a; j++) F[i][j]=-1;
	}
	for (int i=a-1; i>=0; i--)
	{
		for (int j=i+1; j<a; j++)
		{
			if (j-i==1) F[i][j]=0;
			else if (j-i==2) F[i][j] = C[i]*C[j];
			else for (int k = i+1; k<j; k++) F[i][j] = max(F[i][j], F[i][k] + F[k][j] + C[i]*C[j]);
		}
	}
	cout<<F[0][a-1];
}
