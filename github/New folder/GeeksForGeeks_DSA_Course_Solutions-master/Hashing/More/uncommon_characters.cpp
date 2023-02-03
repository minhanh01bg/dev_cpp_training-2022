#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

void findUncommon(string s1, string s2);

int main(void)
{
	int t, n;
	string s1, s2;
	cin >> t;
	while(t--){
	    cin >> s1;
	    cin >> s2;
	    findUncommon(s1, s2);
	}
	return 0;
}

void findUncommon(string s1, string s2){
    char h[26];
    
    int len1 = s1.length();
    int len2 = s2.length();
    
    for(int i=0;i<len1;i++){
        h[s1[i] - 'a'] = 1;
    }
    
    for(int i=0;i<len2;i++){
        if(h[s2[i] - 'a'] == 1 || h[s2[i] - 'a'] == -1){
            h[s2[i] - 'a'] = -1;
        }else{
            h[s2[i] - 'a'] = 2;
        }
    }
    
    for(int i=0;i<26;i++){
        if(h[i]==1 || h[i]==2)
            cout << (char(i + 'a'));
    }
    cout << endl;
}