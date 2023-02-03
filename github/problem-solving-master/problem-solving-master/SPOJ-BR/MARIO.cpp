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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int n,l;
  while(cin >> n >> l, n != 0 && l != 0){
    vector<int> v(l);
    for(int i=0; i<l; i++) cin >> v[i];
    int ans = INF;
    for(int i=0; i<l; i++){
      int idx = upper_bound(v.begin(), v.end(), v[i] + n-1) - v.begin();
      idx--;
      ans = min(ans, n - (idx-i+1));
    }
    cout << ans << endl;
  }
      
}


