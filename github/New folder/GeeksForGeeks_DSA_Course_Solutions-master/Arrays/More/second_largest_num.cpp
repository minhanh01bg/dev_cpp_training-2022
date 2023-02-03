#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int find2ndlargest(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    cout << find2ndlargest(arr, n) << endl;
	}
	return 0;
}

int find2ndlargest(int arr[], int n){
    int first = INT_MIN, second = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }else if(arr[i] > second && arr[i]!=first){
            second = arr[i];
        }
    }
    
    return second==INT_MIN?-1:second;
}