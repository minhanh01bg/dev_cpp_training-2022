#include <iostream>
using namespace std;
long n, m, a[100001];
long PREV[100001], NEXT[100001];
main()
{
	cin >> n >> m;
	NEXT[0] = 1;
	for (long i = 1; i <= n; i++)
	{
		a[i] = i;
		PREV[i] = i - 1;
		NEXT[i] = i + 1;
	}
	long ik, jk;
	for (long k = 1; k <= m; k++)
	{
		cin >> ik >> jk;
		PREV[NEXT[ik]] = PREV[ik];
		NEXT[PREV[ik]] = NEXT[ik];
		PREV[ik] = PREV[jk];
		NEXT[ik] = jk;
		NEXT[PREV[jk]] = ik;
		PREV[jk] = ik; 
	}
	long k = NEXT[0];
	while (k <= n)
	{
		cout << k << " ";
		k = NEXT[k];
	}
}