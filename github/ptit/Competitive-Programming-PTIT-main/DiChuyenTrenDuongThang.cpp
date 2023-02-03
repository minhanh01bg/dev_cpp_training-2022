#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y;
	while(cin>>x>>y)
	{
		long long k=abs(y-x);
		long long sum=0;
		if (k==0) 
		{
			cout<<0<<endl;
			continue;
		}
		for (int i=1; ; i++)
		{
			if (k<i)
			{
				sum++;
				break;
			}
			k-=i;
			sum++;
			if (k==0) break;
			if (k>=i)
			{
				sum++;
				k-=i;
			}
			if (k==0) break;
		}
		cout<<sum<<endl;
	}
}
