#include <cstdio>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
long long count(long long n)
{
long long i=0,ch=0;
while(i<n)
i+=pow(5,++ch);
return ch;
}
int main(void) {
	int t;
    long long n,g,i,j;
    scanf("%d",&t);
    string s="manku";
    while(t--)
    {
     string ch="";
     scanf("%lld",&n);
     g=count(n);
     for(i=0;i<g;i++)
     {
      j=n%5;
      if(j==0)
      j=5;
      ch=s[j-1]+ch;
      if(n%5==0)
      n=n/5-1;
      else
      n=n/5;
     }
     cout<<ch<<"\n";
     }
	return 0;
}
