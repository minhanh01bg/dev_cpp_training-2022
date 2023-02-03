#include <iostream>
using namespace std;

int main() {
    int t, count = 0;
    unsigned long long int n;
    scanf("%d", &t);
    while(t--){
        scanf("%llu", &n);
        // we use brian karnighan algorithm
        // Subtraction of 1 from a number toggle all the bits 
        // after the rightmost set bit(including 
        // the rightmost set bit). So if we subtract a number by 1 
        // and do bitwise & with itself (n & (n-1)), we unset the 
        // rightmost set bit. If we do n & (n-1) in a loop and count
        // the no of times loop executes we get the set bit count.
        while(n > 0){
            n = n & (n - 1);
            count++;
        }
        printf("%d\n", count);
        count = 0;
    }
	return 0;
}
