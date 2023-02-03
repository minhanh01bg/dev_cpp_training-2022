#include<bits/stdc++.h>
using namespace std;

void findSubarray(int arr[], int n, int sum) {
    // hashing and prefix sum
    unordered_map<int, int> m;
    int currsum = 0;

    for(int i=0;i<n;i++) {
        currsum += arr[i];

        if(currsum == sum) {
            cout << "0 to " << i;
            return;
        }

        if(m.find(currsum - sum) != m.end()) {
            cout << m[currsum - sum] << " to " << i;
            return;
        }

        m[currsum] = i;
    }
}

int main() {
    int n, t, sum;

    cin >> t;
    cin >> n >> sum;

    while(t--) {
        int arr[n];

        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        findSubarray(arr, n, sum);
    }

    return 0;
}