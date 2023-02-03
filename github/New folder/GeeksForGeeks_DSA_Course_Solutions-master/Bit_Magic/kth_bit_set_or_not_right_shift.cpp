#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    if(checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}

bool checkKthBit(int n, int k){
	// right shift n by k
	// then do & with 1
	// if rightmost bit is 1
	// it will return a non-zero int
	// therefore results true
    if((n >> k) & 1)
        return true;
    else
        return false;
}