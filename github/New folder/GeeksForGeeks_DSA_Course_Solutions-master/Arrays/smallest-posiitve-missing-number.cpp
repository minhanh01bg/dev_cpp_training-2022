int missingNumber(int a[], int n) { 
    
    int i = 0;
    
    while(i < n) {
        if(a[i] > 0 && a[i] <= n && a[i] != a[a[i] - 1]) {
            swap(a[i], a[a[i] - 1]);
        }else{
            i++;
        }
    }
    
    for(i=0;i<n;i++) {
        // the first index that does not have 'i' in its value
        if(a[i] != i+1) {
            return i+1;
        }
    }
    
    return n+1;
    
} 