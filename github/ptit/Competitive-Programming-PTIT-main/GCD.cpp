#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int a;
        cin>>a;
        int C[a];
        int F[a+1];
        for (int i=0; i<a; i++) cin>>C[i];
        F[0]=C[0];
        for (int i=1; i<a; i++) F[i]=__detail::__lcm(C[i],C[i-1]);
        F[a]=C[a-1];
        for (int i=0; i<a+1; i++) cout<<F[i]<<' ';
        cout<<endl;
    }
}
