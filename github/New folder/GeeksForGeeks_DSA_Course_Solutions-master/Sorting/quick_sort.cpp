#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition (int arr[], int low, int high)
{
    //Lomuto partition
    
    int pivot = arr[high]; //last element
    int i = low-1; //index for smaller element window
    
    //j is the index for larger element window
    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    //put the pivot in its correct position
    swap(arr[i+1], arr[high]);
    return i+1;
}