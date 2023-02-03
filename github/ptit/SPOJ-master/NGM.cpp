#include <iostream>
using namespace std;

int main()
{
    unsigned long L;
    cin>>L;
    if(L%10==0)
        cout<<2<<endl;
    else
        cout<<1<<endl<<L%10<<endl;
    return 0;
}
