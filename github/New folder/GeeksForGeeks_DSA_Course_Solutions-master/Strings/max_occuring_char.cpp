#include<bits/stdc++.h>
using namespace std;
char getMaxOccuringChar(char*);
int main()
{
   
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s",str);
    cout<< getMaxOccuringChar(str)<<endl;
    }
}



char getMaxOccuringChar(char* str)
{
    int count[26]={0};
    
    for(int i=0;str[i];i++){
        count[str[i]-97]++;
    }
    
    int max=INT_MIN, k;
    
    for(int i=0;i<26;i++){
        if(count[i]>max){ //> maintains the lexicographic order
            max = count[i];
            k = i;
        }
    }
    
    return char(k+'a');
}