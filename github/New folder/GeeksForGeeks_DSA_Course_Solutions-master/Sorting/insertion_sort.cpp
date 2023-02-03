#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n);

void insert(int arr[], int i);

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
    insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++){
        int j=i-1, curr = arr[i];
        
        while(j>=0 && curr<arr[j]){
            arr[j+1] = arr[j]; //shifting previous elements and making room for the curr
            j--;
        }
        
        arr[j+1] = curr;
   }
}