#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N1;
	cin>>N1;
	while(N1--)
	{
	    long long N, C, D;
	    cin>>N>>C>>D;
	    long long larger1 = max(C,D);
	    double larger = larger1;
	    double smaller = C + D - larger;
	    long long smaller1 = smaller;
	    long long factor[N];
	    for (long long i=0; i<N; i++) cin>>factor[i];
	    sort(factor, factor+N);
	    double total1=0;
	    double total2=0;
	    int key=0;
	    for (long long i=N-1; i>=N-smaller1; i--) 
	    {
	        total1 += factor[i];
	        if (i==0) 
	        {
	            key=-1;
	            break;
	        }
	    }
	    if (key==0) for (long long i=N-smaller1-1; i>=N-smaller1-larger1; i--) 
	    {
	        total2 += factor[i];
	        if (i==0) break;
	    }
	    double answer = total1/smaller + total2/larger;
	    cout<<setprecision(6)<<fixed<<answer<<endl;
	}
}
