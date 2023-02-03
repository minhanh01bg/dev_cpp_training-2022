#include<bits/stdc++.h>
using namespace std;
double cToF(int C);
//Position this line where user code will be pasted.
int main()
{
    int T;//number of testcases
    int C,F;
    cin >> T; //input number of testcases
    while(T--){
        cin >> C;//input temperature in celscius
        cout << floor(cToF(C)) << endl; //print the output
    }
    return 0;
}
//User function Template for C++
//You need to complete this function
double cToF(int C)
{
    return (double)((C * 9) / 5) + 32;
}