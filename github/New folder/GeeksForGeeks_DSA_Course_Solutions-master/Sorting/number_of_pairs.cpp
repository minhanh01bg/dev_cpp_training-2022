#include<bits/stdc++.h>
using namespace std;

long long countPairs(int X[], int Y[], int m, int n);
int count(int x, int Y[], int n, int NoOfY[]);

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}

 
// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input array
// m, n: size of arrays X[] and Y[] respectively

int count(int x, int Y[], int n, int NoOfY[]){
    //base cases
    if(x == 0) return 0;
    
    if(x == 1) return NoOfY[0];
    
    //find upper bound and elements after it
    //satisfies the condition
    int* index = upper_bound(Y, Y+n, x);
    int ans = (Y+n)-index;
    
    //exceptions
    ans += (NoOfY[0] + NoOfY[1]);
    
    if(x == 2)
        ans -= (NoOfY[3] + NoOfY[4]);
    
    if(x == 3)
        ans += NoOfY[2];
        
    return ans;
}



long long countPairs(int X[], int Y[], int m, int n)
{
   int NoOfY[5] = {0};
   
   for(int i=0;i<n;i++){
       if(Y[i] < 5)
            NoOfY[Y[i]]++;
   }
   
   //sort Y[]
   sort(Y, Y+n);
   
   long long total_pairs = 0;
   
   //for each x in X[]
   for(int i=0;i<m;i++)
        total_pairs += count(X[i], Y, n, NoOfY);
        
    return total_pairs;
}