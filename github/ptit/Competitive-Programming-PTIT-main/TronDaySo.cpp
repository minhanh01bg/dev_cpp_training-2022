#include <bits/stdc++.h>
using namespace std;
int M=1e9+7;
int main()
{
    long long C[102][102];
    memset(C,0,sizeof(C));
    for (int i=1; i<102; i++)
    {
        for (int j=1; j<102; j++)
        {
            if (j==1) C[i][j]=1;
            else C[i][j]=(C[i][j-1]+C[i-1][j])%M;
        }
    }
    int N;
    cin>>N;
    while (N--)
    {
        int a,b;
        cin>>a>>b;
        cout<<C[a+1][b+1]<<endl;
    }
}
// 0 1111 - 1 111 - 11 11- 111 1 - 1111 0
