#include<bits/stdc++.h> 
using namespace std; 

void printfrequency(int arr[], int n);

int main() 
{ 
	long long t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n; // taking input size of array
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; // input elements of array
	    }
	    
	    printfrequency(arr,n); // print frequency of elements 
	    cout << endl;
	}
	
	return 0; 
}



/*This is a function problem.You only need to complete the function given below*/
// Function to count frequencies of elements in the array
// arr: input array
// n: size of array
void printfrequency(int arr[], int n)
{ 
    int i;
    
    /* This solution add n to keep track of counts*/
    
    /*Subtract 1 from every element so that the elements
    become in range from 0 to n-1*/
	for(i=0; i<n; i++)
	    arr[i] = arr[i]-1;
	
	/*Use every element arr[i] as index and add 'n' to
    element present at arr[i]%n to keep track of count of
    occurrences of arr[i]*/
	for(i=0; i<n; i++)
	    arr[arr[i]%n] = arr[arr[i]%n] + n;
        
    /*To print counts, simply print the number of times n
    was added at index corresponding to every element*/
    for(i=0; i<n; i++)
        cout << arr[i]/n << " ";
} 
