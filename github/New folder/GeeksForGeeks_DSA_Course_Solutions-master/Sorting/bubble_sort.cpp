#include <stdio.h>

void bubbleSort(int arr[], int n);
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

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
      
    bubbleSort(arr, n);
    printArray(arr, n);
    }
    return 0;;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swap_flag = false;

    for (i = 0; i < n-1; i++){
        for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    swap(&arr[i], &arr[j]);
                    swap_flag = true;
                }
            }
            if(swap_flag == false)
                break;
        }
}