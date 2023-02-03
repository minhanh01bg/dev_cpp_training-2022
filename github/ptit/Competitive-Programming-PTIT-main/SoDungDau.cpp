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
        long long C[a];
        for (int i=0; i<a; i++) cin>>C[i];
        long long F[a];
        F[a-1]=C[a-1];
        vector<int> K;
        K.clear();
        K.push_back(C[a-1]);
        for (int i=a-2; i>=0; i--)
        {
            if (C[i]>F[i+1])
            {
                F[i]=C[i];
                K.push_back(C[i]);
            }
            else F[i]=F[i+1];
        }
        for (int i=K.size()-1; i>=0; i--) cout<<K[i]<<' ';
        cout<<endl;
    }
}
