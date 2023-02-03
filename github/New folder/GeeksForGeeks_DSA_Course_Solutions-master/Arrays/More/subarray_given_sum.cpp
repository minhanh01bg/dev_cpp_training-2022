#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void findSubarray(int arr[], int n, int sum);

int main(void)
{
	int t, n, k, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    cin >> k;
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    findSubarray(arr, n, k);
	}
	return 0;
}

void findSubarray(int arr[], int n, int sum){
    bool found = false;
    int currsum = arr[0];
    
    int start=0, i=1;
   
    //remember, we have 1-based indexing here
    for(i=1;i<=n;i++){
        while(currsum > sum && start < i-1){
            currsum = currsum - arr[start];
            start++;
        }
        
        if(currsum == sum){
            cout << start+1 << " " << i << endl;
            found = true;
            break;
        }
        
        if(i<n)
            currsum = currsum + arr[i];
    }
    
    if(!found)
        cout << "-1" << endl;
}