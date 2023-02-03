#include<bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x);
  
long long int floorSqrt(long long int x) ;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}



// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    if(x<=1)
        return x;
        
    long long int start=1, end=x, mid=-1, result=-1;
    
    while(start<=end){
        mid = (start+end)/2;
        
        //if perfect square
        if(mid*mid == x)
            return mid;
            
        if(mid*mid < x){
            start = mid+1;
            result = mid;
        }else{
            end = mid-1;
        }
    }
    return result;
}