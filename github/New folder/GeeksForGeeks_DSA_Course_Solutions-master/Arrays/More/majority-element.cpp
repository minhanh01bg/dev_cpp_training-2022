#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

// using the boyre-moore voting algorithm

int findMajority(int a[], int n) {
    int count, candidate;
        
        // finding the candidate
        candidate = a[0];
        count = 1;
        for(int i=1;i<n;i++) {
            if(candidate != a[i]) {
                count--;
            }else{
                count++;
            }
            
            if(count == 0) {
                candidate = a[i];
                count = 1;
            }
        }
        
        // find the majority candidate
        count = 0;
        for(int i=0;i<n;i++) {
            if(a[i] == candidate) {
                count++;
            }
            
            if(count > (n/2)) {
                return candidate;
            }
        }
        
        return -1;
}


int main(void)
{
	int t, n, arr[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	        
	    cout << findMajority(arr, n) << endl;
	        
	}
	return 0;
}
