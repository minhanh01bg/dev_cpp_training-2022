#include<bits/stdc++.h>
using namespace std;

void twoRepeated(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        twoRepeated(a, n);
        cout<<endl;
    }
    return 0;
}


// Function to find the two repeated element
// arr: input array
// n: size of array
void twoRepeated(int arr[], int n){
    //using array indexing method
    for(int i=0;i<n+2;i++) {
        if(arr[abs(arr[i])]>0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}