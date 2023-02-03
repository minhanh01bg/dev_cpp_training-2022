#include <bits/stdc++.h>
using namespace std;

void insertAtIndex(int arr[],int sizeOfArray,int index,int element);

int main() {
    int t;
    cin>>t;//Input testcases
    while(t--)
    {
        int sizeOfArray; 
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray-1;i++)
        cin>>arr[i];
        
        int index;
        cin>>index;
        int element;
        cin>>element;
        
        insertAtIndex(arr,sizeOfArray,index,element); //Complete this function
        
        for(int i=0;i<sizeOfArray;i++)//Printing the array for verification
        cout<<arr[i]<<" ";
        
        cout<<endl;
        
    }
    
	return 0;
}

void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
{
    if(index == (sizeOfArray-1)) //insert at end
        arr[sizeOfArray-1] = element;
    else{
        // make room for new element
        for(int i=sizeOfArray-1 ;i>=index; i--){
           arr[i] = arr[i-1];
        }
        // insert at the specified index
        arr[index] = element;
    }
}