#include <bits/stdc++.h>
using namespace std;

int Query(int a[], int b[], int l, int r, int qLen)
{
    int ans = INT_MAX;
    while (l < r && l % qLen != 0 && l != 0)
    {
        ans = min(ans, a[l]);
        l += 1;
    }
    while (l + qLen - 1 <= r)
    {
        ans = min(ans, a[b[l / qLen]]);
        l += qLen;
    }
    while (l <= r)
    {
        ans = min(ans, a[l]);
        l += 1;
    }
    return ans;
}

void Process()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n], idx = 0, MinR = INT_MAX, cnt = sqrt(n), indx = 0, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (MinR > a[i])
        {
            MinR = a[i];
            index = i;
        }
        indx += 1;
        if (indx == cnt)
        {
            b[idx] = index;
            MinR = INT_MAX;
            idx += 1;
            indx = 0;
        }
    }
    if (indx != cnt)
    {
        MinR = INT_MAX;
        for (int i = n - indx; i < n; i++)
        {
            if (MinR > a[i])
            {
                MinR = a[i];
                index = i;
                b[idx] = i;
            }
        }
        idx += 1;
    }
    int query;
    cin >> query;
    while (query--)
    {
        int l, r;
        cin >> l >> r;
        cout << Query(a, b, l, r, cnt) << endl;
    }
}

int main()
{
        Process();
}