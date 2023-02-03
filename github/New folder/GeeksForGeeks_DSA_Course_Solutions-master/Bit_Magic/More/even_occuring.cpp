#include<bits/stdc++.h>
using namespace std;
#define MAX 200

void evenOcurrence(int* arr, int n);

int main(void)
{
	int t, n;
	int arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    evenOccurence(arr, n);
	}
	return 0;
}

void evenOcurrence(int* arr, int n){
    long long xorr = 0L, pos;
    for(int i=0;i<n;i++){
        pos = 1 << arr[i];
        xorr = xorr ^ pos;
    }
    
    for(int i=0;i<n;i++){
        pos = 1 << arr[i];
        
        if(!(pos & xorr)){
            cout << arr[i];
            // to avoid duplicates
            xorr = xorr ^ pos;
        }
    }
}