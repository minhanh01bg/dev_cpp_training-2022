#include<bits/stdc++.h>
using namespace std;

bool checkSetBits(int n);

int main(void) 
{
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    if(checkSetBits(n))
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
	}
	return 0;
}

bool checkSetBits(int n){
    if(n == 0)
        return false;
        
    while(n > 0){
        if((n & 1) == 0)
            return false;

            n = n >> 1;
    }
    return true;
}