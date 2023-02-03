#include <bits/stdc++.h>
using namespace std;
int M=1e9+7;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int a,b;
        cin>>a>>b;
        if (a%(b+1)==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}
