#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t,i;
    long long k;
    cin>>t;
    while(t--)
    {
        cin>>k;
        k++;
        vector<int> temp;
        while(k>1)
        {
            if(k%2)
                temp.push_back(6);
            else
                temp.push_back(5);
            k=k/2;
        }
        for (i=temp.size()-1;i>=0;i--)
            cout<<temp[i];
        cout<<"\n";
    }
    return 0;
}
