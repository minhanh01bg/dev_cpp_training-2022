#include <iostream>
using namespace std;

// My way
int countDigits(int n)
{
    if(n < 10)
        return 1;
    else
        return n/n + countDigits(n / 10);
    
}

/* int countDigits(int n)
{
    if(n == 0)
        return 0;
    else
        return (1 + countDigits(n / 10));
} */

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    cout<<countDigits(n)<<endl;
	}
	return 0;
}