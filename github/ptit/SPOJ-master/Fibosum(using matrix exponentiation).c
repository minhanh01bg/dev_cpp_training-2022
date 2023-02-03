
#include<stdio.h>
#include<string.h>
#define CPY(d, s) memcpy(d, s, sizeof(s))

const long long MOD = 1000000007;
const long long base[2][2] = {{1, 1}, {1, 0}};
const long long unit[2][2] = {{1, 0}, {0, 1}};

// a = a * b
void mul(long long a[2][2], long long b[2][2])
{
	long long r[2][2];
	r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
	r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
	r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
	r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;
	CPY(a, r);
}

// r = base ^ n
void pwr(long long r[2][2], int n)
{
	long long b[2][2];
	CPY(r, unit);
	CPY(b, base);
	while(n > 0)
    {
		if(n & 1)
            mul(r, b);
		n >>= 1;
		mul(b, b);
	}
}

// nth fib % MOD
long long fibo(int n)
{
	long long r[2][2];
	if(!n) return 0;
	pwr(r, n-1);
	return r[0][0];
}

int main()
{
	int b, a, t;
	long long sa, sb, ans;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%d%d", &a, &b);
		sa = fibo(a + 1); // 0 to a-1
		sb = fibo(b + 2); // 0 to b
		ans = (sb - sa) % MOD;
		if(ans < 0)
            ans += MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
