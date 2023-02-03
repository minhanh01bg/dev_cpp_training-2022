#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int minDiff(int arr[], int n, int s);

int main(void)
{
	int t, n, s, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    cin >> s;
	    
	    cout << minDiff(arr, n, s) << endl;
	}
	return 0;
}

int minDiff(int arr[], int n, int s){
    sort(arr, arr+n);
    
    int min = INT_MAX, diff;
    
    for(int i=0;i<n-s+1;i++){
        diff = arr[i+s-1] - arr[i];
        
        if(diff < min)
            min = diff;
    }
    
    return min;
}