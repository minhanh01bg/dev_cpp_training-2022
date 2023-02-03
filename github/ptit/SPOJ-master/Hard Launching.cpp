#include <iostream>
#include<math.h>
using namespace std;
double g=9.806;
double pi=2.0*acos(0.0);
int main() {
	int t,i=1;
	double d,v,ang;
	cin>>t;
	while(t--)
    {
		cin>>d>>v;
		if(d*g<=v*v){
		ang=0.5*asin((d*g)/(v*v));
		printf("Scenario #%d: %.2lf\n",i,(180.0*ang/pi));
       }
		else {
		ang=-1;
		cout<<"Scenario #"<<i<<": -1\n";
        }
		i++;
	}
	return 0;
}
