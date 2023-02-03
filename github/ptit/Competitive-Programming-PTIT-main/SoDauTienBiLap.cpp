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
        int it;
        string k = "NO";
        for (int i=0; i<a; i++) cin>>C[i];
        for (int i=0; i<a-1; i++)
        {
            it = find (C+i+1, C+a, C[i]) - C;
            if (it<a)
            {
                k = to_string(C[i]);
                break;
            }
        }
        cout<<k<<endl;
    }
}
