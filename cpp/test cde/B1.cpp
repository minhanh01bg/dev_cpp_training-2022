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

bool isPrim1(ll n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;

    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
        return false;
    for (int i = 11; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
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

ll spf[1000000 + 11];
void sieve(int N)
{
    for (int i = 0; i <= N; ++i)
    {
        spf[i] = i;
    }

    spf[1] = 1;

    for (int i = 4; i <= N; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i <= N; ++i)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void Process()
{
    ll n, m;
    cin >> n >> m;
    cout << search(n, m) << endl;
    for (int i = 1000000; i >= 0; i--)
    {
        if (spf[i] == i)
        {
            ll x = i;
            cout << x * x * 7 << endl;
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(1000000);
    int t;
    cin >> t;
    while (t--)
        Process();
}