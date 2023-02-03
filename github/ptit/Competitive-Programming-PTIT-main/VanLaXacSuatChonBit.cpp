#include <bits/stdc++.h>
using namespace std;
long long factor[64];
double C[64][64];
double bonusone[64];
double getthis[64];
void factory()
{
    factor[0]=1;
    for (int i=1; i<64; i++) factor[i] = 2 * factor[i-1];
}
long long getSetBitsFromOneToN(long long N)
{
	long long two = 2,ans = 0;
	long long n = N;
	while(n){
		ans += (N/two)*(two>>1);
		if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1;
		two <<= 1;
		n >>= 1;
	}
	return ans;
}
double check(long long data, long long total)
{
    //data = (data & 0x55555555) + ((data >> 1) & 0x55555555);
    //data = (data & 0x33333333) + ((data >> 2) & 0x33333333);
    //data = (data & 0x0F0F0F0F) + ((data >> 4) & 0x0F0F0F0F);
    //data = (data & 0x00FF00FF) + ((data >> 8) & 0x00FF00FF);
    //data = (data & 0x0000FFFF) + ((data >> 16) & 0x0000FFFF);
    //return (double)data / (double)total;
    return (double)(getSetBitsFromOneToN(factor[total]-1) - getSetBitsFromOneToN(data-1)) / (double)total;
}
double checkNguoc(long long total, long long data)
{
	return (double)(getSetBitsFromOneToN(data) - getSetBitsFromOneToN(factor[total]-1)) / (double)(total+1);
}
void getC()
{
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for (int i=1; i<64; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if (j==0 || j==i) C[i][j]=1;
            else C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}
void getbonus()
{
	memset(bonusone,0,sizeof(bonusone));
	for (int i=1; i<64; i++)
	{
		for (int j=0; j<i; j++) bonusone[i] += ((double)(j+1)/(double)(i))*C[i-1][j];
		//bonusone[i]/=factor[i-1];
	}
}
void bonusthesecond()
{
	memset(getthis,0,sizeof(getthis));
	for (int i=1; i<64; i++)
	{
		getthis[i]=getthis[i-1]+bonusone[i];
	}
}
double bonus(int key1, int key2)
{
    if (key1==key2) return 0;
    return getthis[key2] - getthis[key1];
}
int main()
{
    factory();
    getC();
    getbonus();
    bonusthesecond();
    //for (int i=0; i<64; i++) cout<<bonusone[i]<<' ';
    //cout<<endl;
    //for (int i=0; i<5; i++)
    //{
    //	for (int j=0; j<5; j++)
    //	{
    //		cout<<C[i][j]<<' ';
    //	}
    //	cout<<endl;
    //}
    int N;
    cin>>N;
    while (N--)
    {
        long long a,b;
        cin>>a>>b;
        double sum=0;
        if (b<a) swap(a,b);
        if (a==1) 
        {
        	a++;
        	sum=1;
        }
        long long key1=0, key2=0;
        while (factor[key1]<=a) key1++;
        while (factor[key2]<=b) key2++;
        key2--;
        //cout<<key1<<' '<<key2<<endl;
        if (key2 >= key1) 
        {
        	sum += check(a, key1);
        	sum += checkNguoc(key2, b);
        	sum += bonus(key1, key2);
        	//cout<<bonus(key1,key2)/(b-a+1)<<endl;
        }
        else
        {
        	sum += check(a, key1);
        	sum -= check(b+1, key1);
        }
        //cout<<a<<' '<<key1<<' '<<b<<' '<<key2<<endl;
        //cout<<key1<<' '<<key2<<endl;
        sum/=(double)(b-a+1);
        cout<<setprecision(5)<<fixed<<sum<<endl;
    }
}
