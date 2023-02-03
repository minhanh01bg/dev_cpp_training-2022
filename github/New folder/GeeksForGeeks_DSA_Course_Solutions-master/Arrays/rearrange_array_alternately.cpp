#include <bits/stdc++.h>
using namespace std;

void rearrange(int *arr, int n);

int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 



/*This is a function problem.You only need to complete the function given below*/
// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(int *arr, int n) 
{ 
    int max_index, min_index, max_element;
    
    min_index = 0;
    max_index = n-1;
    
    max_element = arr[n-1] + 1; //can be any number greater the maximun in the array

    /* This solution uses the technique of multiplication and modulus. 
        After this,
        arr[i] += (arr[max_index] % max_element) * max_element

        If we do arr[i]/max_element, we get the new element back whereas 
        if we do arr[i]%max_element we get the original element back.
     */
    
    for(int i=0;i<n;i++) {
        if(i%2 == 0) {
            //even places
            arr[i] += (arr[max_index] % max_element) * max_element;
            max_index--;
        }else{
            //odd places
            arr[i] += (arr[min_index] % max_element) * max_element;
            min_index++;
        }
    }
    
    for(int i=0;i<n;i++) {
        arr[i] = arr[i]/max_element;
    }
}