#include<stdio.h>
int main()
{
    long long x,t,j,A;
    scanf("%lld",&t);
    for(;t;t--){
    scanf("%lld",&A);x=A*A+1;
    for(j=A;j;j--) if (x%j==0) {printf("%lld\n",2*A+j+x/j);break;}
    }
}
