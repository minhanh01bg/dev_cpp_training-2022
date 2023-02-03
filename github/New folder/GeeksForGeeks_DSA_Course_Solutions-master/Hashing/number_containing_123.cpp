#include<bits/stdc++.h>
using namespace std;
int flag[1000001];
int main()
{
    int t;
    cin>>t; 
    int num=1,num2;
    
    vector<int> a; int j=1;
    a.push_back(j);
    a.push_back(j+1);
    a.push_back(j+2);
    
    j=0;
    
    // push the elements which have digits as 1, 2, and 3 only
    while(num<=1000000)
    {
        num2=a[j++];
        
        if((num2*10)+1<=1000000)
            a.push_back((num2*10)+1);
        
        if((num2*10)+2<=1000000)
            a.push_back((num2*10)+2);
        
        num2=(num2*10)+3;
        
        if(num2<=1000000)
            a.push_back(num2);
        
        num=num2;
    }
    
    while(t--)
    {
        int n,i;
        cin>>n; 
        int k,max2=0; 
        memset(flag,0,sizeof(flag)); 
        bool flag2=0;
        
        // find max element in the array
        for(i=0;i<n;i++)
        {
            cin>>k;
            flag[k]++;
            max2=max(max2,k);
        }
        
        // iterating over the array elements
        for(i=0;a[i]<=max2 && i<a.size();i++)
        {
            // check the frequency of element in vector which is filled with preprocessing
            while(flag[a[i]]>0)
            {
                cout<<a[i]<<" ";
                flag2=1;
                flag[a[i]]--;
            }
        }
        
        if(flag2==0)
            cout<<"-1";
        
        cout<<endl;
    }
return 0;
}