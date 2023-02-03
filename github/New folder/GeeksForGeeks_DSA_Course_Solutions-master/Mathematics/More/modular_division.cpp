#include<bits/stdc++.h> 
using namespace std; 

void modDivide(int a, int b, int m);
int modInverse(int b, int m);
int extendedGCD(int a, int b, int *x, int *y);

int main(void){
	int t, a, b, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &m);
		modDivide(a, b, m);
	}
}

// Function to compute a / b under m
void modDivide(int a, int b, int m) 
{ 
	// Formula: (a / b) % m = ((a % m) * (b ^ -1 % m)) % m
	a = a % m; 
	int inv = modInverse(b, m); 
	if(inv == -1)
		printf("Division not possible.");
	else
		printf("Result: %d\n", (a * inv) % m); 
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