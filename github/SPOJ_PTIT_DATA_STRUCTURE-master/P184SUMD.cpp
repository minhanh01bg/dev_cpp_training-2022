#include<bits/stdc++.h>
#define hoaf cout<<"\nhoaf13. I'm here ~";
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;
 
const double pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0;
	for(int i=0;i<n;i++){
		if (a[i]>0){
			count++;
			for(int j=i+1;j<n;j++){
				if (a[j]==a[i]) a[j]=0;
				else if (a[j]<a[i]) break;
			}
		}
	}
	cout << count;
	return 0;
}	