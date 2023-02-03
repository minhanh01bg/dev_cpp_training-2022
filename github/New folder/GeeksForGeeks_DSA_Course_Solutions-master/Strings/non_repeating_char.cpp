#include <bits/stdc++.h>
using namespace std;
char nonrepeatingCharacter(string S);
int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    
        char ans = nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}


char nonrepeatingCharacter(string str)
{
    unordered_map<char, int> m;
    
    for(int i=0;i<str.length();i++){
        m[str[i]]++;
    }
    
    for(int i=0;i<str.length();i++){
        if(m[str[i]] == 1){
            return str[i];
        }
    }
    
    return '$';
}