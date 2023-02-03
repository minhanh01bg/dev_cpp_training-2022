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
int INP,AM;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        if (feof(stdin)) memset(BUF, 0, sizeof BUF); else fread(BUF,1,BUFSIZE,stdin); \
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

char getAlpha() {
    char c = ' '; while (c < 'A' || c > 'z') GETCHAR(c);
    return c;
}

int value(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}

const long double PI = acos((long double) -1.0);
const long long MOD = 1000000007;

struct Matrix {
    long long x[55][55];
} I, A, p;
long long n;
int m, k;

Matrix operator * (Matrix a, Matrix b) {
    static Matrix c;
    REP(i,m) REP(j,m) {
        c.x[i][j] = 0;
        REP(k,m)
            c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
    }
    return c;
}

Matrix power(long long k) {
    if (k == 0) return I;
    if (k == 1) return A;
    Matrix mid = power(k >> 1);
    mid = mid * mid;
    if (k & 1) return mid * A;
    else return mid;
}

bool can[55][55];
long long f[55], g[55];

int main() {
    GN(n); GN(m); GN(k);
    REP(i,m) I.x[i][i] = 1;
    memset(can, true, sizeof can);
    while (k--) {
        char c = getAlpha();
        int i = value(c);
        c = getAlpha();
        int j = value(c);
        can[i][j] = false;
    }
    REP(i,m) REP(j,m)
        if (can[i][j]) A.x[i][j] = 1;
        else A.x[i][j] = 0;

    p = power(n-1);
    REP(i,m) f[i] = 1;
    long long res = 0;
    REP(i,m) {
        g[i] = 0;
        REP(j,m) g[i] = (g[i] + p.x[i][j] * f[j]) % MOD;
        res = (res + g[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}
