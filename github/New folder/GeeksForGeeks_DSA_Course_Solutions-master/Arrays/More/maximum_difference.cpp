#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int maxDiff(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    cout << maxDiff(arr, n) << endl;
	}
	return 0;
}

int maxDiff(int arr[], int n){
    int max_diff = arr[1] - arr[0];
    int min = arr[0];
    
    for(int i=1; i<n; i++)
    {
        if(arr[i] - min > max_diff){
            max_diff = arr[i] - min;
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return max_diff;
}