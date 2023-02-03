// We need to use Kamenentsky's formula
// to count the digits of N!
// when the value of N is very large
// Formula: f(x) = log10( ((n/e)^n) * sqrt(2*pi*n))
// applying property of logarithms
// we get, f(x) = n * log10((n/ e)) + log10(2*pi*n)/2 

#include<bits/stdc++.h>
using namespace std;

long long countdigits(int n);

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld", countdigits(n));
    }
}

// Since the result can be large 
// long long is used as return type
long long countdigits(int n){
    if(n <= 1)
        return n;
    else
    {
        double x = ((n * log10(n / M_E)) + (log10(2 * M_PI * n) / 2.0)); 
        cout<<x<<endl;
        return floor(x) + 1;
    }
}