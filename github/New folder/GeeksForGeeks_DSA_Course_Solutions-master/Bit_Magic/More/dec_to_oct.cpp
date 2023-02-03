#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

int main() {
	int n, oct[MAX], i = 0;
	cin >> n;
	
	while(n != 0){
	    oct[i++] = n % 8;
	    n = n /8;
	}
	
	for(int j=i-1; j>=0; j--){
	    cout << oct[j];
	}
	
	return 0;
}
