#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const double pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;

void khoitao(int b[],int n ){
	for (int i=1;i<=n;i++){
		b[i]=0;
	}
}

int tong(int a[],int b[],int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		if (b[i]){
			sum+=a[i];
		}
	}
	return sum;
}

void sinhnp(int a[],int b[],int n,int j,vi &ds){
	for (int i=0;i<=1;i++){
		b[j]=i;
		if (j==n) {
			ds.push_back(tong(a,b,n));
		}
		else sinhnp(a,b,n,j+1,ds);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,c;
	cin>>c>>n;
	int a[n+1];
	int b[n+1];
	vi ds;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	khoitao(b,n);
	sinhnp(a,b,n,1,ds);
	int res=ds[0];
	for(int i=0;i<ds.size();i++){
		if (ds[i]>res && ds[i]<=c){
			res=ds[i];
		}
	}
	cout<<res;
return 0;
}
