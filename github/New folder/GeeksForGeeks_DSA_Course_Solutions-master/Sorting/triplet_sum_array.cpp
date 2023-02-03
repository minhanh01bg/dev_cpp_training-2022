#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int arr[], int n, int sum);

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
        cout <<  find3Numbers(A, N, sum) << endl;
    }
}



// function to find the triplet which sum to x
bool find3Numbers(int arr[], int n, int sum)
{
    for(int i=0;i<n-2;i++)
    {
        unordered_set <int> m; //reset on every iteration of outer loop
        int curr_sum = sum - arr[i];
        
        for(int j=i+1;j<n;j++)
        {
            if(m.find(curr_sum - arr[j]) != m.end())
            {
                return true;
            }
            m.insert(arr[j]);
        }
    }
    return false;
}

//time complexity is O(n^2)