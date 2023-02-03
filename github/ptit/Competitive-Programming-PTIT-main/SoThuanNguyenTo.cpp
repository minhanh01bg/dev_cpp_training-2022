#include<bits/stdc++.h>
using namespace std;
set<long long> C;
long long M=1e8;
bool SNT(long long a)
{
    if (a<2) return false;
    if (a==2) return true;
    if (a%2==0) return false;
    for (long long i=3; i<=sqrt(a); i+=2)
    {
        if (a%i==0) return false;
    }
    return true;
}
void check(long long n, long long sum, int checker)
{
	if (checker==1 && SNT(sum) && SNT(n)) C.insert(n);
    if (n>M) return;
    check(n*10+3, sum+3, 1);
    check(n*10+2, sum+2, 0);
    check(n*10+5, sum+5, 0);
    check(n*10+7, sum+7, 1);
}
int main()
{
    check(2,2,1);
    check(3,3,1);
    check(5,5,1);
    check(7,7,1);
    vector<long long> F(C.begin(),C.end());
    int N;
    cin>>N;
    while (N--)
    {
        long long a,b;
        cin>>a>>b;
        vector<long long>::iterator first, last;
        first=lower_bound(F.begin(), F.end(), a);
        last=lower_bound(F.begin(), F.end(), b);
        cout<<(last-F.begin())-(first-F.begin())<<endl;
    }
}
