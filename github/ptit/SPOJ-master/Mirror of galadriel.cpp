#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
vector<string> v;
int main()
{
    int t,i,flag=0,j;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        v.push_back(s);
    }
   for(i=0;i<v.size();i++)
   {
       flag=0;
        for(j=0;j<(v[i].length())/2;j++)
        {
            if(v[i][j]!=v[i][v[i].length()-1-j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("YES\n");
        else
        printf("NO\n");
   }
}
