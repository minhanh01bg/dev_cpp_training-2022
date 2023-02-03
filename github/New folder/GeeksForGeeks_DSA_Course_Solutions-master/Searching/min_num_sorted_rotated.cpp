#include <bits/stdc++.h>
using namespace std;

int minNumber(int arr[], int low, int high);

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];		
		cout << minNumber(a,0,n-1) << endl;
	}
	return 0;
}


// Function to find the minimum element in sorted and rotated array
// arr: input array
// low and high are 0 and n-1, where n is the size of arr
int minNumber(int arr[], int low, int high)
{
    //if array is not rotated at all
    //then first element is the minimum
    if(low>high)
        return arr[0];
        
    //if there is only one element left
    if(high == low)
        return arr[low];
        
    int mid = low + (high-low)/2;
    
    if(mid > low && arr[mid-1] > arr[mid])
        return arr[mid];
        
    if(mid < high && arr[mid+1] < arr[mid])
        return arr[mid+1];
        
    //decide whether to go left or right
    if(arr[high] < arr[mid])
        return minNumber(arr, mid+1, high);
    else
        return minNumber(arr, low, mid-1);
}