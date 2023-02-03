int convertFive(int n) {
    int t, res = 0, d = 1;
    
    while(n != 0) {
        t = n % 10;
        t = t == 0 ? 5 : t;
        res = res + (t * d);
        d = d * 10;
        n = n / 10;
    }
    
    return res;
}