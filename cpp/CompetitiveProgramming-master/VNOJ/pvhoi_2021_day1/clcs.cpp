// binary search:
// - kiem tra xem kq >= m hay khong?
// - f[i][j] = 1 iff a[i][j] >= m
// --> 1 bang con co median >= m <=> sum(f) >= h*w/2+1
//
// --> O(r*c*log)

#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int MN = 3011;
int a[MN][MN];
int f[MN][MN];
int nRow, nCol, needRow, needCol, need;

int getSum(int i1, int j1, int i2, int j2)
{
    return f[i2][j2] - f[i1 - 1][j2] - f[i2][j1 - 1] + f[i1 - 1][j1 - 1];
}

bool check(int val)
{
    // init f
    FOR(i, 1, nRow)
    FOR(j, 1, nCol)
    {
        f[i][j] = a[i][j] >= val; // f[i][j] = 1 if a[i][j]  >= val

        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
    }

    // loop through all submatrices
    for (int i1 = 1, i2 = needRow; i2 <= nRow; i1++, i2++)
    {
        for (int j1 = 1, j2 = needCol; j2 <= nCol; j1++, j2++)
        {
            if (getSum(i1, j1, i2, j2) >= need)
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input
    cin >> nRow >> nCol >> needRow >> needCol;

    FOR(i, 1, nRow)
    FOR(j, 1, nCol)
    {
        cin >> a[i][j];
    }

    need = needRow * needCol / 2 + 1;

    // binary search
    // - find largest m: there exists submatrix sum(f) >= need;
    int l = 1, r = nRow * nCol, res = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << res << endl;
    return 0;
}
