
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = '"; cout << (x) << "'" << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    string s, t;
    while (cin >> s >> t) {
        int ls = s.length(), lt = t.length();
        REP(i,lt) s = ' ' + s;
        REP(i,lt) s += ' ';

        int res = lt;
        for(int start = 0, last = lt; last <= s.length(); ++start, ++last) {
            int cur = 0;
            FOR(i,start,last-1)
                if (s[i] != t[i-start]) ++cur;
            res = min(res, cur);
        }
        cout << res << endl;
    }
    return 0;
}
