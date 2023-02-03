/** using bitwise operator we can't produce
 * a lexicographically sorted result as
 * required by the problem statement.
 * To do that we have to use other
 * techniques to solve the problem
 */
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void printPowerSet(char* set, int n);

int main(void)
{
	int t, n;
	char set[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
            cin >> set[i];
	    }
	    printPowerSet(set, n);
	}
	return 0;
}

void printPowerSet(char* set, int n){
    unsigned int subsetNos = pow(2, n);
    
    // n is number of characters
    // we have 2^n combinations i.e. subsetNos
    // subsetNos: 0 to ((2^n) - 1)
    // for each subsetNos we go from 0 to n
    // and check the position of set bits in it
    // and print them
    for(int i=0;i<subsetNos;i++){
        for(int j=0;j<n;j++){
            if((i & (1 << j)) != 0){
                cout << set[j];
            }
        }
        cout << " ";
    }
}