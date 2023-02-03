#include <bits/stdc++.h>
using namespace std;
bool Check(long long C[], int a)
{
	for (int i=2; i<a; i++) 
	{
		int j = 0, k = i-1;
		while (j<k)
		{
			if (C[k] + C[j] == C[i]) return true;
			else if (C[k] + C[j] > C[i]) k--;
			else j++;
		}
	}
	return false;
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
	    int a;
		long long b;
		cin>>a;
		long long C[a];
		for (int i=0; i<a; i++) 
		{
		    cin>>b;
		    C[i]=b*b;
		}
		sort(C,C+a);
		Check(C,a) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
}
