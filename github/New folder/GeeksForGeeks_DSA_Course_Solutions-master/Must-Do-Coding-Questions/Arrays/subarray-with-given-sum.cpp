// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    unsigned long long sum;
    
    cin >> t;
    
    while(t--) {
        cin >> n >> sum;
    
        int arr[n];
        
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        
        // solution
        unsigned long long currsum = 0;
        int start = 0;
        bool flag = false;
        
        for(int i=0;i<n;i++) {
            
            currsum += arr[i]; // adding the elements
            
            // There is no possibility of finding the subarray
            // if the current sum is greater than the given sum
            
            // so we will remove the elements from the start of the current subarray
            // while current sum is greater than the given sum
            // this is an implementation of the sliding window technique
            while(currsum > sum && start < i) {
                currsum -= arr[start++];
            }
            
            if(currsum == sum) {
                flag = true;
                cout << start + 1 << " " << i + 1 << endl;
                break;
            }
        }
        
        if(!flag) {
            cout << "-1" << endl;
        }
    }
}
