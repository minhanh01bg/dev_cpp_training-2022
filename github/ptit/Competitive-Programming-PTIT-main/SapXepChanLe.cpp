#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
	long long N;
	cin>>N;
	long long C[N];
	vector<long long> F;
	vector<long long> K;
	for (int i = 0; i < N; i++) cin>>C[i];
	long long f=0;
	while (f<N)
	{
		if (f%2==0) F.push_back(C[f]);
		else K.push_back(C[f]);
		f++;
	}
	sort(F.begin(),F.end());
	sort(K.begin(),K.end(),greater<int>());
	for (int i=0; i<K.size(); i++) cout<<F[i]<<' '<<K[i]<<' ';
	if (N%2==1) cout<<F.back()<<endl;
//	sort(C,C+N);
//	for (int i=0; i<N/2; i++) cout<<C[i]<<' '<<C[N-1-i]<<' ';
//	if (N%2==1) cout<<C[N/2];
}
