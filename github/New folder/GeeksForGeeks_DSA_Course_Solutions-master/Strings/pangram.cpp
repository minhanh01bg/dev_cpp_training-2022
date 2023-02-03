#include<bits/stdc++.h>
using namespace std;

bool checkPangram (string &str);

int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '
');
    while(t--){
        string str;
        getline(cin, str);
        
        if (checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}



bool checkPangram (string &str)
{
    bool alphacount[26];
    int size = str.length();
    
    for(int i=0;i<size;i++){
        if(str[i]>='a' && str[i]<='z'){
            alphacount[str[i]-97] = true;
        }else if(str[i]>='A' && str[i]<='Z'){
            alphacount[str[i]-65] = true;
        }
    }
    
    for(int i=0;i<26;i++){
        if(alphacount[i] != true)
            return false;
    }
    
    return true;
}