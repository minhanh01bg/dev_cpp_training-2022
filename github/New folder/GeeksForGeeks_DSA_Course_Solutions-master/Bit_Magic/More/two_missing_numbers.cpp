#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void findTwoMissingNumbers(int arr[], int n);

int main() 
{
	int arr[MAX], n;

    scanf("%d", &n);
    for(int i=0;i<n-2;i++){
        scanf("%d", &arr[i]);
    }

	findTwoMissingNumbers(arr, n);
	return 0; 
}

void findTwoMissingNumbers(int arr[], int n) 
{ 
	/* Get the XOR of all elements in arr[] and 
	{1, 2 .. n} */
	int XOR = arr[0]; 
	for (int i = 1; i < n-2; i++) 
		XOR ^= arr[i]; 
	for (int i = 1; i <= n; i++) 
		XOR ^= i; 

	// Now XOR has XOR of two missing elements. Any set 
	// bit in it must be set in one missing and unset in 
	// other missing number 

	// Get a set bit of XOR (We get the rightmost set bit) 
	int set_bit_no = XOR & ~(XOR-1); 

	// Now divide elements in two sets by comparing rightmost 
	// set bit of XOR with bit at same position in each element. 
	int x = 0, y = 0; // Initialize missing numbers 
	for (int i = 0; i < n-2; i++) // traversing elements in arr[]
	{ 
		if (arr[i] & set_bit_no) 
			x = x ^ arr[i]; /*XOR of first set in arr[] */
		else
			y = y ^ arr[i]; /*XOR of second set in arr[] */
	} 
	for (int i = 1; i <= n; i++) // traversing elements from 1 to n
	{ 
		if (i & set_bit_no) 
			x = x ^ i; /* XOR of first set in arr[] and 
						{1, 2, ...n }*/
		else
			y = y ^ i; /* XOR of second set in arr[] and 
						{1, 2, ...n } */
	} 

	printf("Two Missing Numbers are %d %d.\n", x, y); 
}
