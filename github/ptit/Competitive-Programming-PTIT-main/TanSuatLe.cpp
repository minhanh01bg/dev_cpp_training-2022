#include <bits/stdc++.h>
using namespace std;
int main()
{
	int M=1e7+1;
    int C[M];
    int N;
    cin>>N;
    while (N--)
    {
        memset(C,0,sizeof(C));
        int a;
        cin>>a;
        int F[a];
        for (int i=0; i<a; i++)
        {
            cin>>F[i];
            C[F[i]]++;
        }
        for (int i=0; i<a; i++)
        {
            if (C[F[i]]%2==1)
            {
                cout<<F[i]<<endl;
                break;
            }
        }
    }
}
