#include<bits/stdc++.h>
using namespace std;

int main(void)
 {
	int t, m, n;
	cin >> t;
	while(t--){
	    scanf("%d %d", &m, &n);
	    // xor two nos.
	    unsigned int k = (m ^ n);
	    // now find the position of
	    // rightmost set bit
	    // occurs in xor when
	    // two elements are different
	    cout << log2(k & -k) + 1 << endl;
	}
	return 0;
}