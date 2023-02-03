#include<iostream>
using namespace std;
int isPowerOfFour(unsigned int n);
/*Driver program to test above function*/
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
if(isPowerOfFour(n))
	cout<<1<<endl;
else
	cout<<0<<endl;
}
}



int isPowerOfFour(unsigned int n)
{
    while(n!=1){
        if(n % 4 != 0)
            return 0;
        
        n = n/4;
    }
    return 1;
}