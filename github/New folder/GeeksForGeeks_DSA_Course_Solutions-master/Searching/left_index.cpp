#include <iostream>
using namespace std;

int leftmost(int arr[], int n, int start, int end, int x);
int leftIndex(int n, int arr[], int x);

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
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}



int leftmost(int arr[], int n, int start, int end, int x){
    if(start<=end){
        int mid = start + (end-start)/2;
        
        if(arr[mid]==x && (mid==start || arr[mid-1]!=x))
            return mid;
        else if(arr[mid]>=x)
            return leftmost(arr, n, start, mid-1, x);
        else
            return leftmost(arr, n, mid+1, end, x);
    }
    return -1;
}

int leftIndex(int n, int arr[], int x){
    
    return leftmost(arr, n, 0, n-1, x);
    
}