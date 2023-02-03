#include <bits/stdc++.h>
using namespace std;

int repeatedCharacter (string str) ;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    int index = repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}


int repeatedCharacter (string str) 
{ 
    unordered_set<int> s;
    int pos=-1;
    
    for(int i=str.length()-1;i>=0;i--){
        if(s.find(str[i]) != s.end()){
            pos = i;
        }
        
        s.insert(str[i]);
    }
    
    return pos;
} 