#include <iostream>
using namespace std;
#define MAX 100000

int main() {
	int t, n, i;
	long arr[MAX];
    cin>>t;
	while(t--){
	    cin>>n;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
		// notice that all the even occuring elements
		// form a pair. The pair cancel out in XOR
		// and finally result in zero
		// the remaining element we get is the one odd
		// occuring element
	    int rem = 0;
	    for(i=0;i<n;i++){
	        rem = rem ^ arr[i]; // XOR of all numbers
	    }
		/**
		 	arr[] = {3, 3, 3, 4, 5, 4, 5}
			>>> 3^3
			0
			>>> 0^3
			3
			>>> 3^4
			7
			>>> 7^5
			2
			>>> 2^4
			6
			>>> 6^5
			3
		 */
	    cout << rem << endl;
	}
	return 0;
}