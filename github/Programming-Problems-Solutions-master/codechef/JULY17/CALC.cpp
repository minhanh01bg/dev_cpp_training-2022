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

ll func(ll n, ll b, ll p)
{
    return (n-b*p)*p;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti;
    ll n, b;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &n, &b);
        ll res = 0;
        ll low = 0, hig = n/b;
        while(low<=hig)
        {
            ll lef = (low*2+hig)/3;
            ll rig = (low+hig*2)/3;
            ll res1 = func(n,b,lef);
            ll res2 = func(n,b,rig);
            res = max(res,max(res1,res2));
            if(res1<=res2)
                low = lef+1;
            else
                hig = rig-1;
        }
        printf("%lld\n", res);
    }
    return 0;
}


