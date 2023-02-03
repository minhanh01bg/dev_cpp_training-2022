#include <bits/stdc++.h>

using namespace std;

long long M = 1e15 + 7;

struct mat
{
	long long x,y;
	long long a[5][5];
};

long long multiply(long long a, long long b)
{
	string A = to_string(a);
	string B = to_string(b);
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	string C;
	C.resize(A.length()+B.length(),'0');
	for (int i=0; i<A.length(); i++)
	{
		int c = 0;
		for (int j=0; j<B.length(); j++)
		{
			c += ((A[i]-'0') * (B[j]-'0') + C[i+j] -'0');
			C[i+j] = (char)(c%10 + '0');
			c/=10;
		}
		if (c > 0) C[i + B.length()] += c;
	}
	long long re = 0;
	reverse(C.begin(),C.end());
	for (int i=0; i<C.length(); i++)
	{
		re = (re*10 + C[i] - '0')%M;
	}
	return re;
}

mat operator *(mat a, mat b)
{
	mat c = {a.x, b.y};
	for (int i=0; i<c.x; i++)
	{
		for (int j=0; j<c.y; j++) c.a[i][j] = 0;
	}
	for (int i=0; i<c.x; i++)
	{
		for (int j=0; j<c.y; j++)
		{
			for (int k=0; k<a.y; k++) c.a[i][j] = (c.a[i][j] + multiply(a.a[i][k], b.a[k][j])%M) %M;
		}
	}
	return c;
}

mat Power(mat a, int x)
{
	if (x==1) return a;
	mat k = Power(a, x/2);
	if (x%2==0) return k*k;
	return k*k*a;
}

int main() 
{
	long long T[5], F[5];
	for (int i=1; i<4; i++) T[i] = i;
	for (int i=1; i<4; i++) F[i] = F[i-1] + T[i];
	
	mat a;
	
	a.x = 4;
	a.y = 1;
	a.a[0][0] = F[3];
	a.a[1][0] = T[3];
	a.a[2][0] = T[2];
	a.a[3][0] = T[1];
	
	mat x;
	
	
	x.x = x.y = 4;
	x.a[0][0] = x.a[0][1] = x.a[0][2] = x.a[0][3] = 1ll;
	x.a[1][1] = x.a[1][2] = x.a[1][3] = 1ll;
	x.a[2][1] = x.a[3][2] = 1ll;
	
	mat ans;
	
	int N;
	cin>>N;
	while(N--)
	{
		long long a1;
		cin>>a1;
		if (a1<=3) 
		{
			cout<<F[a1]<<endl;
			continue;
		}
		ans = Power(x,a1-3) * a;
		// for (int i=0; i<5; i++)
		// {
		// 	for (int j=0; j<5; j++) cout<<ans.a[i][j]<<' ';
		// 	cout<<endl;
		// }
		cout<<ans.a[0][0]<<endl;
	}
}
