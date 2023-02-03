#include <iostream>
using namespace std;
int main()
{
	long long hanoi[36];
	hanoi[1]=2;
	for(int i=2;i<36;i++)
	    hanoi[i]=3*hanoi[i-1]+2;
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<hanoi[n]<<endl;
	}
	return 0;
}

