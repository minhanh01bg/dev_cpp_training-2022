#include<bits/stdc++.h>
using namespace std;

int remove_duplicate(int [],int );

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }

    int n = remove_duplicate(a,sizeof(a)/sizeof(a[0]));

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}


int remove_duplicate(int a[],int n)
{
    int i = 0, j;
    
    for(j=1;j<n;j++) {
        if(a[i] != a[j]) {
            a[++i] = a[j];
        }
    }
    
    return i+1;
}