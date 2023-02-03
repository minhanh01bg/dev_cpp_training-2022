#include<bits/stdc++.h>
using namespace std;
vector<int> F;
vector<int> C;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
	    int a;
	    cin>>a;
	    C.resize(a);
	    for (int i=0; i<a; i++) cin>>C[i];
	    sort(C.begin(),C.end());
	    F=C;
	    for (int i=0; i<a-1; i++) F[i]=C[i+1]-C[i];
	    F.pop_back();
	    sort(F.begin(),F.end());
	    cout<<F[0]<<endl;
	}
}
