#include <bits/stdc++.h>

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
const int BUFSIZE = (1<<12) + 17;
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp && !REACHEOF) { \
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

const int MN = 1011;
int m, n, a[MN][MN], x[MN];
bool good[MN][MN];

bool check(int val) {
    memset(good, false, sizeof good);

    FOR(j,1,n) {
        int cnt = 0;
        FOR(i,1,m) if (a[i][j] >= val) x[++cnt] = i;

        FOR(i1,1,cnt) FOR(i2,i1+1,cnt) {
            if (good[x[i1]][x[i2]]) return true;
            good[x[i1]][x[i2]] = true;
        }
    }

    return false;
}

int main() {
    ios :: sync_with_stdio(false);
    while (cin >> m >> n) {
        FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];

        int l = 0, r = 1000111000, res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}
