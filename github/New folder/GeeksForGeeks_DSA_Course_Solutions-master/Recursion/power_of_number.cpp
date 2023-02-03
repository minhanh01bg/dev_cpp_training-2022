#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll unsigned long long

ll reverse(ll n);
long modPow(ll n, ll r);

int main(void)
{
	int t;
	ll n, r;
	cin >> t;
	while(t--){
	    cin >> n;
	    r = reverse(n);
	    cout << modPow(n, r) << endl;
	}
	return 0;
}

ll reverse(ll n){
    ll r = 0;
    int temp;
    while(n > 0){
        temp = n % 10;
        r = temp + (r * 10);
        n = n / 10;
    }
    return r;
}

long modPow(ll n, ll r){
    int result = 1;
    
    n = n % m;
    
    while(r > 0){
        if(r & 1){
            result = (n * result) % m;
        }
        
        r = r >> 1;
        n = (n * n) % m;
    }
    
    return result;
}

/**
 * // compute pow(n, R) with mod 1000000007
long long modfun(long long n, long long R)
{
    // Base cases 
    if (n == 0) 
        return 0; 
    if (R == 0)  //power zero mean answer is 1
        return 1; 
  
    // If R is even 
    long long y; 
    if (R % 2 == 0) { 
        y = modfun(n, R/2);  //finding r/2 power as power is even then storing answer in y and---
        y = (y * y) % mod; //---if power is even like 2^4 we can simply do (2^2)*(2^2)
    } 
  
    // If R is odd 
    else { 
        y = n % mod;  //if power is odd then ---
        y = (y * modfun(n, R - 1) % mod) % mod; //--- reduce the power by 1 to make it even. The reducing power
        //by one can be done if we take one n out. Like 2^3 can be written as 2*(2^2)
    } 
  
    return ((y + mod) % mod);  //finally return the answer (y+mod)%mod = (y%mod+mod%mod)%mod = (y%mod)%mod
}


long long power(int N,int R)
{
    return modfun(N,R)%mod;
    
}
**/