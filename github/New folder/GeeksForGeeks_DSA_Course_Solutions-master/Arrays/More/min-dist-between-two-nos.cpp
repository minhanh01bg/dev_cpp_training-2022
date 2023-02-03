int minDist(int a[], int n, int x, int y) {
    // we will only keep track of consecutive pairs
    // of x and y
    
    int mindist = INT_MAX, p = -1;
    
    for(int i=0;i<n;i++) {
        if(a[i] == x || a[i] == y) {
            
            if(p != -1 && a[i] != a[p]) {
                mindist = min(mindist, (i-p));
            }
            
            p = i;
        }
    }
    
    return mindist == INT_MAX ? -1 : mindist;
}