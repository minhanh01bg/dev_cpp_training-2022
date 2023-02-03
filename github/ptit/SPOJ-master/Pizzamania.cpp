#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int bin(int a[],int i,int m,int l,int u)
{
     int mid;
     if(l<=u)
    {
          mid=(l+u)/2;
          if(m==a[mid] && mid!=i)
              return 1;
          else if(m<a[mid])
              return bin(a,i,m,l,mid-1);
          else
              return bin(a,i,m,mid+1,u);
     }
       return 0;
}
int main()
{
	int t,m,n,i,ans;
    scanf("%d",&t);;
    while(t--)
    {
    ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
    ans=ans+bin(a,i,m-a[i],i,n-1);
    printf("%d\n",ans);
    }
	return 0;
}

