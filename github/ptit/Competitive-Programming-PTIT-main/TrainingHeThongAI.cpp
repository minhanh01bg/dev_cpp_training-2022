#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
	    int a;
	    cin>>a;
	    double C[a];
	    double b;
	    cin>>b;
	    double total=b;
	    for (int i=0; i<a; i++) 
	    {
	        cin>>C[i];
	        total+=C[i];
	    }
	    double average = total / a;
	    if (average >= 1)
	    {
	        cout<<"1.000000"<<endl;
	        continue;
	    }
	    sort(C,C+a);
	    for (int i=a-1; i>=0; i--)
	    {
	        total-=C[i];
	        if (C[i]>average)
	        {
	            average = total / (i);
	        }
	        else
	        {
	            total -= (average - C[i]);
	            C[i] = average;
	        }
	    }
	    double final=1;
	    for (int i=0; i<a; i++) 
	    {
	    	final *= C[i];
	    	//cout<<C[i]<<' ';
	    }
	    //cout<<endl;
	    cout<<setprecision(6)<<fixed<<final<<endl;
	}
}
