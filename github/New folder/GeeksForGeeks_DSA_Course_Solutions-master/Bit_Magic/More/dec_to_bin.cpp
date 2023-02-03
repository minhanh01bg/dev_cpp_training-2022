#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void toBinary(int n);

int main(void)
{
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    toBinary(n);
	}
	return 0;
}

void toBinary(int n){
    int binaryNum[32];
    int i = 0;
    
    while(n > 0){
        binaryNum[i++] = n % 2;
        n = n / 2;
    }
    for(int j=i-1;j>=0;j--){
        cout << binaryNum[j];
    }
    cout << endl;
}