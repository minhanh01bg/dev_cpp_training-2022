#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

void twoOddOccuring(int arr[], int n);

int main(void)
{
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[MAX];
	    for(int i=0;i<n+2;i++){
	        cin>>arr[i];
	    }
	    twoOddOccuring(arr, n);
	}
	return 0;
}

// using XOR
void twoOddOccuring(int arr[], int n){
    int i, xorResult;
    
    xorResult = arr[0];
    for(i=1;i<n+2;i++){
        xorResult = xorResult ^ arr[i];
    }
    
    // get the rightmost set bit
    int set_bit = xorResult & ~(xorResult - 1);
    
    //initialize two nos: x and y
    int x = 0, y = 0;
    
    for(i=0;i<n+2;i++){
        if(arr[i] & set_bit)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }

    printf("%d %d\n", x, y);
}