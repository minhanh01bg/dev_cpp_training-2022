#include <bits/stdc++.h>
using namespace std;
bool Check(int C[], int a, int b)
{
	for (int i=2; i<a; i++) 
	{
		int j = 0, k = i-1;
		while (j<k)
		{
			if (C[k] + C[j] + C[i] == b) return true;
			else if (C[k] + C[j] + C[i] > b) k--;
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
		int b;
		cin>>a>>b;
		int C[a];
		for (int i=0; i<a; i++) cin>>C[i];
		sort(C,C+a);
		Check(C,a,b) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
}
