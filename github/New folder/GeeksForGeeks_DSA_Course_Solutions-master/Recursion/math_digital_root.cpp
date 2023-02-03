/** This is a mathematical fact that a number 
 * that is divisible by 9 has a digital root 
 * equal to 9 and if it's not divisible by 9 then 
 * it's digital root is equal to (number % 9)
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;

    cin >> t;
    while(t--){
        cin >> n;
        if(n % 9 == 0){
            cout << "9" << endl;
        }else{
            cout << (n % 9) << endl;
        }
    }
    return 0;
}