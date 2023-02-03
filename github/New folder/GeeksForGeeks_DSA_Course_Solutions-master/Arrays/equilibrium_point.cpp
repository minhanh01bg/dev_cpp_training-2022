#include <iostream>
using namespace std;
// Position this line where user code will be pasted.
int equilibriumPoint(long long a[], int n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}

int equilibriumPoint(long long a[], int n) {
    unsigned long long sum = 0L;
    
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    
    long long left_sum = 0;
    
    for(int i=0;i<n;i++){
        sum -= a[i];
        
        if(left_sum == sum)
            return i+1; //since problem follows 1-based indexing
        
        left_sum += a[i];
    }
    return -1;
}