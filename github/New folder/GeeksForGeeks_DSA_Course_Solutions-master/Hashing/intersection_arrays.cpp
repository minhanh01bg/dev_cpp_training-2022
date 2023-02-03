#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int intersectArrays(int arr1[], int n, int arr2[], int m);

int main(void)
{
	int t, n, m, arr1[MAX], arr2[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    cin >> m;
	    for(int i=0;i<n;i++)
	        cin >> arr1[i];
	        
	    for(int i=0;i<m;i++)
	        cin >> arr2[i];
	        
	    cout << intersectArrays(arr1, n, arr2, m) << endl;
	}
	return 0;
}

int intersectArrays(int arr1[], int n, int arr2[], int m){
    unordered_set<int> s;
    int result = 0;
    
    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }
    
    for(int i=0;i<m;i++){
        if(s.find(arr2[i]) != s.end()){
            result++; //count the no. of common elements
            s.erase(arr2[i]); //erasing the common elements
        }
    }
    return result;
}