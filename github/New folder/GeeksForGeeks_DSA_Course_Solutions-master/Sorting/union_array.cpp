#include <bits/stdc++.h>
using namespace std;

void findUnion(int arr1[], int arr2[], int n, int m);

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    findUnion(arr1,arr2, N, M);
	    
	    cout << endl;
	    
	}
	
	return 0;
}


void findUnion(int arr1[], int arr2[], int n, int m)
{
    int i=0, j=0;
    
    while(i<n && j<m){
        while(i+1<n && arr1[i]==arr1[i+1]){i++;}
        
        while(j+1<m && arr2[j]==arr2[j+1]){j++;}
        
        if(arr1[i]<arr2[j]){
            cout << arr1[i++] << " ";
        }else if(arr1[i]>arr2[j]){
            cout << arr2[j++] << " ";
        }else{
            cout << arr1[i] << " ";
            i++; j++;
        }
    }
    
    while(i<n){
        while(i+1<n && arr1[i]==arr1[i+1]){i++;}
        cout << arr1[i++] << " ";
    }
    
    while(j<m){
        while(j+1<m && arr2[j]==arr2[j+1]){j++;}
        cout << arr2[j++] << " ";
    }
}