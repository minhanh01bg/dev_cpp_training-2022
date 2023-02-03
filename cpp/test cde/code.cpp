#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(), (c).end()
#define srt(c) sort(all(c))
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

vvi edge(100011);
vb visit(100011, false);
int V, E;

int dfs(int u)
{
    int res = 1;
    visit[u] = true;
    rep(i, 0, edge[u].size() - 1)
    {
        if (visit[edge[u][i]] == false)
        {
            res += dfs(edge[u][i]);
        }
    }
    
    return res;
}
void Process()
{
    rep(i, 1, 100000)
    {
        edge[i].clear();
        visit[i] = false;
    }
    cin >> V >> E;

    int x, y;
    rep(i, 1, E)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    int ans = 0;
    rep(i, 1, V) if (visit[i] == false)
        ans = max(ans, dfs(i));

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    run()
        Process();
    return 0;
}