#include<bits/stdc++.h>
using namespace std;

// program to find rightmost set bit
int main(void)
 {
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    unsigned int k = (n & -n);
	    if(n != 0)
	        cout << (log2(k) + 1) << endl;
	    else
	        cout << "0" << endl;
	}
	return 0;
}