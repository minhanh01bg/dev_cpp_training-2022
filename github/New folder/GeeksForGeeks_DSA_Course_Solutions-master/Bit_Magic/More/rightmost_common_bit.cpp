#include<bits/stdc++.h>
using namespace std;

int rightmostUnsetBit(int n);
bool allSetBits(int n);
int getRightmostSetBit(int n);

int main(){
    int t, m, n;
    cin >> t;
    while(t--){
        scanf("%d %d", &m, &n);
        int xorResult = m ^ n;
        cout << rightmostUnsetBit(xorResult) << endl;
    }
}

int rightmostUnsetBit(int n){
    if(n == 0)
        return 1;
    
    /* if(allSetBits(n))
        return -1; */
    
    return getRightmostSetBit(~n);
}

int getRightmostSetBit(int n){
    return (log2(n & -n) + 1);
}

/* bool allSetBits(int n){
    if(n == 0)
        return false;
    while(n > 0){
        if((n & 1) == 0){
            return false;
        }
        n = n >> 1;
    }
    return true;
} */