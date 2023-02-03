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

const ll mod = 1000000007ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    int tot = ((n+k-1)/k)*t;
    int tot2 = 0;
    n -= (d/t)*k;
    if(d%t == 0)
    {
        tot2 = ((n+2*k-1)/(2*k))*t;
    }
    else
    {
        int ex = n%(2*k);
        tot2 = (n/(2*k))*t;
        if(ex != 0)
        {
            if(ex<=k) tot2 += t-(d%t);
            else tot2 += t;
        }
    }
    if(tot2+d<tot)
        puts("YES");
    else
        puts("NO");
    return 0;
}


