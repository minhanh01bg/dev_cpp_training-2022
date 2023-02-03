#include <bits/stdc++.h> 
using namespace std;

int searchInSorted(int arr[], int n, int x);
int binarySearch(int arr[], int start, int end, int key);

int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << searchInSorted(arr, n, k) << endl;
    }
	return 0; 
} 


// Function to find element in sorted array
// arr: input array
// n: size of array
// x: element to be searched
int binarySearch(int arr[], int start, int end, int key){
    if(start<=end){
        int mid = start + (end-start)/2;
        
        if(arr[mid] == key)
            return 1;
        else if(arr[mid] < key)
            return binarySearch(arr, mid+1, end, key);
        else
            return binarySearch(arr, start, mid-1, key);
    }
    return -1;
}

int searchInSorted(int arr[], int n, int x) 
{
    return binarySearch(arr, 0, n-1, x);
}