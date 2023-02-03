#include <iostream>
using namespace std;

int RecursivePower(int n,int p);

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n,p;
	    cin>>n>>p;
	    cout<<RecursivePower(n,p)<<endl;
	}
	return 0;
}

int RecursivePower(int n,int p)
{
    if(p == 0)
        return 1;
    else
        return n * RecursivePower(n, p-1);
}

/** Another way that takes O(log n):
int RecursivePower(int n,int p)
{
	int t = 1;

    if(p == 1){
		return n;
	}

	t = RecursivePower(n, p/2);
	if((p%2) == 0){
		return (t * t);
	}else
	{
		return (t * t * n);
	}
	
}
**/