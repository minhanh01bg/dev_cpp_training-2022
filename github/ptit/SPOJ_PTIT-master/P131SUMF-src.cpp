#include <iostream>
#include <string>
#include <algorithm>
#define ll long long 
#define x first
#define y second
using namespace std;
const ll mod = 1000000007;
const ll mod2 = 1000000009;
ll r, c, n;
char x[1001][1001];
string s[1005];
ll pow[1001], pow2[1001], Haxh2[1001][1001], Haxh[1001][1001], v[1001], v2[1001];
ll res;
typedef pair <ll, ll> record;
record q[1005];

void Init()
{
	//for (int i = 1; i <= c; i++) cout << s[i] << endl;
	n = c;
	pow[0] = 1;
	pow2[0] = 1;
	for (int i = 1; i <= r; i++)
	{
		pow[i] = pow[i - 1] * 26 % mod;
		pow2[i] = pow2[i - 1] * 26 % mod2;
	}
}

ll getHaxh(int k, int i, int j)
{
	return (Haxh[k][j] - Haxh[k][i - 1] * pow[j - i + 1] + mod * mod) % mod;
}

ll getHaxh2(int k, int i, int j)
{
	return (Haxh2[k][j] - Haxh2[k][i - 1] * pow2[j - i + 1] + mod2 * mod2) % mod2;
}

void tinhH(int k)
{
	string x = s[k];
	Haxh[k][0] = 0;
	for (int i = 1; i <= r; i++) Haxh[k][i] = (Haxh[k][i - 1] * 26 + x[i] - 'a') % mod;
}

void tinhH2(int k)
{
	string x = s[k];
	Haxh2[k][0] = 0;
	for (int i = 1; i <= r; i++) Haxh2[k][i] = (Haxh2[k][i - 1] * 26 + x[i] - 'a') % mod2;
}

int STOP()
{
	ll q2[1005];
	for (int i = 1; i <= n; i++) 
	{
		q[i].x = v[i];
		q[i].y = i;
	}
	for (int i = 1; i <= n; i++) q2[i] = v2[i];
	
	sort(q + 1, q + 1 + n);
	
	for (int i = 2; i <= n; i++)
	  if (q[i].x == q[i - 1].x && q2[q[i].y] == q2[q[i - 1].y]) return 1;
	
	  
	return 0;
}

void Xoa(int k)
{
	for (int i = 1; i <= n; i++) v[i] = getHaxh(i, k + 1, r);
	for (int i = 1; i <= n; i++) v2[i] = getHaxh2(i, k + 1, r);
}

void Process()
{
	for (int i = 1; i <= n; i++) tinhH(i);
	for (int i = 1; i <= n; i++) tinhH2(i);
	res = 0;
	for (int i = 1; i < r; i++)
	{
		Xoa(i);
		if (STOP()) break;
		res++;
	}
	return;
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	  for (int j = 1; j <= c; j++) cin >> x[i][j];
	for (int j = 1; j <= c; j++)
	{
		s[j] = "*";
		for (int i = 1; i <= r; i++) s[j] += x[i][j];
	}
	Init();	
	Process();	
	cout << res;
}