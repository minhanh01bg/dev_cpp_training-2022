#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
	long long n,k,s;
	while(t--)
	{
		cin>>n>>k;
		s=0;
		k=k-1;
		while(k!=0)
		{
			s=s+(k%2);
			k=k/2;
		}
		if(s%2==1)
		cout<<"Female\n";
		else
		cout<<"Male\n";
	}
	return 0;
}
