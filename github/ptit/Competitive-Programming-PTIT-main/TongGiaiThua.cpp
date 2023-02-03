#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long C[21];
    memset(C,0,sizeof(C));
    C[0]=1;
    C[1]=1;
    for (long long i=2; i<21; i++) C[i]=i*C[i-1];
    long long X[21];
    memset(X,0,sizeof(X));
    X[1]=C[1];
    for (int i=2; i<21; i++) X[i]=C[i]+X[i-1];
    int a;
    cin>>a;
    cout<<X[a]<<endl;
}
