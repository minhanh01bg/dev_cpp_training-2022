#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void largestNum(string num);

int main(void)
{
	int t;
	string num;
	cin >> t;
	while(t--){
	    cin >> num;
	    largestNum(num);
	}
	return 0;
}

void largestNum(string num){
    //we do hashing
    //store the count of each 0-9 numbers
    int count[10] = {0};
    
    for(int i=0;i<num.length();i++){
        count[num[i]-'0']++;
    }
    
    for(int i=9;i>=0;i--){
        while(count[i]>0){
            cout<<i;
            count[i]--;
        }
    }
    cout << endl;
}

// time complexity - O(n)
// better than the method that involves sorting since it is O(nlogn)