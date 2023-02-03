#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

const int x = 1e4+7; 
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / __gcd(a, b);
}


long long sum_of_lcm(int A[], int N) {

    int max = 70000;
    max++;
    int dp[max][2];
    memset(dp, 0, sizeof(dp));
    int pri = 0;
    int cur = 1;

    for (int i = 0; i < N; i++) {
        for (int v = 1; v < max; v++) {
            int x = A[i];
            if (dp[v][pri] > 0) {
                x = lcm(A[i], v);
                dp[v][cur] = (dp[v][cur] == 0) ? dp[v][pri]%x : dp[v][cur] % x;
                if ( x % A[i] != 0 ) {
                    dp[x][cur] += (dp[v][pri]%x + dp[A[i]][pri] % x ) % x;
                } else {
                    dp[x][cur] += ( x==v ) ? ( dp[v][pri]%x + dp[v][pri]%x ) : ( dp[v][pri]%x ) ;
                }
            }
        }
        dp[A[i]][cur]++;
        pri = cur;
        cur = (pri + 1) % 2;
    }

    for (int i = 0; i < N; i++) {
        dp[A[i]][pri] -= 1;
    }
    long long total = 0;
    for (int j = 0; j < max; j++) {
        if (dp[j][pri] > 0) {
            total += ((dp[j][pri]%x)* j)%x;
        }
    }
    return total;
}



int main() {
    int t;
    cin>>t;
    int z=1;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        long long sum=0;
        for(int i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
        cout<<"Case "<<z<<": "<<sum_of_lcm(a,n)+sum;
        z++;
        cout<<endl;
    } 
    return 0;
}