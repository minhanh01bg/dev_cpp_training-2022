#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes";
	else
		cout << "No";
	}
	return 0;
}



bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s;
    int presum = 0;
    
    for(int i=0;i<n;i++){
        presum = presum + arr[i];
        
        if(presum == 0)
            return true;
            
        if(s.find(presum) != s.end())
            return true;
            
        s.insert(presum);
    }
    
    return false;
}