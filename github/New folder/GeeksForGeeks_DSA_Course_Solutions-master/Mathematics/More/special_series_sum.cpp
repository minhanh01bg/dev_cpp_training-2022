#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int main(void)
{
	int t;
	long n, sum = 0;
	cin >> t;
	while(t--){
	    cin >> n;
	    sum = ((n * (n + 1)) * ((2 * n) + 4)) / 12;
        // Time - O(1)
	    cout << sum << endl;
	}
	return 0;
}