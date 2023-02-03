#include <bits/stdc++.h>
using namespace std;
int arr[5000001];

int binarySearch(int arr[], int start, int end, int key);
int countOnes(int n);

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
                
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        cout <<countOnes(n)<<endl;
    }
    return 0;
}


// Function to count number of Ones
// arr: input array declared globally
// n: size of input array

int binarySearch(int arr[], int start, int end, int key){
    if(start<=end){
        int mid = start + (end-start)/2;
        
        if(arr[mid] == key && (mid==end || arr[mid+1]!=key))
            return mid;
        else if(arr[mid] >= key)
            return binarySearch(arr, mid+1, end, key);
        else
            return binarySearch(arr, start, mid-1, key);
    }
    return -1;
}


int countOnes(int n)
{
    int pos = binarySearch(arr, 0, n-1, 1);
    return pos+1;
}