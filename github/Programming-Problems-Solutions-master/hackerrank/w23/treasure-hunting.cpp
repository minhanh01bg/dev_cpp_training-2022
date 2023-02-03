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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll x, y, a, b;
    scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
    double m1 = (double) y/x;
    double m2 = (double) b/a;
    double th1 = atan(m1);
    double th2 = atan(m2);
    double th = th1-th2;
    //printf("%lf\n", th1*180/acos(-1));
    //printf("%lf\n", th2*180/acos(-1));
    //printf("%lf\n", th*180/acos(-1));
    double dis = sqrt(x*x+y*y);
    dis /= sqrt(a*a+b*b);
    //printf("---%lf\n", dis);
    printf("%.12lf\n", cos(th)*dis);
    printf("%.12lf\n", sin(th)*dis);
    return 0;
}


