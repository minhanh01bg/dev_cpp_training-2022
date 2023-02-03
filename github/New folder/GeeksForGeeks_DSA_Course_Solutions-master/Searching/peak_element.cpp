#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n);
int searchPeak(int arr[], int n, int start, int end);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}
	return 0;
}


/* The function should return the index of any
   peak element present in the array */
// arr: input array
// n: size of array

int searchPeak(int arr[], int n, int start, int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        
        //corner cases
        if(mid==start && arr[mid]>arr[mid+1])
            return mid;
        if(mid==end && arr[mid]>arr[mid-1])
            return mid;
            
        //binary search
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            return mid;
        else if(arr[mid+1] > arr[mid])
            return searchPeak(arr, n, mid+1, end);
        else
            return searchPeak(arr, n, start, mid-1);
    }
}

int peakElement(int arr[], int n)
{
   return searchPeak(arr, n, 0, n-1);
}