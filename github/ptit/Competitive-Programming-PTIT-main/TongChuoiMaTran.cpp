// Designed by Nguyen Thanh Chau
// a.k.a Linh's servant - Ken
// En Taro Adun! - TemplarAssasin a.k.a Zeratul

// Libraries

#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/math/constants/constants.hpp>
// #include <boost/cstdint.hpp>

// Defines
	
	// Typedefs
	
	#define ll long long
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define cl(C) C.clear()
	#define cint cpp_int
	#define all(C) C.begin(), C.end()
	#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
	//Commands
	
		// Loops
		
		#define FOR(i,a,b) for (int i=a; i<=b; i++)
		#define FORD(i,a,b) for (int i=a; i>=b; i--)
		#define FORA(x,C) for (auto x:C)
		#define WHILE(x,y) while(cin>>x>>y)
		#define WHILEF(x,y,f) while(f>>x>>y)
		#define WHILE2(x) while(cin>>x)
		#define WHILEGL(a) while(getline(cin,a))
		#define WHILEGLF(a,f) while(getline(f,a))
		
		// Get values
		
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		#define ite(y,x,it) y<x>::iterator it
		
		// Clear containers
		
		#define reset(C) memset(C,0,sizeof(C))
		#define clearQueue(C, x) C = queue<x> ()
		#define Fill(C,a) fill(C.begin(), C.end(), a)
		
		// Customize containers
		
		#define SORT(C) sort(C.begin(), C.end())
		#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
		#define SORTC(C,check) sort(C.begin(), C.end(), check)
		#define tlw(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = tolower(C[i])
		#define tup(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = toupper(C[i])
		#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
		#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
		#define CutInHalf(C,F,x,y) y<x> F(C.begin() + C.size()/2 + 1, C.end()); C.resize(C.size()/2)
		#define revrs(C) reverse(C.begin(, C.end()))
		
		// Scan and print containers
		
		#define get(C,a) for(int i=0; i<a; i++) cin>>C[i]
		#define getVector(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getDeque(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getSet(C, a, token) for(int i=0; i<a-1; i++) { cin>>token; C.insert(token); } cin>>token; C.insert(token)
		#define print(C,a) for(int i=0; i<a; i++) cout<<C[i]<<' '
		#define printVector(C) for(int i=0; i<C.size(); i++) cout<<C[i]<<' '
		#define printSet(C,x) for (set<x>::iterator it = C.begin(); it!= C.end(); ++it) cout<<*it<<' '
		#define printDeque(C) for(int i=0; i<C.size(); i++) cout<<C[i]<<' '
		
		// Converts between containers
		
		#define toSet(C,x) set<x> (C.begin(), C.end())
		#define toVector(C,x) vector<x> (C.begin(), C.end())
		#define toQueue(C,x) queue<x> (C.begin(), C.end())
		#define toDeque(C,x) deque<x> (C.begin(), C.end())
		#define toList(C,x) list<x> (C.begin(), C.end())
		#define toMultiset(C,x) multiset<x> (C.begin(), C.end())
		
		// Iterators
		
		#define pointer(A,x) A<x>::iterator
		
	// Containers
	
	#define um(x,y) unordered_map<x,y> 
	#define m(x,y) map<x,y> 
	#define p(x,y) pair<x,y> 
	#define us(x) unordered_set<x> 
	#define vec(x) vector<x> 
	#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y))
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
	
	// System
	
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#define pause() system("pause");

// Namespaces

using namespace std;
// using namespace boost::multiprecision;
// using boost::multiprecision::cpp_dec_float_50;

//===================== Your code starts HERE =====================

ll M = 10;

ll A,B;

vector<vector<ll> > mr, tp;

vector<vector<ll> > multiply(vector<vector<ll> > a, vector<vector<ll> > b)
{
	vector<vector<ll> > K = a;
	for (int i=0; i<A; i++)
	{
		for (int j=0; j<A; j++)
		{
			K[i][j] = 0;
			for (int k = 0; k<A; k++) 
			{
				K[i][j] += (a[i][k] * b[k][j]);
				K[i][j] %= M;
			}
		}
	}
	return K;
}

vector<vector<ll> > Plus(vector<vector<ll> > a, vector<vector<ll> > b)
{
	vector<vector<ll> > K = a;
	for (int i=0; i<A; i++)
	{
		for (int j=0; j<A; j++)
		{
			K[i][j] = (a[i][j] + b[i][j]) % M;
		}
	}
	return K;
}

vector<vector<ll> > masterPow(vector<vector<ll> > m, ll n){
	if(n == 1) return m;
	if(n == 0) return mr;
	else if(n & 1) return multiply(masterPow(m, n-1),m);
	else{
		vector<vector<ll> > mtr = masterPow(m, n/2);
		return multiply(mtr, mtr);
	}
}

vector<vector<ll> > solved(vector<vector<ll> > m, ll k){
	if(k == 0) return tp;
	if(k == 1) return m;
	if(!(k & 1)){
		vector<vector<ll> > mtr = solved(m, k/2);
		return Plus(mtr,multiply(mtr,masterPow(m, k/2)));
	}
	else return Plus(solved(m, k-1), masterPow(m, k));
}

int main()
{
	faster();
//	Begin()
//	{
//		
//	}
	cin>>A>>B;
	vector<ll> X(A,0);
	vector<vector<ll> > k(A,X);
	mr = k;
	tp = k;
	FOR(i,0,A-1)
	{
		FOR(j,0,A-1) cin>>k[i][j];
	}
 	vector<vector<ll> > token = solved(k,B);
 	FOR(i,0,A-1)
 	{
 		FOR(j,0,A-1) cout<<token[i][j]%10<<' ';
 		cout<<endl;
 	}
}
