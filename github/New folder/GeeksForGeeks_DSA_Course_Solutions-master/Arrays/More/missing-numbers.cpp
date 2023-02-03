#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

/** We can use the n(n+1)/2 formula to calculate
 * the sum of natural nos. up to n and subtract it from 
 * the sum of all elements in the array. That would give
 * us the missing number. But if n is a big number,
 * we might face integer overflow. The below solution
 * works on the fly and curtails the risk of 
 * meeting an integer overflow. **/
 
int findMissingNumber(int a[], int n) {
    int sum = 1;
    
    for(int i=2;i<=n;i++) {
        sum = sum + i;
        sum = sum - a[i-2];
    }
    
    return sum;
}

int main() {
    int t, n, a[MAX];
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        for(int i=0;i<n-1;i++) {
            cin >> a[i];
        }
        
        cout << findMissingNumber(a, n) << endl;
    }
}