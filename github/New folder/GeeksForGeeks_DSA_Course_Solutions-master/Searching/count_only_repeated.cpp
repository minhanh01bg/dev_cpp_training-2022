#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

string countOnlyRepeated(vector<long long> arr, int n);

int main(void)
{
	int t, n;
	long long input;
	vector<long long> arr;
	
	cin >> t;
	
	while(t--){
	    cin >> n;
	    
	    arr.clear();
	    while(n--){
	        cin>>input;
	        arr.push_back(input);
	    }
	    
	    cout << countOnlyRepeated(arr, arr.size()) << endl;
	}
	return 0;
}

string countOnlyRepeated(vector<long long> arr, int n){
    int start = 0, end = n-1;
    
    if(start == end)
        return "0 0";
        
    while(start<=end){
        int mid = start + (end-start)/2;
        
        if(arr[mid] >= mid+arr[0])
            start = mid+1;
        else
            end = mid-1;
    }
    
    string element = to_string(arr[start]);
    string count = to_string(n - (arr[n-1]-arr[0]));
    
    return element+" "+count;
}