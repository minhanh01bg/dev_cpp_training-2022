#include <iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void generateSub(long start,long num,long *arr,vector<long>& v)
{
    long s=0;
    long i,j;
    for(i=0;i<(1<<num);i++)
    {
         s=0;
        for(j=0;j<num;j++){
         if(i&(1<<j))
         s=s+arr[j+start];
         }
         v.push_back(s);
    }
}
int main() {
	long a,n,i,b,j;
	long long c=0;
	long arr[35];
    vector<long> left;
    vector<long> right;
	vector<long>::iterator low,high;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
     cin>>arr[i];
     generateSub(0,n/2,arr,left);
     generateSub(n/2,n&1?n/2+1:n/2,arr,right);
     sort(right.begin(),right.end());

     for(i=0;i<left.size();i++)
     {
       low=lower_bound(right.begin(),right.end(),a-left[i]);
       high=upper_bound(right.begin(),right.end(),b-left[i]);
       c=c+(high-right.begin())-(low-right.begin());
     }
    cout<<c<<"\n";
	return 0;
}
