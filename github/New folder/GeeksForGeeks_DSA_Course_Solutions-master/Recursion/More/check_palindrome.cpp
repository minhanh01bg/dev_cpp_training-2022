#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

bool checkPalindrome(char* str, int start, int end);

int main(){
    int t;
    char str[MAX];
    cin >> t;
    while(t--){
        cin >> str;
        int n = strlen(str);
        if(checkPalindrome(str, 0, n-1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

bool checkPalindrome(char* str, int start, int end){
    if(start == end) // when we reach to a single character
        return true;

    if(start > end) // when the two pointers cross
        return true;
    
    if(str[start] != str[end]) 
        return false;

    return checkPalindrome(str, start+1, end-1);
}