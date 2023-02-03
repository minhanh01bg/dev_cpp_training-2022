#include<bits/stdc++.h>
#define hoaf cout<<"\nhoaf13. I'm here ~";

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	ll a,b,x,n,l,r,res;
	ld ct;
	cin>>a>>b>>x;
	l=1;
	r=x*x;
	while(l<=r){
		n=(l+r)/2;
		ct=(double)a*pow((double)n,1.0/3)+(double)b*pow((double)n,1.0/2);
		if(ct>=x){
			res=n;
			r=n-1;
		}
		else l=n+1;
	}
	cout<<res;

return 0;
}
