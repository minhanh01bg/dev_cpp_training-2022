#include<bits/stdc++.h>
using namespace std;

double termOfGP(int A,int B,int N);

int main()
{
    int T; 
    cin>>T;
    for(int i=0;i<T;i++) 
    {
        int A,B;
        cin>>A>>B; 
        int N;
        cin>>N;
        
        cout<<floor(termOfGP(A,B,N))<<endl;
    }
    return 0;
}

double termOfGP(int A,int B,int N)
{
    double r = ((double) B)/A; // the trick is here
    return A * pow(r, N-1);
}