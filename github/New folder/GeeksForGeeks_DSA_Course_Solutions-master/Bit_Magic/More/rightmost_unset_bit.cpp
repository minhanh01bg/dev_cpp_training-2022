#include<bits/stdc++.h>
using namespace std;

int check(int n);
bool allSetBits(int n);
int getRightmostSetBit(int n);

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << check(n) << endl;
    }
}

/**
    If n = 0, return 1.
    If all bits of n are set, return -1.
    Else perform bitwise not on the given number(operation equivalent to 1’s complement).
    Let it be num = ~n.
    Get the position of rightmost set bit of num.
    This will be the position of rightmost unset bit of n.
*/
int check(int n){
    if(n == 0)
        return 1;
    
    if(allSetBits(n))
        return -1;
    
    return getRightmostSetBit(~n);
}

bool allSetBits(int n){
    if(n == 0)
        return false;
    while(n > 0){
        if((n & 1) == 0){
            return false;
        }
        n = n >> 1;
    }
    return true;
}

int getRightmostSetBit(int n){
    return (log2(n & -n) + 1);
}