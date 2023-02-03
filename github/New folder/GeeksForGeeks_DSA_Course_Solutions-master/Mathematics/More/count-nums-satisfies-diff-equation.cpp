#include<bits/stdc++.h>
using namespace std;

int SumOfDigits(int k) {
    int sum = 0;
    while(k > 0) {
        sum += (k % 10);
        k = k / 10;
    }
    return sum;
}

// using binary search we find the smallest number
// after which every number satisfies the given condition
int solve(int n, int d) {
    int low = 1, high = n;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        // if diff is less than d 
        // then the smallest no. is in the right part
        if(mid - SumOfDigits(mid) < d) {
            low = mid + 1;
        }
        // else it's in the left part
        else{
            high = mid - 1;
        }
    }
    
    // n - (the position where we got the smallest no.)
    return n - high;
}

int main(void)
{
	int t, n, d;
	
	cin >> t;
	
	while(t--){
	    cin >> n >> d;
	    cout << solve(n, d) << endl;
	}
	return 0;
}