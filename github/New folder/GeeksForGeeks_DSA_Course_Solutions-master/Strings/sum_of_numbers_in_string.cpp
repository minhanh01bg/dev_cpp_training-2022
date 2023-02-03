#include <iostream>
using namespace std;

int findSum(string str);

int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout << findSum(str);
        cout<<endl;
	}
	return 0;
}



int findSum(string str)
{
    int sum = 0;
    string temp = "";
    
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i])){
            temp = temp + str[i];
        }else{
            sum = sum + atoi(temp.c_str());
            temp = "";
        }
    }
    
    return sum + atoi(temp.c_str());
    //c_str() changes string to c-style string that 
    //is used by atoi() legacy function to convert it into int
}