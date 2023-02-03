#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
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

const int MN = 100111;

int n, d, a, b;
int x[MN];

int main() {
    ios :: sync_with_stdio(false);
    while (cin >> n >> d >> a >> b) {
        int lInc = 0, lDec = 0;
        int money = d, stock = 0;

        FOR(i,1,n) cin >> x[i];

        FOR(i,2,n) {
            if (x[i] == x[i-1]) {
                lInc = lDec = 0;
            }
            else if (x[i] > x[i-1]) {
                lDec = 0;
                ++lInc;
            }
            else if (x[i] < x[i-1]) {
                lInc = 0;
                ++lDec;
            }

            if (lInc) {
                int can = min(lInc * a, money / x[i]);
                stock += can;
                money -= can * x[i];
            }
            else if (lDec) {
                int can = min(lDec * b, stock);
                stock -= can;
                money += can * x[i];
            }
        }

        cout << money << ' ' << stock << endl;
    }
    return 0;
}
