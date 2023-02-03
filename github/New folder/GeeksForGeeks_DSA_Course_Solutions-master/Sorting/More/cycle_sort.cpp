#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

void CycleSort(int arr[], int n);

//utility function
void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int main(){
    int arr[MAX], n, t;

    cin >> t;
    while(t--){
        cin >> n;

        for(int i=0;i<n;i++)
            cin >> arr[i];
        
        CycleSort(arr, n);
        printArray(arr, n);
    }
}

void CycleSort(int arr[], int n){
    int pos, item;

    for(int cs=0; cs<=n-2; cs++){
        //initialize item as cycle starting point
        item = arr[cs];

        //find right position to put the item
        int pos = cs;
        for(int i=cs+1; i<n; i++){
            if(arr[i] < item){
                pos++;
            }
        }

        //if item is already at its correct position
        if(pos == cs){
            continue;
        }

        //ignore duplicate elements
        while(arr[pos] == item) {
            pos++;
        }

        //put the item at correct position
        if(pos != cs){
            swap(item, arr[pos]);
        }

        //rotate rest of the cycle
        while(pos != cs){
            //find right position to put the item
            pos = cs;
            for(int i=cs+1; i<n; i++){
                if(arr[i] < item){
                    pos++;
                }
            }

            //ignore duplicate elements
            while(arr[pos] == item) {
                pos++;
            }

            //put the item at correct position
            if(item != arr[pos]){
                swap(item, arr[pos]);
            }
        }
    }//end outer for loop
}