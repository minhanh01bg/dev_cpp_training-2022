#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double d[21];
bool possible(double d[],int n)
{
    int i;
	double sum=0.0;
	for(i=0;i<n-1;i++)
    {
		sum += d[i];
		if(sum>=d[i+1])
            return true;
	}
	return false;
}

int main()
{
	int n, i;
	while(scanf("%d",&n)==1 && n)
    {
		for(i=0;i<n;i++)
            cin>>d[i];
		if(n==1)
            cout<<"NO\n";
		else
        {
			sort(d,d+n);
			if(possible(d,n))
                cout<<"YES\n";
			else
                cout<<"NO\n";
		}
	}
	return 0;
}
