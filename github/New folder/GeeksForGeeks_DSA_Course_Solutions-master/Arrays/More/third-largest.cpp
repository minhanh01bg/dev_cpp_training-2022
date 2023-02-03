int thirdLargest(int a[], int n)
{
    int max, smax, tmax;
    max = smax = tmax = -1;
    
    for(int i=0;i<n;i++) {
        if(a[i] > max) {
            tmax = smax;
            smax = max;
            max = a[i];
        }else if(a[i] > smax && a[i] != max) {
            tmax = smax;
            smax = a[i];
        }else if(a[i] > tmax && a[i] != max && a[i] != smax) {
            tmax = a[i];
        }
    }
    
    return tmax;
}