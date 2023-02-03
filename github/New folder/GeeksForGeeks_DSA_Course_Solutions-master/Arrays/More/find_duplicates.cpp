#include <bits/stdc++.h>
using namespace std;

void printDuplicates(int arr[], int n);

int main()
{
  int t;
  cin>>t;
  while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		printDuplicates(a, n);
		cout<<endl;
  }
  return 0;
}


void printDuplicates(int arr[], int n)
{
    int flag=0;
    
    for(int i=0;i<n;i++){
        int index = arr[i]%n;
        arr[index] += n;
        
        if((arr[index]/n) == 2){ //2 because we don't want to repeat any duplicates in output
            flag = 1;
            cout << index << " ";
        }
    }
    
    if(flag == 0)
        cout << "-1";
}