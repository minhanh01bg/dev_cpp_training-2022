#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    long long C[a], F[a+1];
    for (int i=0; i<a; i++) cin>>C[i];
    sort(C, C+a);
    F[0] = 0;
    F[1] = C[0];
//    set<long long> myset;
//    myset.insert(F[0]);
    for (int i=2; i<=a; i++) 
    {
    	F[i] = C[i-1] + F[i-1];
//    	myset.insert(F[i]);
	}
	// for (int i=0; i<a+1; i++) cout<<F[i]<<' ';
	// cout<<endl;
    while (b--)
    {
//    	long long k;
//    	cin>>k;
//    	for (int i = 0; i < a; i++)
//    	{
//    		long long it = find(F+i, F+a, F[i]+k) - F;
//    		if (it < a)
//    		{
//    			cout<<(it-i)<<' '<<C[i]<<endl;
//    			break;
//			}
//		}
		long long k;
    	cin>>k;
    	long long left=1, right= lower_bound(F+1,F+a+1,k) - F;
    	// cout<<right<<endl;
    	if (F[right]!=k)
    	{
    		right--;
		}
    	long long count = F[right];
    	while (count + C[right] - C[left-1] <= k && right <= a)
    	{
    		count += C[right];
    		count -= C[left]-1;
    		left++;
    		right++;
		}
		cout<<right - left + 1<<' '<<C[left-1]<<endl;
	}
}
