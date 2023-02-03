#include <cstdio>
using namespace std;
long long gcd(long long a, long long b)
{
	if(!b)
        return a;
	return
    gcd(b, a%b);
}
void f(long long n, long long &l, long long &h)
{
	if(n==1)
        l=h=1;
	else
	{
		f(n/2,l,h);
		(n&1)? (l=l+h) : (h=h+l);
	}
}

int main()
{
	long long a, b, l1, l2, h1, h2, g;
	while(scanf("%lld%lld", &a, &b)==2 && (a+b))
	{
		f(a, l1, h1);
		f(b, l2, h2);
		g = gcd(l1, h2);
		printf("%lld/%lld\n", l1/g, h2/g);
	}
	return 0;
}

