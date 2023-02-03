#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void toDecimal(long n);

int main(void)
{
	int t;
	long n;
	cin >> t;
	while(t--){
	    cin >> n;
	    toDecimal(n);
	}
	return 0;
}

void toDecimal(long n){
    int result, i = 0, k;
    while(n > 0){
        k = n % 10;
        result += (k * (int)pow(2, i++));
        n = n /10;
    }
    cout << result << endl;
}