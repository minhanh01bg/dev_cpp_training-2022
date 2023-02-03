#include<bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }
    return 0;
}


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int n)
{
    //using hashing
    
    unordered_map<int, int> mp;
    int count_flag=0;
    
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
        
    for(auto i:mp){
        if(i.second > n/2){
            count_flag = 1;
            return i.first;
        }
    }
    
    if(count_flag==0)
        return -1;
}