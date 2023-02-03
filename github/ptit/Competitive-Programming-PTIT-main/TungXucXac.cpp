#include <bits/stdc++.h>
using namespace std;
long long factor[21][121];
void factory()
{
	memset(factor,0,sizeof(factor));
	for (int i=1; i<7; i++) factor[1][i]=1;
	for (int i=1; i<20; i++)
	{
		for (int j=i; j<=6*i; j++)
		{
			for (int k=1; k<=6; k++)
			{
				factor[i+1][j+k]+=factor[i][j];
			}
		}
	}
}
int main()
{
	factory();
	int N;
	cin>>N;
	while(N--)
	{
		int a, b;
		cin>>a>>b;
		cout<<factor[a][b]<<endl;
	}
}
