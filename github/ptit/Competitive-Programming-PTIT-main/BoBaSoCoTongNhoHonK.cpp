#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		long long a,b;
		cin>>a>>b;
		long long C[a];
		for (int i=0; i<a; i++) cin>>C[i];
		sort(C,C+a);
		long long sum=0;
		for (int i=0; i<a-2; i++) 
		{
			int j = i+1, k = a-1;
			while (j<k)
			{
				if (C[i] + C[j] + C[k] >= b) k--;
				else 
				{
					sum+=(k-j);
					j++;
				}
			}
		}
		cout<<sum<<endl;
	}
}
