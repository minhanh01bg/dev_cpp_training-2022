#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int occuringOnce(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout << occuringOnce(arr, n) << endl;
	}
	return 0;
}

int occuringOnce(int arr[], int n){
    int x=0;
    
    for(int i=0;i<n;i++){
        x = x ^ arr[i];
    }
    
    return x;
}