#include <bits/stdc++.h>
using namespace std;

int maxOccured(int L[], int R[], int n, int maxx);

int arr[1000000];

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int L[n];
	    int R[n];
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    
	    cout << maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}


int maxOccured(int L[], int R[], int n, int maxx){

    memset(arr, 0, sizeof(arr)); 

    for(int i=0;i<n;i++) {
        arr[L[i]]++;
        arr[R[i]+1]--;
    }

    //calculate prefix sum
    int maxSum = arr[0], index;
    
    for(int i=1;i<=maxx;i++){
        arr[i] = arr[i-1] + arr[i];

        if(maxSum < arr[i]) {
            maxSum = arr[i];
            index = i;
        }
    }
    return index;
}