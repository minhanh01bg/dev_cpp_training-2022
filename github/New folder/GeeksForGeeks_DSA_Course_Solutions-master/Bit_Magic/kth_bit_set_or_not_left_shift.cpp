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
	// left shift 1 by k 
	// if that number matches n
	// that means doing & operation
	// between them must give a non-zero int
	// therefore results true
    if(n & (1 << k))
        return true;
    else
        return false;
}