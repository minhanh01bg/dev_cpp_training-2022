//https://oj.vnoi.info/problem/acmnb
/*
solution:
    Giả sử cho Tí làm hết cả 2n bài. Khi đó nếu Tèo thay Tí làm bài số i thì tổng thời gian làm bài sẽ tăng lên bằng bi - ai
    Vậy ta cho Tèo làm n bài có giá trị bi - ai lớn nhất.
    Độ phức tạp: O(nlog2n)
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pub push_back
#define pob pop_back
#define mp make_pair
#define all(C) C.begin(), C.end()
#define run() int N; cin>>N; cin.ignore(); while(N--)

#define FOR(i, a, b) for (int i = a;i <= b; i++)
#define FOR2(i, a, b) for (ll i = a;i <= b; ++i)
#define FORD(i, a, b) for (int i = a;i >= b; i--)
#define FORA(x, C) for (auto x:C)
#define REP(i, a) for(int i = 0;i <= a; i++)
#define REP2(i, a) for(ll i = 0;i <= a; i++)
#define REPD(i, a) for(int i = a;i >= 0; i--)
#define FORx(i,m,n,x)   for(int i = m; i <= n; i += x)

#define Sort(C) sort(C,C+n)
#define SORT(C) sort(c.begin(),C.end())

#define reset(C) memset(C, 0, sizeof(C))
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pause() system("pause");

using namespace std;
int n, ans = 0;

vector<int> dif;
void setup() {
    cin >> n;
    int a, b;
    FOR(i, 1, (n << 1)) {
        cin >> a >> b;
        ans += a;
        dif.pb(b - a);
    }
    sort(dif.begin(), dif.end());
    FOR(i, 0, n - 1)
        ans += dif[i];
    cout << ans;
}

main() {
    faster()
    setup ();
    return 0;
}