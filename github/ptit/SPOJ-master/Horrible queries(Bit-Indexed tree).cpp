#include<iostream>
#include<cstdio>
using namespace std;
long long ft1[1000001];
long long ft2[1000001];

long long sum(long long ft[],long long idx)
{
    long long s=0;
    while (idx>0)
    {
        s=s+ft[idx];
        idx-=(idx & -idx);
    }
    return s;
}
void update(long long ft[],long long size,long long idx ,long long val)
{
    while (idx<=size)
    {
        ft[idx]+=val;
        idx += (idx & -idx);
    }
}
void range_update(long long ft1[],long long ft2[],long long size,long long a,long long b,long long v){
	 update(ft1,size, a, v);
     update(ft1,size, b + 1, -v);
     update(ft2,size, a, v * (a-1));
     update(ft2,size, b + 1, -v * b);
}
int main()
{
    int t;
    long long n,q,i,h,k,l,s,idx,p;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=0; i<=n; i++)
        {
            ft1[i]=0;
            ft2[i]=0;
        }
        for(i=0; i<q; i++)
        {
            cin>>c>>l>>h;
            if(c=='0'){
                cin>>k;
                range_update(ft1,ft2,n,l,h,k);
            }
            else
            {
                    s=sum(ft1,h)*h- sum(ft2,h)-sum(ft1,l-1)*(l-1)+sum(ft2,l-1);
                cout<<s<<"\n";
            }
        }
    }
    return(0);
}
