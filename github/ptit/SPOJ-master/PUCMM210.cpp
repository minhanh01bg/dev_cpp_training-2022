#include <iostream>
using namespace std;
long long mod = 1000000003;
long long a[1000001];
long long b[1000001];
int main() {
	long long t,i,n;
	cin>>t;
	for(i=1;i<=1000000;i++)
	{
	a[i]=(a[i-1]+(i*i*i))%mod;
	b[i]=(a[i]+b[i-1])%mod;
    }
	while(t--)
    {
		cin>>n;
		cout<<b[n]<<"\n";
	}
	return 0;
}
