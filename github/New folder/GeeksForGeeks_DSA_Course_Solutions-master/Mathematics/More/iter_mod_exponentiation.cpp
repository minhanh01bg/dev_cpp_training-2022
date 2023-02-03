#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int modPow(int x, int n, int m);

int main(void)
{
	int t, a, b, c;
	cin >> t;
	while(t--){
	    scanf("%d %d %d", &a, &b, &c);
	    cout << modPow(a, b, c) << endl;
	}
	return 0;
}

// iterative solution that uses divide and
// conquer approach to solve (x^n) % m
int modPow(int x, int n, int m){
    int result = 1;
    
    // update x if its more than or 
    // equal to m. Trick to handle large numbers
    x = x % m;
    
    while(n > 0){
        // if n is odd, multiple x with the result
        // the last bit of every odd number is a set bit
        // so doing & with an odd number must return true
        if(n & 1){
            result = (x * result) % m; // do mod to handle large nos.
        }
        
        // right shift is equal to (n/2^k). Here k is 1
        // so we are doing n/2
        // here comes the story of divide and conquer
        n = n >> 1;
        x = (x * x) % m;
    }
    return result;
}
