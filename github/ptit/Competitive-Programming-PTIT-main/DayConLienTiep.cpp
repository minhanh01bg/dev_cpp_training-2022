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
        long long sum=0;
        long long max_of_all=0;
        for (int i=0; i<a; i++)
        {
            sum+=C[i];
            max_of_all = max(sum, max_of_all);
            if (sum<0) sum=0;
        }
        cout<<max_of_all<<endl;
    }
}
