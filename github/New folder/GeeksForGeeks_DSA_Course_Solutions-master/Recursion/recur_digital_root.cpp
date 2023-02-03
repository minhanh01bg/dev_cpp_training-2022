#include <iostream>
using namespace std;

int digitalRoot(int n)
{
    if(n < 10)
        return n;
    else
        return digitalRoot(n % 10 + n / 10);
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    cout<<digitalRoot(n)<<endl;
	}
	return 0;
}