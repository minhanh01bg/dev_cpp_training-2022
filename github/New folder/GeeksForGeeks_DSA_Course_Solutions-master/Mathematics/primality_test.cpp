#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
bool isPrime(int N);
int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n
        
        if(isPrime(N)) 
        cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}
//User function Template for C++
//You need to complete this function
bool isPrime(int N)
{
    if(N <= 1)
        return false;
    if(N == 2)
        return true;
    if(N % 2 == 0)
        return false;
        
    for(int i=3;i<=sqrt(N);i+=2){
        if(N % i == 0)
            return false;
    }
    return true;
}