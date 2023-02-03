#include <bits/stdc++.h>
using namespace std;
bool findSubarraySum(long long arr[], long long n, long long sum)
{
    unordered_map<long long, long long> prevSum;
 
    long long currsum = 0;
 
    for (int i = 0; i < n; i++) 
	{
        currsum += arr[i];
 
        if (currsum == sum)
            return true;
 
        if (prevSum.find(currsum - sum) != prevSum.end())
            return true;
 
        prevSum[currsum]++;
    }
 
    return false;
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		long long a; long long b;
		cin>>a>>b;
		long long C[a];
		for (int i=0; i<a; i++) cin>>C[i];
		if (findSubarraySum(C,a,b)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
