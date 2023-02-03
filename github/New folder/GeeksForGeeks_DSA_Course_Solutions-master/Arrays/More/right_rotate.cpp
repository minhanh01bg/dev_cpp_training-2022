#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void rotateArray(int* arr, int d, int n);
void reverse(int* arr, int start, int end);

int main(void)
{
	int t, n, d;
	int arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    // input to array
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    cin >> d;

	    rotateArray(arr, d, n);

	    // print the array
	    for(int i=0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}

void rotateArray(int* arr, int d, int n){
    d = d % n; //handles corner cases; when d > n
    reverse(arr, 0, n-1);
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
}

void reverse(int* arr, int start, int end){
    int temp;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}