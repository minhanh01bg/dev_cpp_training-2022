#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, temp, i = 0, dec = 0;
	cin >> n;
	
	while(n != 0){
	    temp = n % 10;
	    dec = dec + (temp * pow(8, i++));
	    n = n / 10;
	}
	
	cout << dec << endl;
	
	return 0;
}
