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
	    F.clear();
	    F.push_back(1);
	    vector<int>::iterator it;
	    for (int i=0; i<C.size(); i++)
	    {
	        it = find(C.begin()+i+1, C.end(), C[i]);
	        while (it!=C.end())
	        {
	            F[i]++;
	            C.erase(it);
	            it = find(C.begin()+i+1, C.end(), C[i]);
	        }
	        F.push_back(1);
	    }
	    K=F;
	    sort(K.begin(),K.end());
	    int token=K[K.size()-1]+1;
	    while (token--)
	    {
	    	for (int i=0; i<C.size(); i++)
	    	{
	    		if (F[i]==token)
	    		{
	    			while (F[i]--) cout<<C[i]<<' ';
	    		}
	    	}
	    }
	    cout<<endl;
	}
}
