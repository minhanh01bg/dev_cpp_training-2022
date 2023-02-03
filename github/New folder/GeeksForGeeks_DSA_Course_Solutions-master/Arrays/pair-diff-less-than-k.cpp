#include<bits/stdc++.h>
using namespace std;

int findPairs(int nums[], int n, int k) {
    // sort the array and start finding the pairs
    sort(nums, nums+n);
    
    int count = 0;
    
    for(int i=0;i<n;i++) {
        
        int j = i + 1;
        // skip if difference is equal to or greater than k
        // a sorted array benefits us here to skip iterations and save time
        while(j < n && nums[j]-nums[i] < k) {
            count++;
            j++;
        }
    }
    
    return count;
}

int main() {
    int t, n, k, nums[10000];
    
    cin >> t;
    
    while(t--) {
        cin >> n >> k;
        
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        
        cout << findPairs(nums, n, k) << endl;
    }
}