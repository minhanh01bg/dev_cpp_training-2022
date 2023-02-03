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

int nextGap(int k){
    if(k<=1)
        return 0;
    
    return ceil(k/2);
}

void mergeSortedarray(int arr1[], int arr2[], int m, int n){
    int i, j, gap = m+n;
    
    for(gap=nextGap(gap); gap>0; gap=nextGap(gap)){
        //comparing elements in first array
        for(i=0; i+gap<m; i++){
            if(arr1[i] > arr1[i+gap])
                swap(arr1[i], arr1[i+gap]);
        }
        
        //comparing elements from both the arrays
        for(j=gap>m?gap-m:0; i<m && j<n ; i++, j++){
            if(arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }
        
        //comapring elements in second array
        if(j < n){
            for(j=0; j+gap<n; j++){
                if(arr2[j] > arr2[j])
                    swap(arr2[j], arr2[j+gap]);
            }
        }
    }
}