//b�n t?i uu => ngu?i d?u ti�n th?ng => d?o v? tr�
//b�n kh�ng t?i uu => ngu?i th? hai th?ng => kh�ng d?o v? tr�
//1 - 1 => ngu?i d?u ti�n th?ng
//2 - 1 => ngu?i th? hai th?ng
//2 - 2 => ngu?i d?u ti�n th?ng
//K� hi?u b�n t?i uu l� 1, b�n kh�ng t?i uu l� 0 => t?ng l?: ngu?i d?u ti�n th?ng, t?ng ch?n: ngu?i th? hai th?ng
#include <bits/stdc++.h>
using namespace std;
int M=1e9+7;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int a;
        cin>>a;
        int C[a], F[a];
        for (int i=0; i<a; i++) cin>>C[i];
        for (int i=0; i<a; i++) cin>>F[i];
        int sum=0;
        int sum2=0;
        int sum3=0;
        for (int i=0; i<a; i++)
        {
            sum = sum^(C[i]%(F[i]+1));
        }
        
        if (sum==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}
