#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define p pair
#define all(C) C.begin(), C.end()
#define Begin()   \
    int N;        \
    cin >> N;     \
    cin.ignore(); \
    while (N--)

#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define FOR2(i, a, b) for (ll i = (ll)a; i <= (ll)b; ++i)
#define FORD(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)

#define vec(x) vector<x>
// System

#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

using namespace std;

void Process()
{
    string a, b;
    cin >> a >> b;
    a = b + a;
    ll sz = a.length();
    vec(ll) prefix(sz + 1);
    FOR(i, 1, sz - 1)
    {
        ll j = prefix[i - 1];
        while (j > 0 && a[i] != a[j])
            j = prefix[j - 1];
        if (a[i] == a[j])
            j++;
        prefix[i] = j;
    }
    FOR(i, b.length() * 2 - 1, a.length() - 1)
    {
        if (prefix[i] >= b.length() && a[i] == b.back())
            cout << i - b.length() * 2 + 2 << ' ';
    }
}

signed main()
{
    faster();
    Process();
}