#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

void findDuplicates(int arr[], int n);

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
	    findDuplicates(arr, n);
	}
	return 0;
}

void findDuplicates(int arr[], int n){
    // int count[n];
    // memset(count, 0, sizeof(count));
    // I don't know why the above stuff doesn't work
    int *count = new int[sizeof(int) * n];

    for(int i=0;i<n+2;i++){
        if(count[arr[i]] == 1){
            printf("%d ", arr[i]);
        }else{
            count[arr[i]]++;
        }
    }
    printf("\n");
}

/* // using XOR
   // insertion order cannot be maintained in output
void findDuplicates(int arr[], int n){
    int i, xorResult;
    
    xorResult = arr[0];
    for(i=1;i<n+2;i++){
        xorResult = xorResult ^ arr[i];
    }
    for(i=1;i<=n;i++){
        xorResult = xorResult ^ i;
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
    
    for(i=1;i<=n;i++){
        if(i & set_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }

    printf("%d %d\n", x, y);
} */