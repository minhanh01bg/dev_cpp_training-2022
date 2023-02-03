#include<bits/stdc++.h> 
using namespace std; 

// Generate all prime numbers less than num. 
bool SieveOfEratosthenes(int num, bool isPrime[]) 
{ 
    //0 and 1 are not primes
	isPrime[0] = isPrime[1] = false; 
	
	for(int i=2; i<=num; i++) 
		isPrime[i] = true; 

	for(int p=2; p*p<=num; p++) 
	{ 
		if (isPrime[p] == true) 
		{ 
			// Update all multiples of p 
			for (int i=p*p; i<=num; i += p) 
				isPrime[i] = false; 
		} 
	} 
} 

void findPrimePair(int num) 
{ 
	bool isPrime[num+1]; 
	SieveOfEratosthenes(num, isPrime); 

	// Traversing all numbers to find first 
	// pair 
	for (int i=0; i<num; i++) 
	{ 
	    //this problem is based on Goldbach's conjecture statement that says
	    //Every even integer greater than 2 can be expressed as the sum of two primes
		if (isPrime[i] && isPrime[num-i]) 
		{ 
			cout << i << " " << (num-i) << endl; 
			return; 
		} 
	} 
} 

int main() 
{ 
	int num, t; 
	cin >> t;
	
	while(t--){
	    cin >> num;
	    findPrimePair(num); 
	}

	return 0; 
} 