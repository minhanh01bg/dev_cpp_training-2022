#include<bits/stdc++.h>
using namespace std;
vector<int> K;
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
	    K=C;
	    F=C;
	    for (int i=1; i<a; i++) K[i]+=K[i-1];
	    for (int i=a-2; i>=0; i--) F[i]+=F[i+1];
	    int key=-1;
	    for (int i=0; i<a; i++) 
	    {
	        if (K[i]==F[i])
	        {
	            key=i+1;
	            break;
	        }
	    }
	    cout<<key<<endl;
	}
}
