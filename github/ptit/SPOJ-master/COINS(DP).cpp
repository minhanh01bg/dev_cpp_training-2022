#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<long long,long long> mp;
long long coins(long long n)
{
	if(n==0)
	return 0;
	if(mp.count(n))
	return mp[n];
	mp[n]=max(n,(coins(n/2)+coins(n/3)+coins(n/4)));
	return mp[n];
}
int main(void)
{
	long long n;
	while(cin>>n)
		cout<<coins(n)<<"\n";
	return 0;
}
