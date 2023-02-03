#include<bits/stdc++.h>
using namespace std;

int digitsInFactorial(int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<digitsInFactorial(N)<<endl;
    }
    return 0;
}

int digitsInFactorial(int N)
{
    double digits = 0;
    if(N<=1)
        return N;
        
    for(int i=2;i<=N;i++){
        digits += log10(i);
    }
    return floor(digits) + 1;
    //time complexity - O(n)
}