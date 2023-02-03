#include<iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
int x[201];
int y[201];
double s[99999];
#define INF 2000000
int main(void) {
	int n,k,i,j,d;
	cin>>n;
	while(n!=0)
	{
	k=0;
	cin>>x[0]>>y[0];
	for(i=1;i<n;i++)
	{
		cin>>x[i]>>y[i];
		if(x[0]==x[i])
		s[k]=INF;
		else
		s[k]=(double)(y[i]-y[0])/(x[i]-x[0]);
		k++;
	}
	for(i=1;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
		if(x[i]==x[j])
		s[k]=INF;
		else
		s[k]=(double)(y[j]-y[i])/(x[j]-x[i]);
		k++;
		}
	}
	sort(s,s+k);
	i=1;
	d=1;
	while(i<k)
	{
	if(s[i-1]!=s[i])
	++d;
	i++;
	}
	cout<<d<<"\n";
	cin>>n;
	}
	return 0;
}
