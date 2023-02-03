#include <bits/stdc++.h>
using namespace std;

int minAdjDiff(int arr[], int n);

int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        
        cout << minAdjDiff(arr, n) << endl;
    }
    return 0;
}

int minAdjDiff(int arr[], int n){   
    int min, temp;
    
    min = abs(arr[0] - arr[1]);
    
    for(int i=1;i<n;i++) {
        if(i == n-1){
            temp = abs(arr[0] - arr[i]);
        }else{
            temp = abs(arr[i] - arr[i+1]);
        }
        
        if(temp < min) {
            min = temp;
        }
    }
    return min;
}