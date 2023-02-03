/*
link dề:https://codeforces.com/contest/1605/problem/C
tóm tắt đề
 cho chuỗi s chỉ gồm các kí tự a,b,c,
  tìm chuỗi con liên tiếp nhỏ nhất sao cho số kí tự a > số kí tự b và c
nhập n là chiều dài chuỗi sau đó nhập s
input:
3
2
aa
5
cbabb
8
cacabccc
output:
2
-1
3
// đề hơi lừa lọc nhỉ => nếu để ý sẽ thấy một số trường hợp đặc biệt

 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int n;
string a;
int solve()
{
    cin >> n >> a;
    if (~a.find("aa"))
        return 2;
    if (~a.find("aba") || ~a.find("aca"))
        return 3;
    if (~a.find("abca") || ~a.find("acba"))
        return 4;
    if (~a.find("abbacca") || ~a.find("accabba"))
        return 7;
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << solve() << '\n';
}