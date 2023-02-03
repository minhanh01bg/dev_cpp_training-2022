#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n);

int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
       long long n;
       cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        vector<int> v = leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;
   }
}

// This method scans from right
vector<int> leaders(int arr[], int n){
    vector<int> v;
    
    int max = arr[n-1];
    for(int i=n-1;i>=0;i--){
        if(arr[i] >= max){
            max = arr[i];
            v.push_back(max);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}