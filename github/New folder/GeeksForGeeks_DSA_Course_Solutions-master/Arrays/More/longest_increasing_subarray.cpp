#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int longestSubarray(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout << longestSubarray(arr, n) << endl;
	}
	return 0;
}

int longestSubarray(int arr[], int n){
    int count=0, maximum=0;
    
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            count++;
        }else{
            maximum = max(maximum, count);
            count=0;
        }
    }
    return max(maximum, count)+1;
}