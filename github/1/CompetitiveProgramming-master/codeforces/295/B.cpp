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

#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
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

int c[511][511], f[511][511];
int n, a[511];
long long save[511];

int main() {
    while (scanf("%d", &n) == 1) {
        FOR(i,1,n) FOR(j,1,n) scanf("%d", &c[i][j]);
        FOR(i,1,n) scanf("%d", &a[i]);

        for(int t = n; t >= 1; --t) {
            long long res = 0;

            int u = a[t];
            FOR(i,t+1,n) {
                int x = a[i];
                f[u][x] = c[u][x];
                f[x][u] = c[x][u];
                FOR(j,t+1,n) if (j != i) {
                    int y = a[j];
                    f[u][x] = min(f[u][x], c[u][y] + f[y][x]);
                    f[x][u] = min(f[x][u], f[x][y] + c[y][u]);
                }
            }

            FOR(i,t+1,n)
            FOR(j,t+1,n) {
                int x = a[i], y = a[j];
                f[x][y] = min(f[x][y], f[x][u] + f[u][y]);
            }

            FOR(i,t,n) FOR(j,t,n)
                res += f[a[i]][a[j]];

            save[t] = res;
        }
        FOR(i,1,n) cout << save[i] << ' '; cout << endl;
    }
    return 0;
}