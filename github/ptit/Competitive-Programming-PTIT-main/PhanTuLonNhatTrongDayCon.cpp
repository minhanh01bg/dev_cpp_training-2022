#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a,b;
		cin>>a>>b;
		deque<int> F;
		int C[a];
		for (int i=0; i<a; i++) cin>>C[i];
		for (int i=0; i<b; i++)
		{
			while (F.size()>0 && C[F.back()]<=C[i]) F.pop_back();
			F.push_back(i);
		}
		cout<<C[F.front()]<<' ';
		for (int i=b; i<a; i++)
		{
		    while (F.size()>0 && F.front()<=i-b) F.pop_front();
			while (F.size()>0 && C[F.back()]<=C[i]) F.pop_back();
			F.push_back(i);
			cout<<C[F.front()]<<' ';
		}
		cout<<endl;
	}
}
