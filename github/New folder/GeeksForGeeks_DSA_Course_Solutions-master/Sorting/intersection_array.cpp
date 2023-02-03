#include <bits/stdc++.h> 
using namespace std; 

void printIntersection(int arr1[], int arr2[], int N, int M);  
  
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        
        // Function calling 
        printIntersection(arr1, arr2, N, M); 
        
        cout << endl;
    }
    
  return 0; 
} 

void printIntersection(int arr1[], int arr2[], int n, int m) 
{ 
    int i=0, j=0;
    
    while(i<n && j<m){
        if(i>0 && arr1[i]==arr1[i-1]){i++;}
        if(j>0 && arr2[j]==arr2[j-1]){j++;}
        
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++; j++;
        }
        
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }
    }
}