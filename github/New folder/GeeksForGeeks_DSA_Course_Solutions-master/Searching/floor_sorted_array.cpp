#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<long long> arr, long long n, long long x);

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    
	    cout << findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}


// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> arr, long long n, long long x){
    
    int start=0, end=n-1, pos=-1;
    
    //if last element is the floor
        if(arr[end]<=x)
            pos = end;
    
    //binary search implementation
    while(start<=end){
        int mid = start + (end-start)/2;
            
        if(arr[mid]==x)
            pos = mid;
            
        if(arr[mid]>x && arr[mid-1]<=x)
            pos = mid-1;
            
        if(arr[mid]<x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return pos;
}