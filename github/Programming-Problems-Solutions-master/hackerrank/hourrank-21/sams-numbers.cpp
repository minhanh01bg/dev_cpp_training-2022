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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000009ll;

ll dp[MX][12];
int m, d;
ll func(int s, int pre)
{
    if(s == 0) return 1;
    if(s<0) return 0;
    ll & res = dp[s][pre];
    if(res != -1) return res;
    res = 0;
    for(int i = max(1,pre-d); i <= min(m,pre+d); i++)
        res += func(s-i,i);
    res %= mod;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll s;
    cin>>s>>m>>d;
    ll ans = 0;
    memset(dp,-1,sizeof dp);
    for(int i = 1; i <= m; i++)
        ans += func(s-i,i);
    ans %= mod;
    cout<<ans;
    return 0;
}


