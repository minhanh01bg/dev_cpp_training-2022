#include <iostream>
using namespace std;

void binSort(int A[], int N);

int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}


void binSort(int arr[], int n)
{
    //implementing lomuto partition
    int i = -1; //keeps track of 0 segment
    
    for(int j=0;j<n;j++){
        if(arr[j] == 0){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
}