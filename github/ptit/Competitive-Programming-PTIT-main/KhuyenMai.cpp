#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	long long a,b;
	cin>>a>>b;
	vector<long long> C, F, K;
	long long token;
	long long total=0;
	for (int i=0; i<a; i++) 
	{
	    cin>>token;
	    C.push_back(token);
	}
	for (int i=0; i<a; i++)
	{
	    cin>>token;
	    F.push_back(token);
	    total+=token;
	}
	for (int i=0; i<a; i++) 
	{
	    token=C[i]-F[i];
	    K.push_back(token);
	}
	sort(K.begin(),K.end());
	for (int i=0; i<b; i++) total+=K[i];
	for (int i=b; ; i++) 
	{
		if (K[i] >=0 ) break;
		total += K[i];
	}
	cout<<total;
}
