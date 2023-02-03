#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while (N--)
    {
        int a;
        cin>>a;
        int C[a], F[a], K[a];
        for (int i=0; i<a; i++) cin>>C[i];
        F[0]=1;
        K[a-1]=1;
        int total=0-a;
        for (int i=1; i<a; i++)
        {
            if (C[i]>C[i-1]) F[i] = F[i-1] + 1;
            else F[i] = 1;
        }
        for (int i=a-2; i>=0; i--)
        {
            if (C[i]>C[i+1]) K[i] = K[i+1] + 1;
            else K[i] = 1;
        }
        for (int i=0; i<a; i++) total = max(total, F[i]+K[i]);
        cout<<total-1<<endl;
    }
}
