#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void productArray(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    productArray(arr, n);
	}
	return 0;
}

void productArray(int arr[], int n){
    int p=1;
    
    for(int i=0;i<n;i++){
        p = p * arr[i];
    }
    
    for(int i=0;i<n;i++){
        cout << p/arr[i] << " ";
    }
    cout << endl;
}