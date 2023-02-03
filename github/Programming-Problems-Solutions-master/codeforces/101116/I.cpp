//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 110
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int cnt[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, n, x;
    scanf("%d", &te);
    while(te--) {
        scanf("%d", &n);
        memset(cnt,0,sizeof cnt);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 6; j++) {
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        vector<int> vc;
        for(int i = 1; i <= 6; i++) {
            int mx = 0;
            int res = -1;
            for(int j = 1; j <= 49; j++) {
                if(mx<cnt[j]) {
                    mx = cnt[j];
                    res = j;
                } else if(mx == cnt[j]) {
                    if(j == 7)
                        res = 7;
                }
            }
            cnt[res] = -1;
            vc.push_back(res);
        }
        sort(vc.begin(),vc.end());
        printf("%d", vc[0]);
        for(int i = 1; i < vc.size(); i++)
            printf(" %d", vc[i]);
        puts("");
    }
    return 0;
}


