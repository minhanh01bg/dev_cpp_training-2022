#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int isEqual(long long arr1[], long long arr2[], long long n);

int main(void)
{
	long long t, n, arr1[MAX], arr2[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(long long i=0;i<n;i++)
	        cin >> arr1[i];
	        
	    for(long long i=0;i<n;i++)
	        cin >> arr2[i];
	        
	    cout << isEqual(arr1, arr2, n) << endl; 
	        
	}
	return 0;
}

int isEqual(long long arr1[], long long arr2[], long long n){
    unordered_map<long long, long long> m;
    
    for(long long i=0;i<n;i++){
        m[arr1[i]]++;
    }
    
    for(long long i=0;i<n;i++){
        if(m[arr2[i]] == 0)
            return 0;
            
        m[arr2[i]]--;
    }
    
    return 1;
}