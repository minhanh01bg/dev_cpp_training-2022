#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int solve(int a[], int n) {
    int incl = a[0], excl = 0, excl_new = 0;
    
    // incl is the max sum including the previous element
    // excl is the max sum excluding the previous element
    
    for(int i=1;i<n;i++) {
        excl_new = incl > excl ? incl : excl;
        incl = excl + a[i];
        excl = excl_new;
    }
    
    return incl > excl ? incl : excl;
}




int main(void)
{
	int t, n, a[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++)
	        cin >> a[i];
	    
	    cout << solve(a, n) << endl;
	}
	return 0;
}