//1
//2 => 4 => 8 => 6 => 2
//3 => 9 => 7 => 1 => 3
//4 => 6 => 4 => 6 => 4
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string a;
        cin>>a;
        string b="";
        b+=a[a.length()-1];
        if (a.length()>1) b+=a[a.length()-2];
        reverse(b.begin(), b.end());
        int k=stoi(b);
        (k%4==0) ? cout<<4<<endl : cout<<0<<endl;
    }
}
