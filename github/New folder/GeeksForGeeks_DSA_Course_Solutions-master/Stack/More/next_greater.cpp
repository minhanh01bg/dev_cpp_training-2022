vector <long long> nextLargerElement(long long a[], int n){
    stack<long long> s; //stores indexes
    vector<long long> v(n, -1); // size n, filled with -1
    
    for(int i=0;i<n;i++) {
        
        if(s.empty()) {
            s.push(i);
        }
        
        else {
            while(!s.empty() && a[i] > a[s.top()]) {
                v[s.top()] = a[i];
                s.pop();
            }
            
            s.push(i);
        }
    }
    
    return v;
}