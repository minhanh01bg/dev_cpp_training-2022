#include<bits/stdc++.h>
using namespace std;
// Nhà nào mà ch?ng có mái
// Nguy?n Thanh Châu
long long n;
long long a[10001];
long long sum(long long i, long long k)
{
    long long re = 0;
    re += abs(k - a[i]);
    long long x = k - 1;
    for (long long j = i-1; j>0; j--)
    {
        re += abs(x - a[j]);
        x--;
    }
    x = k - 1;
    for (long long j = i+1; j<=n; j++)
    {
        re += abs(x - a[j]);
        x--;
    }
    return re;
}
long long solve(long long i)
{
    long long left = max(i, n - i);
    if (n%2==1) left++;
    long long right = 1e9;
    while (left + 1 < right)
    {
        long long x1 = sum(i, left);
        long long mid = (right + left) / 2;
        long long x2 = sum(i, mid);
        long long x3 = sum(i, right);
        if (x2 > x1 && x2 < x3) right = mid;
        else if (x2 < x1 && x2 > x3) left = mid;
        else
        {
            long long x4 = sum(i, mid - 1);
            long long x5 = sum(i, mid + 1);
            if (x4 > x2 && x5 < x2) left = mid;
            else right = mid;
        }
    }
    return min(sum(i, left), sum(i, right));
}
int main()
{
    cin>>n;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    long long ans = 1e14;
    for (long long i=1; i<=n; i++)
    {
        long long x = solve(i);
        if (x < ans) ans = x;
    }
    cout<<ans;
}
