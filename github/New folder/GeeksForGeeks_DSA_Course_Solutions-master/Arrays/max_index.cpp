#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n);

int main() 
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 


int maxIndexDiff(int arr[], int n) 
{ 
    int LMin[n+1], RMax[n+1];
    int i, j, maxDiff=-1;
    
    LMin[0] = arr[0];
    for(i=1;i<n;i++) {
        LMin[i] = min(arr[i], LMin[i-1]);
    }
    
    RMax[n-1] = arr[n-1];
    for(i=n-2;i>=0;i--) {
        RMax[i] = max(arr[i], RMax[i+1]);
    }
    
    i=0, j=0;
    while(i<n && j<n) {
        if(LMin[i] <= RMax[j]) {
            maxDiff = max(maxDiff, j-i);
            j++;
        }else{
            i++;
        }
    }
    return maxDiff;
}