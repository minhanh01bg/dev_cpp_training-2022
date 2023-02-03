#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	cin >> t;
	while(t--){
	    scanf("%d %d", &a, &b);
	    int xorResult = a ^ b;
	    // using brian karnighan's algorithm to count set bits
	    int count = 0;
	    while(xorResult > 0){
	        xorResult = xorResult & (xorResult - 1);
	        count++;
	    }
	    cout << count << endl;
	}
	return 0;
}