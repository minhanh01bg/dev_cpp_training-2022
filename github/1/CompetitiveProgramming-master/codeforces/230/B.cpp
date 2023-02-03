
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

int sieve[1000111];

int main() {
    unordered_set<long long> a;
    FOR(i,2,1000) {
        for(int j=i*i; j < 1000111; j += i)
            sieve[j] = i;
    }
    FOR(i,2,1000000) if (!sieve[i]) a.insert(i*(long long)i);
    int n;
    while (scanf("%d", &n) == 1) {
        while (n--) {
            long long x; scanf("%lld\n", &x);
            if (a.count(x)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
