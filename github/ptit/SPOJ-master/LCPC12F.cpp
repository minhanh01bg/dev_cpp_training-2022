#include<iostream>
using namespace std;

long long a[1000001];
int main()
{
int t;
long long n,x,i,d,j=1,cnt;
cin>>t;
while(t--)
{
    cnt=0;
    cin>>x;
    cin>>n;
    for(i=0;i<1000001;i++)
    a[i]=0;
    for(i=0;i<n;i++)
    {
        cin>>d;
        if(x-d>=0)
          cnt+=a[x-d];
        a[d]++;
    }
    cout<<j<<". "<<cnt<<"\n";
    j++;
}
return 0;
}
