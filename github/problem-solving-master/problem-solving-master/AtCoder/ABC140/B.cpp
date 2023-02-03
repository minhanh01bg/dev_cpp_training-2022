#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int ids[n];
  for(int i=0; i<n; i++) cin >> ids[i];
  int s[n+1];
  for(int i=1; i<=n; i++) cin >> s[i];
  int extra[n+2];
  for(int i=2; i<=n; i++) cin >> extra[i];
  
  int lst = -1;
  int ans = 0;
  for(int i=0; i<n; i++){
    int x = ids[i];
    ans += s[x];
    if(lst+1 == x) ans += extra[x];
    lst = x;
  }
  cout << ans << endl;
}


