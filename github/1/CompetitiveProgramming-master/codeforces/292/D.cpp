#include <sstream>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define FORN(i,a,b) for(int i=(a),_b=(b);i<_b;i++)
#define DOWN(i,a,b) for(int i=a,_b=(b);i>=_b;i--)
#define SET(a,v) memset(a,v,sizeof(a))
#define sqr(x) ((x)*(x))
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;
using namespace std;

//Buffer reading
int INP,AM,REACHEOF;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        if (REACHEOF) return 0;\
        memset(BUF,0,sizeof BUF);\
        int inpzzz = fread(BUF,1,BUFSIZE,stdin);\
        if (inpzzz != BUFSIZE) REACHEOF = true;\
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}
//End of buffer reading

const long double PI = acos((long double) -1.0);

int n, m, nGood;
pair<int,int> e[10111];
int good[10111];
int lab[511];

int getRoot(int u) {
    if (lab[u] < 0) return u;
    return lab[u] = getRoot(lab[u]);
}

void merge(int u, int v) {
    int x = lab[u] + lab[v];
    if (lab[u] < lab[v]) {
        lab[u] = x;
        lab[v] = u;
    }
    else {
        lab[v] = x;
        lab[u] = v;
    }
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        FOR(i,1,m) scanf("%d%d", &e[i].first, &e[i].second);
        memset(lab, -1, sizeof lab);
        nGood = 0;

        FOR(i,1,m) {
            int u = e[i].first, v = e[i].second;
            u = getRoot(u); v = getRoot(v);
            if (u != v) {
                ++nGood;
                good[nGood] = i;
                merge(u, v);
            }
        }
        memset(lab, -1, sizeof lab);
        FORD(i,m,1) {
            int u = e[i].first, v = e[i].second;
            u = getRoot(u); v = getRoot(v);
            if (u != v) {
                ++nGood;
                good[nGood] = i;
                merge(u, v);
            }
        }

        int q; scanf("%d", &q);
        while (q--) {
            int l, r; scanf("%d%d", &l, &r);
            memset(lab, -1, sizeof lab);
            FOR(i,1,nGood) {
                int t = good[i];
                if (t < l || t > r) {
                    int u = e[t].first, v = e[t].second;
                    u = getRoot(u); v = getRoot(v);
                    if (u != v) merge(u, v);
                }
            }

            int res = 0;
            FOR(i,1,n) if (lab[i] < 0) ++res;
            printf("%d\n", res);
        }
    }
    return 0;
}
