bool checkRotatedAndSorted(int a[], int n){
    int min = INT_MAX, max = INT_MIN, minIndex, maxIndex;
    
    // get max and min elements
    for(int i=0;i<n;i++) {
        if(a[i] > max) {
            max = a[i];
            maxIndex = i;
        }
        
        if(a[i] < min) {
            min = a[i];
            minIndex = i;
        }
    }
    
    // if array is sorted in ascending order
    if((minIndex - maxIndex) == 1) {
        for(int i=1;i<minIndex;i++) {
            if(a[i-1] > a[i]) {
                return false;
            }
        }
        
        for(int i=minIndex+1;i<n;i++) {
            if(a[i-1] > a[i]) {
                return false;
            }
        }
        
        if(a[n-1] < a[0]) {
            // handles edge cases
            return true;
        }else{
            return false;
        }
    }
    // if array is sorted in descending order
    else if((minIndex - maxIndex) == -1) {
        for(int i=1;i<maxIndex;i++) {
            if(a[i-1] < a[i]) {
                return false;
            }
        }
        
        for(int i=maxIndex+1;i<n;i++) {
            if(a[i-1] < a[i]) {
                return false;
            }
        }
        
        if(a[n-1] > a[0]) {
            // handles edge cases
            return true;
        }else{
            return false;
        }
    }
    else{
        // not sorted and rotated
        return false;
    }
}