#include<bits/stdc++.h>
using namespace std;

void convertToWave(int *arr, int n)

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        int a[n]; //declare array of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        
        convertToWave(a, n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}

void convertToWave(int *arr, int n){
    for(int i=0;i<n;i+=2) { //only even places
        if(i<n-1 && arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);
            
        if(i>0 && arr[i] < arr[i-1])
            swap(arr[i], arr[i-1]);
    }
}