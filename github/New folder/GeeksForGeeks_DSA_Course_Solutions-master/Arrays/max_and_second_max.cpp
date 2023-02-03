#include <bits/stdc++.h>
using namespace std;

void largestAndSecondLargest(int, int[]);

int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    largestAndSecondLargest(sizeOfArray, arr);
	}
	
	return 0;
}

void largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    
    for(int i=0;i<sizeOfArray;i++) {
        if(arr[i] > max){
            max2 = max;
            max = arr[i];
        }else if(arr[i] > max2 && arr[i] != max){ //to make sure it is distinct
            max2 = arr[i];
        }
    }
    
    if(max2 == INT_MIN)
        max2 = -1;
    
    cout << max << " " << max2 << endl;
}