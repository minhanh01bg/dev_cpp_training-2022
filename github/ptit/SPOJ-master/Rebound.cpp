#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;
int main()
{
	int t;
	long long x, y, z, r, a, b, d;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%lld %lld %lld", &x, &y, &z);
		d = x*x + y*y + 2*y*z;
		r = (long long)sqrt((double)d);
		if(r*r != d)
            printf("Not this time.\n");
		else
        {
			a = x*z + z*r;
			b = y + 2*z;
			if(a % b)
                printf("Not this time.\n");
			else
                printf("%lld\n", a / b);
		}
	}
	return 0;
}
