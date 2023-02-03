#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	N=1;
	int b;
	cin>>b;
	while(N--)
	{
		string a;
		cin>>a;
		int x=0, y=0;
		string token = "front";
		for (int i=0; i<a.length(); i++)
		{
			if (token=="front")
			{
				if (a[i]=='G') y++;
				else if (a[i]=='L') 
				{
					x--;
					token="left";
				}
				else if (a[i]=='R') 
				{
					x++;
					token="right";
				}
				else if (a[i]=='B') 
				{
					y--;
					token="back";
				}
			}
			else if (token=="back")
			{
				if (a[i]=='G') y--;
				else if (a[i]=='L') 
				{
					x++;
					token="right";
				}
				else if (a[i]=='R') 
				{
					x--;
					token="left";
				}
				else if (a[i]=='B') 
				{
					y++;
					token="front";
				}
			}
			else if (token=="left")
			{
				if (a[i]=='G') x--;
				else if (a[i]=='L') 
				{
					y--;
					token="back";
				}
				else if (a[i]=='R') 
				{
					y++;
					token="front";
				}
				else if (a[i]=='B') 
				{
					x++;
					token="right";
				}
			}
			else
			{
				if (a[i]=='G') x++;
				else if (a[i]=='L') 
				{
					y++;
					token="front";
				}
				else if (a[i]=='R') 
				{
					y--;
					token="back";
				}
				else if (a[i]=='B') 
				{
					x--;
					token="left";
				}
			}
		}
		cout<<x<<' '<<y<<endl;
	}
}
