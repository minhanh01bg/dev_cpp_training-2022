#include <bits/stdc++.h>
using namespace std;
long long Total(long long C[], long long a)
{
	long long answer=0;
	for (int i=0; i<a; i++) answer += C[i];
	return answer;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    long long C[a];
    for (int i=0; i<a; i++) cin>>C[i];
    sort(C,C+a);
    for (int i=0; i<a; i++)
    {
    	if (C[i]>=0) break;
    	if (b==0) break;
    	C[i] = 0 - C[i];
    	b--;
	}
	if (b==0) 
	{
		cout<<Total(C,a);
		return 0;
	}
	sort(C,C+a);
	if (b%2==1) C[0] = 0 - C[0];
	cout<<Total(C,a);
}
