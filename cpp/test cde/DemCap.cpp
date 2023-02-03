#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(), (c).end()
#define srt(c) sort(all(c))
#define srtrev(c) \
    sort(all(c)); \
    reverse(all(c))
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, a, b) for (int i = a; i >= b; i--)
#define read(x) cin >> x
#define readv(x, n) \
    vi x(n);        \
    forn(i, 0, n) cin >> x[i]
#define run()     \
    int TEST;     \
    read(TEST);   \
    cin.ignore(); \
    while (TEST--)

#define pb push_back
#define mp make_pair

void printRight(ll arr[], int n)
{
    stack<ll> s;
    int arr1[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            arr1[i] = -1;
        else
            arr1[i] = s.top();

        s.push(arr[i]);
    }

    rep(i, 0, n - 1) cout << arr1[i] << " ";
}

void printLeft(ll arr[], int n)
{
    stack<ll> s;
    int arr1[n];
    for (int i = 0; i <= n - 1; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            arr1[i] = -1;
        else
            arr1[i] = s.top();

        s.push(arr[i]);
    }

    rep(i, 0, n - 1) cout << arr1[i] << " ";
}
/*
7
2 4 1 2 2 5 1
*/
void Process()
{
    int n;
    cin >> n;
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];

    rep(i, 0, n - 1)
    {
        
    }
    printLeft(a, n);
    cout << endl;
    printRight(a, n);
}

signed main()
{
    Process();
}
