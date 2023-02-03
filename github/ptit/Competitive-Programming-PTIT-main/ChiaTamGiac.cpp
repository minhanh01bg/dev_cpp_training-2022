#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        double a,b;
        cin>>a>>b;
        int c=a;
        for (int i=1; i<c; i++)
        {
            double k = b * sqrt(i/a);
            cout<<setprecision(6)<<fixed<<k<<' ';
        }
        cout<<endl;
    }
}
