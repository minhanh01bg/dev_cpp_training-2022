#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
void quadraticRoots(int a, int b, int c);
int main() {
	int T; 
	cin>>T; //input number of testcases
	
	while(T--)
	{
	    int a, b, c; 
	    cin>>a>>b>>c; //Input a, b, and c
	    
	    quadraticRoots(a,b,c);
	    cout<<endl;
	    
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//You need to complete this function
void quadraticRoots(int a,int b, int c)
{
   if(a == 0) //it's linear, not quadratic
    return;
    
    int d = b*b - 4*a*c; //d for discriminant
    double sqrt_d = sqrt(abs(d));
    
    if(d > 0){
        double rootone = floor((-b + sqrt_d) / (2.0 * a));
        double roottwo = floor((-b - sqrt_d) / (2.0 * a));
        rootone<roottwo?printf("%.lf %.lf", roottwo, rootone):printf("%.lf %.lf", rootone, roottwo);
    }else if(d == 0){ //when b^2 = 4ac
        printf("%.lf %.lf", (-b / (2.0*a)), (-b / (2.0*a)));
    }
    else
        printf("Imaginary");
}
