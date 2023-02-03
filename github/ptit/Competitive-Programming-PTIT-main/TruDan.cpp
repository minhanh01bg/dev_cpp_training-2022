//bàn t?i uu => ngu?i d?u tiên th?ng => d?o v? trí
//bàn không t?i uu => ngu?i th? hai th?ng => không d?o v? trí
//1 - 1 => ngu?i d?u tiên th?ng
//2 - 1 => ngu?i th? hai th?ng
//2 - 2 => ngu?i d?u tiên th?ng
//Kí hi?u bàn t?i uu là 1, bàn không t?i uu là 0 => t?ng l?: ngu?i d?u tiên th?ng, t?ng ch?n: ngu?i th? hai th?ng
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
