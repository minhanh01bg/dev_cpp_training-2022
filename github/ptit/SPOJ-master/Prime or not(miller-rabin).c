#include <stdio.h>
#include<math.h>
long long mul(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
long long modu(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b>0)
    {
        if(b%2==1)
        {
            x=mul(x,y,c);
        }
        y=mul(y,y,c);
        b/=2;
    }
    return(x%c);
}
long long miller(long long p){
	long long a,m,temp,s;
	  if(p<2){
        return 0;
    }
    if(p!=2 && p%2==0){
        return 0;
    }
    s=p-1;
    while(s%2==0){
        s/=2;
    }
        a=rand()%(p-1)+1,temp=s;
        m=modu(a,temp,p);
        while(temp!=p-1 && m!=1 && m!=p-1){
            m=mul(m,m,p);
            temp *= 2;
        }
        if(m!=p-1 && temp%2==0){
            return 0;
        }
    return 1;
}
int main(void) {
	int t;
	long long n;
	long long c;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%lld",&n);
	c=miller(n);
	if(c==1)
	printf("YES\n");
	else
	printf("NO\n");
	}
	return 0;
}

