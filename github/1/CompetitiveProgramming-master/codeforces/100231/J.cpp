#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

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

char a[111][111], b[111][111];
int n;

bool bomb() {
    FOR(i,1,n) FOR(j,1,n)
    if (b[i][j] == 'x' && a[i][j] == '*')
        return true;
    return false;
}

int main() {
    while (scanf("%d\n", &n) == 1) {
        FOR(i,1,n) scanf("%s\n", &a[i][1]);
        FOR(i,1,n) scanf("%s\n", &b[i][1]);

        bool bombon = false;
        if (bomb()) bombon = true;

        FOR(i,1,n) {
            FOR(j,1,n)
            if (a[i][j] == '*') {
                if (bombon) putchar('*');
                else putchar('.');
            }
            else if (b[i][j] == 'x') {
                int cnt = 0;
                FOR(di,-1,1) FOR(dj,-1,1) if (di || dj) {
                    if (a[i+di][j+dj] == '*') ++cnt;
                }
                printf("%d", cnt);
            }
            else {
                putchar('.');
            }
            puts("");
        }
    }
    return 0;
}
