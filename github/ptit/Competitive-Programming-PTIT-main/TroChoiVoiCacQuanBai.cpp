#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int XOR=(a^b)^c;
        if (XOR==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}
