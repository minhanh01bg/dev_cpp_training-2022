#include<iostream>
using namespace std;

int extendedGCD(int a, int b, int *x, int *y);
int modInverse(int b, int m);

int main()
{
	int T;
	cin>>T;
	while(T--){
		int a,m;
		cin>>a>>m;
		cout << modInverse(a, m)<<endl;
	}
    return 0;
}

int extendedGCD(int a, int b, int *x, int *y) 
{ 
	// Base Case 
	if(a == 0){ 
		*x = 0, *y = 1; 
		return b; 
	} 

	int x1, y1; // To store results of recursive call 
	int gcd = extendedGCD(b%a, a, &x1, &y1); 

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
}

int modInverse(int b, int m) 
{ 
	int x, y; // used in extended GCD algorithm
	int g = extendedGCD(b, m, &x, &y);

	// Return -1 if b and m are not co-prime 
	if (g != 1) 
		return -1; 

	// m is added to handle negative x 
	return (x%m + m) % m; 
} 