#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[100], n;
	bool desc = false, aesc = false;
	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	
	for(int i=1;i<n;i++) {
		if(a[i-1] > a[i]) {
			desc = true;
			
			if(aesc) {
				break;
			}
		}else{
			aesc = true;
			
			if(desc) {
				break;
			}
		}
	}
	
	if(aesc && desc) {
		cout << "Not sorted" << endl;
	}else if(desc) {
		cout << "Desc" << endl;
	}else{
		cout << "Aesc" << endl;
	}
	return 0;
}