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
        int C[a];
        for (int i=0; i<a; i++) cin>>C[i];
        sort(C, C+a);
        int maximum=-1;
        int token=1;
        int key;
        for (int i=1; i<a; i++)
        {
            if (C[i]==C[i-1]) token++;
            else
            {
                if (token > maximum)
                {
                	key=i-1;
                	maximum=token;
                }
                token=1;
            }
        }
        if (token > maximum)
            {
               	key=a-1;
                maximum=token;
            }
        if (maximum>(a/2)) cout<<C[key]<<endl;
        else cout<<"NO"<<endl;
    }
}
