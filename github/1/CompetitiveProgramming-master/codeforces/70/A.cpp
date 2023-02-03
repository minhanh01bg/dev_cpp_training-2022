
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define SZ(X) ((int) ((X).size()))
using namespace std;

const int MOD = 1e6 + 3;

ll power(ll x, int k) {
    if (k <= 0) return 1;
    if (k == 1) return x;
    ll mid = power(x*x % MOD, k >> 1);
    if (k & 1) return mid * x % MOD;
    else return mid;
}

int main() {
    ios :: sync_with_stdio(false);
    int n;
    while (cin >> n) {
        cout << power(3, n-1) << endl;
    }
}
