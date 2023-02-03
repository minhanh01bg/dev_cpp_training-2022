#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
	long long N;
	cin>>N;
	while(N--)
	{
		long long a,b;
		cin>>a>>b;
		long long C[a];
		long long total = 0;
		for (int i = 0; i < a; i++) 
		{
			cin>>C[i];
		}
		long long myGCD = C[0] - C[1];
		for (int i = 2; i < a; i++)
		{
			myGCD = __gcd(myGCD,C[0] - C[i]);
		}
		long long x = b - C[0];
		if (x%myGCD==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
