#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define Begin() int N; cin>>N; cin.ignore(); while(N--)

#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define FORA(x,C) for (auto x:C)
#define WHILE(x,y) while(cin>>x>>y)
#define WHILEF(x,y,f) while(f>>x>>y)
#define WHILE2(x) while(cin>>x)
#define WHILEGL(a) while(getline(cin,a))
#define WHILEGLF(a,f) while(getline(f,a))
	
#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
#define ite(y,x,it) y<x>::iterator it


#define reset(C) memset(C,0,sizeof(C))
#define clearQueue(C, x) C = queue<x> ()
#define Fill(C,a) fill(C.begin(), C.end(), a)

	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

string factor[60][61];

ll M = 1e9 + 7;

string Plus(string a, string b){
	if (a.length() < b.length()) swap(a,b);
	string token = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	FOR(i,0,b.length()-1){
		carry = carry + (a[i] - '0') + (b[i] - '0');
		token.push_back(carry % 10 + '0');
		carry /= 10;
	}
	FOR(i,b.length(),a.length()-1){
		carry = carry + (a[i] - '0');
		token.pb(carry % 10 + '0');
		carry /= 10;
	}
	if (carry) token.pb(carry + '0');
	reverse(token.begin(), token.end());
	return token;
}

string Subtract(string a, string b){
	string token = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	int sum = 0;
	FOR(i,0,b.length()-1){
		sum = (a[i] - '0') - (b[i] - '0') - carry;
		if (sum < 0){	
			carry = 1;
			sum += 10;
		}
		else carry = 0;
		token.pb(sum + '0');
	}
	FOR(i,b.length(),a.length()-1){
		sum = (a[i] - '0') - carry;
		if (sum < 0){
			carry = 1;
			sum += 10;
		}
		else carry = 0;
		token.pb(sum + '0');
	}
	reverse(token.begin(), token.end());
	while(token[0] == '0') token.erase(0,1);
	return token;
}

string Multiply(string A, string B){
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	string C;
	C.resize(A.length()+B.length(),'0');
	FOR(i,0,A.length()-1){
		int c = 0;
		FOR(j,0,B.length()-1) {
			c += ((A[i]-'0') * (B[j]-'0') + C[i+j] -'0');
			C[i+j] = (char)(c%10 + '0');
			c/=10;
		}
		if (c > 0) C[i + B.length()] += c;
	}
	reverse(C.begin(),C.end());
	return C;
}

string Devide(string number, ll divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0'); 
    while (number.size() > idx) 
	{ 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) return "0"; 
    return ans; 
}

void factory() {
	factor[0][0] = "1";
	factor[0][1] = "1";
	FOR(i,1,52) {
		factor[i][0] = "1";
		factor[i][i+1] = "1";
		FOR(j,1,i) {
			factor[i][j] = Plus(factor[i-1][j], factor[i-1][j-1]);
		}
	}
}

ll TinhTong(string n, ll k) {
	string x = Plus(n, "1"), X = Multiply(x,x);
	string sum[k+5];
	sum[0] = n;
	sum[1] = Devide(Multiply(n, Plus(n,"1")), 2);
	FOR(i,2,k) {
		X = Multiply(X,x);
		sum[i] = Subtract(X,x);
		FOR(j,1,i-1) {
			sum[i] = Subtract(sum[i],Multiply(sum[j],factor[i][j]));
		}
		sum[i] = Devide(sum[i], i+1);
	}
	ll final = 0;
	string token = sum[k];
	reverse(token.begin(), token.end());
	FORD(i,token.length()-1,0) {
		final = (final * 10 + (token[i] - '0')) % M;
	}
	return final;
}

int main() {
	faster();
	factory();
	Begin() {
		ll n,k;
		cin>>n>>k;
		cout<<TinhTong(to_string(n), k)<<endl;
	}
}
