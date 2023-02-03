#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

int n, q, a[111];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    while (cin >> n >> q) {
        FOR(i,1,n) a[i] = 0;
        while (q--) {
            int u, v, c; cin >> u >> v >> c;
            a[u] += c;
            a[v] -= c;
        }
        int res = 0;
        FOR(i,1,n) if (a[i] > 0) res += a[i];
        cout << res << endl;
    }
    return 0;
}
