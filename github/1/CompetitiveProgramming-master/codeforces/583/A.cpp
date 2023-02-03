
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

int n, a[55], b[55];

int main() {
    ios :: sync_with_stdio(false);
    while (cin >> n) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        FOR(i,1,n*n) {
            int u, v; cin >> u >> v;
            if (!a[u] && !b[v]) {
                a[u] = b[v] = 1;
                cout << i << ' ';
            }
        }
        cout << endl;
    }
}
