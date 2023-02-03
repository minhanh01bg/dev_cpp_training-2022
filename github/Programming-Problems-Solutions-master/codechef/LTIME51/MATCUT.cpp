#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
//#include <bits/stdc++.h>

using namespace std;

#define HI              printf("HI\n")
#define sf              scanf
#define pf              printf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d)    scanf("%d %d %d %d",&a,&b,&c,&d)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define sf4ll(a,b,c,d)    scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define forln(i,a,n)    for(int i=a ; i<n ; i++)
#define foren(i,a,n)    for(int i=a ; i<=n ; i++)
#define forg0(i,a,n)    for(int i=a ; i>n ; i--)
#define fore0(i,a,n)    for(int i=a ; i>=n ; i--)
#define pb              push_back
#define ppb             pop_back
#define ppf             push_front
#define popf            pop_front
#define ll              long long int
#define ui              unsigned int
#define ull             unsigned long long
#define fs              first
#define sc              second
#define clr( a, b )     memset((a),b,sizeof(a))
#define jora            pair<int, int>
#define jora_d          pair<double, double>
#define jora_ll         pair<long long int, long long int>
#define mp              make_pair
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define PI              acos(0.0)
#define wait            system("pause")
#define ps              pf("PASS\n")
#define popc(a)         (__builtin_popcount(a))

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

/// <---------------------------  For Bitmasking  -------------------------------->
//int on( int n, int pos ){
//    return n = n|( 1<<pos );
//}
//bool check( int n, int pos ){
//    return (bool)( n&( 1<<pos ) );
//}
//int off( int n, int pos ){
//    return n = n&~( 1<<pos );
//}
//int toggle( int n, int pos ){
//    return n = n^(1<<pos);
//}
//int count_bit( int n ){
//    return __builtin_popcount( n );
//}
/// <---------------------------  End of Bitmasking  -------------------------------->


/// <--------------------------- For B - Base Number System ----------------------------------->
//int base;
//int pw[10];
//void calPow(int b){
//    base = b;
//    pw[0] = 1;
//    for( int i = 1; i<10; i++ ){
//        pw[i] = pw[i-1]*base;
//    }
//}
//int getV(int mask, int pos){
//    mask /= pw[pos];
//    return ( mask%base );
//}
//int setV(int mask, int v, int pos){
//    int rem = mask%pw[pos];
//    mask /= pw[pos+1];
//    mask = ( mask*base ) + v;
//    mask = ( mask*pw[pos] ) + rem;
//    return mask;
//}
/// <--------------------------- End B - Base Number System ----------------------------------->


// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//double Expo(double n, int p) {
//	if (p == 0)return 1;
//	double x = Expo(n, p >> 1);
//	x = (x * x);
//	return ((p & 1) ? (x * n) : x);
//}

//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MXN 50
#define MXE
#define MXQ
#define SZE
#define MOD
#define EPS
#define INF 100000000
#define MX  1000005
#define inf 100000000

ll make[MX];
vector<int> adj[MX];
ll val[MX];
int dis[MX];
int ans;

ll quve(ll a)
{
    return a*a*a;
}

void bfs(int u)
{
    //deb(u,"......");
    int st = u;
    memset(dis,-1,sizeof dis);
    queue<int> qu;
    qu.push(u);
    dis[u] = 1;
    make[u] = val[u];
    while(!qu.empty())
    {
        u = qu.front();
        qu.pop();
        ll now = make[u];
        //printf("%d %lld\n", u, now);
        ll t = pow(now,1.0/3.0);
        while(quve(t+1)<=now) t++;
        while(quve(t-1)>=now) t--;
        if(quve(t) == now)
        {
            make[u] = 1;
            ans = max(ans,dis[u]);
        }
        for(int i = 0; i < adj[u].size(); i++)
        {

            int v = adj[u][i];
            //if(v<=st) continue;
            //printf("%d %d %d\n", u, v, dis[v]);
            if(dis[v] == -1)
            {
                dis[v] = dis[u]+1;
                make[v] = val[v]*make[u];
                qu.push(v);
            }
        }
    }
}

int cnt[MX];
vector<int> prime[MX];
int power = MX;

void add(int p)
{
    //printf("add %d\n", p);
    cnt[p]++;
    if(cnt[p]%3 == 0) power++;
    else if(cnt[p]%3 == 1) power--;
}

void del(int p)
{
    cnt[p]--;
    if(cnt[p]%3 == 2) power--;
    else if(cnt[p]%3 == 0) power++;
}

void dfs(int u, int p, int dist)
{
    //printf("%d %d %d\n", u, p, dist);
    for(int i = 0; i < prime[u].size(); i++)
    {
        add(prime[u][i]);
    }
    if(power == MX)
    {
        ans = max(ans,dist);
    }
    for(int i = 0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,u,dist+1);
    }
    for(int i = 0; i < prime[u].size(); i++)
    {
        del(prime[u][i]);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int te, n, u, v;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &val[i]);
            //deb(val[i]);
            prime[i].clear();
            for(ll j = 2; j*j <= val[i]; j++)
            {
                //deb(j);
                while(val[i] % j == 0)
                {
                    prime[i].push_back(j);
                    val[i] /= j;
                }
            }
            if(val[i]>1) prime[i].push_back(val[i]);
        }
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = -1;
        for(int i = 1; i <= n; i++)
            dfs(i,i,1);
        printf("%d\n", ans);
    }
    return 0;
}































