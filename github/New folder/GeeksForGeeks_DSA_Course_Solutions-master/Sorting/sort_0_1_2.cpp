#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    sortArray(arr, n);
	    printArray(arr, n);
	}
	return 0;
}

void sortArray(int arr[], int n){
    //use dutch national flag algorithm
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        switch(arr[mid]){
            case 0:{
                swap(arr[low++], arr[mid++]);
                break;
            }
            case 1:{
                mid++;
                break;
            }
            case 2:{
                swap(arr[mid], arr[high--]);
                break;
            }
        }
    }
}