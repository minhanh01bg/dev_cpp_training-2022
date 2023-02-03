 #include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}


int atoi(string str)
{
    int result = 0;
    int n = str.length();
    bool negative_flag = false;
    
    if(str.length() == 0) //if str is null
        return -1;
    
    for(int i=0;i<n;i++){
        if(str[i] >= '0' && str[i] <= '9'){
            result = result*10 + (str[i] - '0');
        }else if(str[i] == '-'){ //handles negative
            negative_flag = true;
        }
        else{
            return -1;
        }
    }
    
    if(negative_flag)
        return -result;
    else
        return result;
}