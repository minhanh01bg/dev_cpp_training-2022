#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void printArray(int arr1[], int arr2[], int m, int n){
    for(int i=0;i<m;i++){
        cout << arr1[i] << " ";
    }
    for(int i=0;i<n;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
}

void mergeSortedarray(int arr1[], int arr2[], int m, int n);

int main(void)
{
	int t, m, n, arr1[MAX], arr2[MAX];
	cin >> t;
	while(t--){
	    cin >> m;
	    cin >> n;
	    for(int i=0;i<m;i++)
	        cin >> arr1[i];
	        
	    for(int j=0;j<n;j++)
	        cin >> arr2[j];
	        
	    mergeSortedarray(arr1, arr2, m, n);
	    printArray(arr1, arr2, m, n);
	}
	return 0;
}

void mergeSortedarray(int arr1[], int arr2[], int m, int n){
    for(int i=n-1; i>=0; i--){
        int j, last = arr1[m-1];
        for(j=m-2; j>=0 && arr1[j]>arr2[i]; j--){
            arr1[j+1] = arr1[j];
        }
        
        if(j!=m-2 || last>arr2[i]){
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
}