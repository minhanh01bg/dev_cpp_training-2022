/**
 * Caesar cipher or Shift cipher is one of the simplest encryption algorithm
 * Asked in ThoughtWorks interview
 * https://www.instagram.com/p/B9lK7-bgw-P/
**/

#include<bits/stdc++.h>
using namespace std;

int main() {
	string input, result="";
	int n;
	
	cin >> n;
	cin.ignore();
	getline(cin, input);
	
	for(int i=0;i<input.length();i++){
	    char c = (char) input[i]+n;
	    
	    if(input[i] >= 'a' && input[i] <= 'z'){
	        if(c > 'z'){
	            c = (char) c - 26;
	        }
	        result += c;
	    }else if(input[i] >= 'A' && input[i] <= 'Z'){
	        if(c > 'Z'){
	            c = (char) c-26;
	        }
	        result += c;
	    }else{
	        result += input[i];
	    }
	}
	
	cout << result << endl;
	return 0;
}