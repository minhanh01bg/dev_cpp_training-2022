
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

int n;
string a[111], b[111];
int cnt[333], need[333];

int main() {
    ios :: sync_with_stdio(false);
    while (cin >> n) {
        FOR(i,1,n) cin >> a[i] >> b[i];

        int best = -1;
        int save = 0;
        FOR(i,1,n) {
            memset(cnt, 0, sizeof cnt);
            memset(need, 0, sizeof need);
            for(char c : a[i]) need[c]++;
            for(char c : b[i]) need[c]++;

            int x, y; cin >> x >> y;
            REP(xx,x) REP(yy,y) {
                char c; cin >> c;
                cnt[c]++;
            }

            int res = 1000111;
            FOR(c,'a','z')
                if (need[c])
                    res = min(res, cnt[c] / need[c]);
            if (res > best) {
                best = res;
                save = i;
            }
        }
        cout << a[save] << ' ' << b[save] << endl;
    }
}
