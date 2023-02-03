#include <bits/stdc++.h>
using namespace std;

vector<long long> reverseArray(vector<long long> mv, int start, int end);
vector<long long> reverseInGroups(vector<long long> mv, int n, int k);

int main() {
    int t; //Testcases
    cin >> t; //input the number of testcases
    while(t--){ //while testcases exist
        int n;
        cin >> n; //input the size of array
        
        vector<long long> mv; // Declaring a vector mv
        
        int k;
        cin >> k; //input k 
        for(long long i =0;i<n;i++){
            long long x;
            cin >> x; //input element of array
            mv.push_back(x); //push the element into vector
        }
        
        mv = reverseInGroups(mv, n, k);
        
        for(long long i =0;i<n;i++){
            cout << mv[i] << " "; //Just print the vector
        }
        cout << endl;
        
       
    }
}

vector<long long> reverse(vector<long long> mv, int start, int end) {
    int temp;
    
    while(start < end) {
        temp = mv[start];
        mv[start] = mv[end];
        mv[end] = temp;
        start++;
        end--;
    }
    return mv;
}

vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    
    int revCount = (n/k) + 1;
    
    int i=0, e;
    while(revCount-- > 0) {
        e = i+k;
        
        if(e > n){
            e = e - (e-n);
        }
        
        mv = reverse(mv, i, e-1);
        i = e;
    }
    
    return mv;
}

/* Straightforward solution on GFG */

/* vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    
    int left, right;
    for(int i=0;i<n;i+=k) {
        left = i;
        
        right = min(i+k-1, n-1);
        
        while(left < right) {
            swap(mv[left++], mv[right--]);
        }
    }
    
    return mv;
} */