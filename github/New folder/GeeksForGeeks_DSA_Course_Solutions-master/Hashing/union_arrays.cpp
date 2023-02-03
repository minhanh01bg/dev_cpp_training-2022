#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int myunion(int arr1[], int n, int arr2[], int m);

int main(void)
{
	int t, n, m, arr1[MAX], arr2[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    cin >> m;
	    for(int i=0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i=0;i<m;i++){
	        cin >> arr2[i];
	    }
	        
	    cout << myunion(arr1, n, arr2, m) << endl;
	}
	return 0;
}

int myunion(int arr1[], int n, int arr2[], int m){
    unordered_set<int> s;
    
    for(int i=0;i<n;i++)
        s.insert(arr1[i]);
    
    for(int i=0;i<m;i++)
        s.insert(arr2[i]);
        
    return s.size();
}