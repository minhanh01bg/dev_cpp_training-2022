#include <stdio.h>
using namespace std;

int main() {
    int N;
    int tmp;
    int X = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &tmp);
        X = X ^ tmp;    //xor
    }
    printf("%d\n", X);
    return 0;
}
