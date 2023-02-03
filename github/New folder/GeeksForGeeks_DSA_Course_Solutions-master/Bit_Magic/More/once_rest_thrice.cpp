#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int OnceRestThrice(int arr[], int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
        
        cout << OnceRestThrice(arr, n) << endl;
	}
	return 0;
}

int OnceRestThrice(int arr[], int n){
    int firstOccurence = 0, secondOccurence = 0, reset;

    for(int i=0;i<n;i++){
        secondOccurence = secondOccurence | (firstOccurence & arr[i]);
        firstOccurence = firstOccurence ^ arr[i];
        reset = ~(firstOccurence & secondOccurence);
        firstOccurence = firstOccurence & reset;
        secondOccurence = secondOccurence & reset;
    }

    return firstOccurence;
}