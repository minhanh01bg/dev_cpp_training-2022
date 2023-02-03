#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using db = double;
using str = string; // yay python!

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
// loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
// #define rep(i, a) rep(i, 0, a)
#define rof(i, a, b) for (int i = (b); i >= (a); --i)
#define r0f(i, a) rof(i, 0, a)
#define trav(a, x) for (auto &a : x)

const int MOD = 1e9 + 7; // 998244353;
const int MX = 2e5 + 5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!

map<str, int> MP;
/*
Tìm số nguyên M lớn nhất sao cho N! chia hết cho K^M.

Input:

Dòng đầu tiên là số lượng bộ test T (T <= 100).

Mỗi test gồm 2 số nguyên dương N và K (N <= 10^18, K <= 10^12).

Output:

In ra số nguyên M tìm được.
input
2
5 2
10 10
output
3
2
*/
// bool isPrim1(ll n)
// {
//     if (n <= 1)
//         return false;
//     if (n == 2 || n == 3 || n == 5 || n == 7)
//         return true;
//     if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
//         return false;
//     for (int i = 11; i <= sqrt(n); i += 2)
//         if (n % i == 0)
//             return false;
//     return true;
// }

bool isPrim1(ll x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    if (x == 3)
        return true;
    if (x % 3 == 0)
        return false;
    ll t = 1;
    for (ll i = 5; i * i <= x; i += 2 * (1 + t))
    {
        if (x % i == 0)
            return false;
        t = 1 - t;
    }
    return true;
}

ll search(ll n, ll m)
{
    ll x = 0;
    ll a = m;
    while (n / a)
    {
        x = x + n / a;
        a = a * m;
    }
    return x;
}

void Process()
{
    ll n, m;
    cin >> n >> m;
    if (isPrim1(m))
    {
        cout << search(n, m) << endl;
        return;
    }
    queue<pl> Q;
    int cnt = 0;
    
    rep(i, 2, sqrt(m))
    {
        cnt = 0;
        while (m % i == 0)
        {
            cnt += 1;
            m /= i;
        }
        if (cnt)
            Q.push({i, cnt});
    }
    if (m != 1)
        Q.push({m, 1});

    ll ans = 1e18;

    while (!Q.empty())
    {
        pi k = Q.front();
        Q.pop();
        ll x = search(n, k.first);
        ans = min(ans, x / k.second);
    }

    if (ans == 1e18)
    {
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Process();
}