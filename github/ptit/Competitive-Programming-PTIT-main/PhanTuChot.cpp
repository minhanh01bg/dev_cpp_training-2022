#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while (N--)
    {
    	long long a;
    	cin>>a;
    	long long C[a], F[a], K[a];
    	for (int i=0; i<a; i++) cin>>C[i];
    	bool bool1[a];
    	// bool bool2[a];
    	memset(bool1,true,sizeof(bool1));
    	// memset(bool2,true,sizeof(bool2));
    	F[0] = C[0];
    	for (int i=1; i<a; i++)
    	{
    		if (C[i]==F[i-1]) bool1[i-1] = false;
    		F[i] = max(F[i-1],C[i]);
		}
		K[a-1] = C[a-1];
		for (int i=a-2; i>=0; i--)
    	{
    		// if (C[i]==K[i+1]) bool2[i] = false;
    		K[i] = min(K[i+1],C[i]);
		}
		long long count=0;
		for (int i=0; i<a; i++)
		{
			if (F[i] == K[i] && bool1[i]) count++;
			// cout<<K[i]<<' ';
		}
		// cout<<endl;
		cout<<count<<endl;
	}
}
