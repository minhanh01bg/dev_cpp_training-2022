#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define unsigned long long ll

int check(string s);

int main(void)
{
	int t;
	string s;
	
	cin >> t;
	
	while(t--){
	    cin>>s;
	    cout << check(s) << endl;
	}
	return 0;
}

int check(string s){
    int num=0, m=1, i;
    
    int n = s.length();
    
    for(i=n-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            num = num + (s[i]-'0') * m;
            m = m*10;
            
            if(num>=n)
                return 0;
        }else{
            break;
        }
    }
    
    if(num == i+1)
        return 1;
    else
        return 0;
}