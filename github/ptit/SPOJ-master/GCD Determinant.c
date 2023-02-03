#include<iostream>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;
int main()
{
	int n, i, j, a[1024], x[1024];
	long long ans;
	while(scanf("%d", &n)==1)
	{
		for(i = 0; i < n; i++) scanf("%d", &x[i]);
		sort(x, x + n);
		ans = a[0] = x[0];
		for(i = 1; i < n; i++) {
			a[i] = x[i];
			for(j = 0; j < i; j++) {
				a[i] -= (x[i] % x[j]? 0 : a[j]);
			}
			ans = ( ans * a[i] ) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
