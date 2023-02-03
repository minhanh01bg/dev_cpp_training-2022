#include <iostream>
using namespace std;

long replaceZeros(long n);

int main() {
    long t, n;
    cin >> t;
    
    while(t--){
        cin>>n;
        cout << replaceZeros(n) << endl;
    }
	return 0;
}

long replaceZeros(long n){
    long temp, r=1, result=0;
    
    while(n!=0){
        temp = n%10;
        
        if(temp == 0){
            result = result + 5*r;
        }else{
            result = result + temp*r;
        }
        
        r=r*10;
        n=n/10;
    }
    return result;
}