#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n);
bool checkBleak(int n);

int main(void)
{
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    if(checkBleak(n))
	        cout << "1" << endl;
	    else
	        cout << "0" << endl;
	}
	return 0;
}

bool checkBleak(int n){
    int k = 0;
    for(int i=1;i<=n;i++){
        int k = i + countSetBits(i);
        if(k == n)
            return false;
    }
    return true;
}

int countSetBits(int n){
    // using brian karnighan's algorithm
    int count = 0;
    while(n > 0){
        n = n & (n-1);
        count++;
    }
    return count;
}