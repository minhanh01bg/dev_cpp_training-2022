#include <bits/stdc++.h>
using namespace std;
int factor[101];
void factory()
{
	memset(factor,0,sizeof(factor));
	for (int i=1; i<=6; i++)
	{
		int p = pow(2,i);
		for (int j=p; j<101; j+=p) factor[j]++;
	}
	for (int i=2; i<101; i++) factor[i]+=factor[i-1];
}
int main()
{
	factory();
	
		int a,b;
		cin>>a>>b;
		int f = factor[a];
		if (f>=b) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
}
