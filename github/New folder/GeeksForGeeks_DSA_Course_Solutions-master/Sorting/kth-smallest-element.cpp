#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int kthSmallest(int arr[], int k, int left, int right);
int partition(int arr[], int left, int right);
int randomPartition(int arr[], int left, int right);

int main(void)
{
	int t, n, arr[MAX], k;
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>k;
	    int index = kthSmallest(arr, k, 0, n-1);
	    cout << arr[index] << endl;
	}
	return 0;
}

int kthSmallest(int arr[], int k, int left, int right){
    int size = right - left + 1;
    
    if(k>0 && k<=size){
        int pos = randomPartition(arr, left, right);
        
        if(pos-left == k-1)
            return pos;
        else if(pos-left > k-1)
            return kthSmallest(arr, k, left, pos-1); //left part has the smaller elements
        else //if pos-left < k-1
            return kthSmallest(arr, k-pos+left-1, pos+1, right); //right part has the greater elements
    }
    return -1;
}

int randomPartition(int arr[], int left, int right) 
{ 
    int size = right - left + 1; 
    int pivot = rand() % size; 
    swap(arr[left + pivot], arr[right]); 
    return partition(arr, left, right); 
} 

int partition(int arr[], int left, int right){
    //Lomuto partition
    int i = left-1;
    int pivot = arr[right];
    
    for(int j=left;j<=right-1;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}