#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;
int a[MAXN];
vector<int> b[320];

int main(){
	io;
	int n, q;
	cin >> n >> q;
	int sqrtn = sqrt(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
		b[i/sqrtn].push_back(a[i]);
	}
	int numBlocks = ceil((double)n/sqrtn);
	for(int i = 0;i < numBlocks; i++)
		sort(b[i].begin(), b[i].end());
	while(q--){
		char c;
		cin >> c;
		if(c == 'M'){
			int idx, newVal;
			cin >> idx >> newVal;
			--idx;
			int block = idx/sqrtn;
			int initVal = a[idx];
			// search initVal in block
			int lo = 0, hi = sqrtn-1;
			while(lo <= hi){
				int mid = (lo + hi) >> 1;
				if(b[block][mid] == initVal){
					b[block][mid] = newVal;
					break;
				}else if(b[block][mid] < initVal){
					lo = mid + 1;
				}else{
					hi = mid - 1;
				}
			}
			a[idx] = newVal;
			sort(b[block].begin(), b[block].end());
		}else{
			int l, r, x;
			cin >> l >> r >> x;
			--l;--r;
			int leftBlock = l/sqrtn;
			int rightBlock = r/sqrtn;
			int ans = 0;
			if(leftBlock == rightBlock){
				for(int i = l;i <= r; i++){
					if(a[i] <= x)
						ans++;
				}
				cout << ans << endl;
			}else{
				if(l%sqrtn != 0)
					leftBlock++;
				int i;
				for(i = l;i < leftBlock*sqrtn; i++)
					if(a[i] <= x)
						ans++;
				while(i+sqrtn-1 <= r){
					int bb = i/sqrtn;
					ans += upper_bound(b[bb].begin(), b[bb].end(), x) - b[bb].begin();
					i += sqrtn;
				}
				while(i <= r){
					if(a[i] <= x)
						ans++;
					i++;
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}