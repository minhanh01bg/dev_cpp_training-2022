#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
    
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FOR2(i,a,b) for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define FORA(x,C) for (auto x:C)

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int N; cin>>N; cin.ignore(); while(N--)
#define pause() system("pause");

using namespace std;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;

using namespace std;

ll POW[maxn], hashT[maxn];

// https://vnoi.info/wiki/algo/string/hash

ll getHashT(int i,int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    string T, P;
    cin >> T >> P;

    int lenT = T.size(), lenP = P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;

    for (int i = 1; i <= lenT; i++)
    	POW[i] = (POW[i - 1] * base) % MOD;

    for (int i = 1; i <= lenT; i++)
    	hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;

    ll hashP = 0;
    for (int i = 1; i <= lenP; i++)
    	hashP = (hashP * base + P[i] - 'a' + 1) % MOD;

    for (int i = 1; i <= lenT - lenP + 1; i++)
    	if (hashP == getHashT(i, i + lenP - 1))
    		printf("%d ", i);
}