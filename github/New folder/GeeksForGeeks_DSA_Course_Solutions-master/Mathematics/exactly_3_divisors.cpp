#include <bits/stdc++.h>
using namespace std;

int exactly3Divisors(int n);

int main()
 {
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<exactly3Divisors(N)<<endl;
    }
	return 0;
}

int exactly3Divisors(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    
    prime[0] = prime[1] = false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i] == true){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }
    
    int count = 0;
    for(int i=1;i<=sqrt(n);i++){
        if(prime[i])
            count++;
    }
    
    return count;
}