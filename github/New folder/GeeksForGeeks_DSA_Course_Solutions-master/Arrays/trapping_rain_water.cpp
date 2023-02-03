#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int trap(int* arr, int n);

int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    cout << trap(arr, n) << endl;
	}
	return 0;
}

// using two pointer approach
// low and high be our two pointers
// time = O(n)
// space = O(1)
int trap(int* arr, int n){
    int water = 0, left_max = 0, right_max = 0, low = 0, high = n-1;
    
    while(low < high){
        if(arr[low] < arr[high]){
            if(arr[low] > left_max){
                left_max = arr[low];
            }else{
                water += left_max - arr[low];
                low++;
            }
        }else{
            if(arr[high] > right_max){
                right_max = arr[high];
            }else{
                water += right_max - arr[high];
                high--;
            }
        }
    }
    return water;
}