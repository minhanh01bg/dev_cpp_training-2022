#include <bits/stdc++.h>
using namespace std;

int maxStep(int arr[], int n);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout << maxStep(a, n) << endl;
	}
	return 0;
}


int maxStep(int arr[], int n){
    
    //this problem is a variation of longest increasing subarray
   int count=0, maximum=0;
   
   for(int i=1;i<n;i++){
       if(arr[i]>arr[i-1]){
           count++;
       }else{
           maximum = max(maximum, count);
           count=0;
       }
   }
   return max(maximum, count);
}