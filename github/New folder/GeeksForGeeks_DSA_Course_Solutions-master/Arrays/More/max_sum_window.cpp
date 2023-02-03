#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int max_sum(int arr[], int n, int k);

int main(void)
{
	int t, n, k, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n >> k;
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    cout << max_sum(arr, n, k) << endl;
	}
	return 0;
}

int max_sum(int arr[], int n, int k){
    if(n == 1)
        return arr[0];
        
    long max = 0;
    for(int i=0;i<k;i++){
        max += arr[i];
    }
    
    long tempmax = max;
    for(int i=k;i<n;i++){
        tempmax = (tempmax - arr[i-k]) + arr[i];
        max = std::max(max, tempmax);
    }
    return max;
}