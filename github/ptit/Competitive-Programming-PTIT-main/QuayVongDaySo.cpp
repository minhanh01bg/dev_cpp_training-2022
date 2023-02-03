#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
	    vector<int> C;
	    C.clear();
	    int a,b;
	    cin>>a>>b;
	    C.resize(a);
	    for (int i=0; i<a; i++)
	    {
	        cin>>C[i];
	    }
	    while(b--)
	    {
	        C.push_back(C[0]);
	        C.erase(C.begin());
	    }
	    for (int i=0; i<a; i++) cout<<C[i]<<' ';
	    cout<<endl;
	}
}
