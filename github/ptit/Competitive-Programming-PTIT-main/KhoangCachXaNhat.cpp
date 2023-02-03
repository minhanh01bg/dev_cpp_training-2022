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
        int C[a], F[a], K[a];
        for (int i=0; i<a; i++) cin>>C[i];
        F[0]=C[0];
        K[a-1]=C[a-1];
        for (int i=1; i<a; i++) F[i]=min(F[i-1], C[i]);
        for (int i=a-2; i>=0; i--) K[i]=max(K[i+1],C[i]);
        int F1=0, K1=0, maximum=0-a;
        while (F1<a && K1<a)
        {
            if (F[F1]<K[K1])
            {
                maximum=max(K1-F1, maximum);
                K1++;
            }
            else F1++;
        }
        cout<<maximum<<endl;
    }
}
