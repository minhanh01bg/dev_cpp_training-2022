#include<bits/stdc++.h>
using namespace std;

int mean(int A[],int N);
int median(int A[],int N);

int main()
{
    //testcase
    int T;
    cin>>T;
   
    //looping testcase
    while(T--)
    {
        //number of elements in array
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        cout<<mean(a,N)<<" "<<median(a,N)<<endl;
    }
    return 0;
}

int median(int A[],int N)
{
    
    sort(A,A+N);
    
    if(N % 2 == 0){
        return (A[(N-1)/2] + A[N/2]) / 2;
    }else{
        return (A[N/2]);
    }
}
int mean(int A[],int N)
{
    long long sum = 0L;
    for(int i=0;i<N;i++){
        sum += A[i];
    }
    return (sum/N);
}