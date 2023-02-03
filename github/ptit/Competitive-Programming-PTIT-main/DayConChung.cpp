#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while (N--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long N[a];
        long long M[b];
        long long K[c];
        long long it, it2;
        for (long long i=0; i<a; i++) cin>>N[i];
        for (long long i=0; i<b; i++) cin>>M[i];
        for (long long i=0; i<c; i++) cin>>K[i];
        sort(N,N+a);
        sort(M,M+b);
        sort(K,K+c);
        int token=0;
        int N1=0, M1=0, K1=0;
        while (N1<a && M1<b && K1<c)
        {
            if (N[N1]<M[M1])
            {
                N1++;
                continue;
            }
            if (N[N1]>M[M1])
            {
                M1++;
                continue;
            }
            if (K[K1]<M[M1])
            {
                K1++;
                continue;
            }
            if (K[K1]>M[M1])
            {
                M1++;
                continue;
            }
            if (N[N1]<K[K1])
            {
                N1++;
                continue;
            }
            if (N[N1]>K[K1])
            {
                K1++;
                continue;
            }
            cout<<N[N1]<<' ';
            token=1;
            N1++;
            K1++;
            M1++;
        }
        if (token==0) cout<<"NO";
        cout<<endl;
    }
}
