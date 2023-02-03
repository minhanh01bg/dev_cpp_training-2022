
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

int cnt[300];

int main() {
    int n; string s;
    while (cin >> n >> s) {
        memset(cnt, 0, sizeof cnt);
        int res = 0;
        for(char c : s) {
            if (c >= 'a' && c <= 'z') cnt[c] += 1;
            else {
                if (cnt[c^' ']) --cnt[c^' '];
                else ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
