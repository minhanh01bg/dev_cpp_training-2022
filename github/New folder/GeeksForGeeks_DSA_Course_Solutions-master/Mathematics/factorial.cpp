#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
long long factorial (int N);
int main()
{
    int T,N;
    cin>>T;  //input number of testcases
    while(T--)
    {
        cin>>N; //input n
        cout<<factorial(N)<<endl;
    }
    return 0;
}
//User function Template for C++
//Complete this function
long long factorial (int N)
{
    long long result = 1;
    for(int i=1;i<=N;i++){
        result *= i;
    }
    return result;
}
