#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int k; cin>>k;
	int sum=0;
	(k>a) ? sum+=a : sum+=(k-1);
	(k>b) ? sum+=b : sum+=(k-1);
	(k>c) ? sum+=c : sum+=(k-1);
	sum++;
	cout<<sum<<endl;
}
