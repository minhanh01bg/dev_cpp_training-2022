#include <bits/stdc++.h>
using namespace std;
int M=1e9+7;
int main()
{
    int N;
    cin>>N;
    int F[50001];
    while(N--)
    {
        memset(F,0,sizeof(F));
        int a;
        cin>>a;
        int C[a];
        for (int i=0; i<a; i++) cin>>C[i];
        sort(C,C+a);
        int key=-1;
        for (int i=0; i<a; i++) 
        {
            F[C[i]]++;
            if (C[i]>i)
            {
                key=0;
                break;
            }
        }
        if (key==0)
        {
            cout<<0<<endl;
            continue;
        }
        key=0;
        long long maximum=1;
        for (int i=0; i<a; i++)
        {
            if (F[i])
            {
                key+=F[i];
            }
            maximum=(maximum*key)%M;
            key--;
        }
        cout<<maximum<<endl;
    }
}
