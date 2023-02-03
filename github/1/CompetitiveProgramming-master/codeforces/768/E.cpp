
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define REPD(i,n) for(int i = (n)-1; i >= 0; --i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define double long double
typedef pair<int, int> II;
#define PI (2 * acos((double)0))
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define MS(a,x) memset(a, x, sizeof(a))
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define y0 u9cqu3jioajc

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
int GI(int& x) { return scanf("%lld", &x); }

int g[66];
map< pair<int, vector<int> >, int> cache;

int get(int n, vector<int> bad) {
    if (n == 0) return 0;

    auto p = make_pair(n, bad);
    if (cache.find(p) != cache.end()) return cache[p];

    set<int> all;
    FOR(i,1,n) if (lower_bound(bad.begin(), bad.end(), i) == bad.end()) {
        int to = n - i;

        auto bad2 = bad;
        if (i <= to) bad2.push_back(i);
        sort(bad2.begin(), bad2.end());

        all.insert(get(to, bad2));
    }

    int res = 0;
    while (all.count(res)) ++res;
    cache[p] = res;
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << (fixed) << setprecision(9);
    FOR(i,1,60) {
        vector<int> tmp;
        g[i] = get(i, tmp);
    }
    int n;
    while (GI(n) == 1) {
        int sum = 0;
        FOR(i,1,n) {
            int a; GI(a);
            sum ^= g[a];
        }
        puts(sum ? "NO" : "YES");
    }
}
