#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long
using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int v[n];
		int sum = 0;
		for(int i=0; i<n; i++){
			cin >> v[i];
			sum += v[i];
			sum %= 4;
			v[i] %= 4;
		}
		if(sum != 0){
			cout << -1 << endl;
			continue;
		}
		
		int mm[] = {0,0,0,0};
		for(int i=0; i<n; i++){
			mm[v[i]]++;
		}
		
		int ans = 0;
		while(mm[3] > 0 && mm[1] > 0){
			mm[3]--;
			mm[1]--;
			ans++;
		}
		while(mm[3] > 0){
			mm[3]-=2;
			mm[2]++;
			ans++;
		}
		while(mm[1] > 0){
			mm[1]-=2;
			mm[2]++;
			ans++;
		}
		while(mm[2] >  0){
			mm[2] -=2;
			ans++;
		}
		cout << ans << endl;
	}
}
			
		
