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


int maximizeOnes(int arr[], int n, int m);

int main(void)
{
	int t, n, m, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    cin >> m;
	    cout << maximizeOnes(arr, n, m) << endl;
	}
	return 0;
}

int maximizeOnes(int arr[], int n, int m){
    int wL = 0, wR = 0;
    int bestWindow = 0, zeroCount = 0;
    
    while(wR < n){
        if(zeroCount <= m){
            if(arr[wR] == 0){
                zeroCount++;
            }
            wR++;
        }
        
        if(zeroCount > m){
            if(arr[wL] == 0){
                zeroCount--;
            }
            wL++;
        }
        
        if((wR-wL) > bestWindow){
            bestWindow = wR - wL;
        }
    }
    
    return bestWindow;
}