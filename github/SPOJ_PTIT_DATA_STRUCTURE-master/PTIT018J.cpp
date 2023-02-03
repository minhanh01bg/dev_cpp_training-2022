#include<bits/stdc++.h>
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
const ll ninf = LONG_MIN;

bool check(string s){			// kiem tra so khong giam ?
	for(int i=1;i<s.length();i++){
		if (s[i]<=s[i-1]) return true;		// co the xet tiep
	}
	return false;					// in ra -1
}

bool check0(string s){
	if (s[0]=='0') return false; // in ra -1
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		if (check(s)==false){
			cout<<-1<<endl;
			continue;
		}
		int index=s.length()-1;
		for (int i=s.length()-1;i>=1;i--){
			if (s[i-1]>s[i]){
				index=i;
				break;
			}
		}
		int move=index;
		char maxx=s[index];
		for(int i=index+1;i<s.length();i++){
			if (s[i]>maxx && s[i]<s[index-1]){
				move=i;
				maxx=s[i];
			}
		}
		swap(s[index-1],s[move]);
		if (check0(s)==false) cout<<-1<<endl;
		else cout<<s<<endl; 
	}
	return 0;
}

