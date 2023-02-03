#include <bits/stdc++.h>
using namespace std;
vector<long long> C;
map<long long,bool> bool1, bool2;
long long N, M, K1;
bool check(long long i, long long j)
{
    return (C[i-1]<C[j-1]);
}
vector<long long> printIntersection(vector<long long> arr1, vector<long long> arr2, long long n1, long long n2)
{
    set<long long> hs;
	vector<long long> re;
    for (long long i = 0; i < n1; i++) hs.insert(arr1[i]);
    for (long long i = 0; i < n2; i++) if (hs.find(arr2[i]) != hs.end()) re.push_back(arr2[i]);
    return re;
}
int main()
{
	cin>>N>>M>>K1;
	C.resize(N);
	for (long long i=0; i<N; i++) cin>>C[i];
	long long A;
	cin>>A;
	long long token;
	vector<long long> F(A);
	for (long long i=0; i<A; i++) 
	{
	    cin>>token;
		F[i]=token;
	    if (token <= 0 || token > N) 
	    {
	        A--;
	        i--;
	        F.pop_back();
	    }
	}
	sort(F.begin(),F.end(),check);
	long long B=-1;
	cin>>B;
	if ( M < K1 || K1 > N || N < M || K1 > A || K1 > B)
	{
		cout<<-1;
		return 0;
	}
	vector<long long> K(B);
	for (long long i=0; i<B; i++) 
	{
	    cin>>token;
	    K[i]=token;
	    if (token <= 0 || token > N) 
	    {
	        B--;
	        i--;
	        K.pop_back();
	    }
	}
	sort(K.begin(),K.end(),check);
	vector<long long> re = printIntersection(F,K,F.size(),K.size());
	sort(re.begin(),re.end(),check);
	for (long long i=0; i<re.size(); i++) bool1[re[i]-1] = true;
	long long save = K1;
	K1=save;
	long long take = max(0LL, 2LL*K1 - M);
	if (take > re.size())
	{
		cout<<-1;
		return 0;
	}
	long long total = 0;
	for (int i=0; i<take; i++)
	{
		if (bool2[re[i]-1]) continue;
		total += C[re[i]-1];
		bool2[re[i]-1] = true;
		C[re[i]-1] = INT_MIN;
		K1--;
		M--;
	}
	long long X1 = K1, X2 = K1;
	for (int i=0; i<F.size(); i++)
	{
		if (X1<=0) break;
		if (bool2[F[i]-1]) continue;
		total += C[F[i]-1];
		bool2[F[i]-1] = true;
		if (bool1[F[i]-1]) X2--;
		C[F[i]-1] = INT_MIN;
		X1--;
		M--;
	}
	for (int i=0; i<K.size(); i++)
	{
		if (X2<=0) break;
		if (bool2[K[i]-1]) continue;
		total += C[K[i]-1];
		bool2[K[i]-1] = true;
		C[K[i]-1] = INT_MIN;
		X2--;
		M--;
	}
	if (X1 > 0 || X2 > 0) 
	{
		cout<<-1;
		return 0;
	}
	vector<pair<long long, long long> > adj;
	for (int i=0; i<N; i++) adj.emplace_back(C[i],i);
	sort(adj.begin(), adj.end());
	for (int i=0; i<adj.size(); i++)
	{
		if (M<=0) break;
		if (bool2[adj[i].second]) continue;
		total += adj[i].first;
		bool2[adj[i].second] = true;
		M--;
	}
	(M > 0) ? cout<<-1 : cout<<total;
}
