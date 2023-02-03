#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define mt make_tuple
#define mp make_pair
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
  int n, w;
  cin >> n >> w;
  int min_x = INF, max_x = -INF;
  int cur = 0;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    cur += x;
    min_x = min(cur, min_x);
    max_x = max(cur, max_x);
  }
  if(max_x > w){
    cout << 0 << endl;
    return 0;
  }
  int r = min(w, w - max_x);
  int l = max(0LL, -min_x);
  if(l > r){
    cout << 0 << endl;
    return 0;
  }
  cout << r - l + 1 << endl; 
}
