#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

class Interval{
    public:
        int buy;
        int sell;
};

void stockBuySell(int price[], int n);

int main(void)
{
	int t, n, price[MAX];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i=0;i<n;i++){
	        cin >> price[i];
	    }
	    stockBuySell(price, n);
	}
	return 0;
}

void stockBuySell(int price[], int n){
    // prices must be given for at least two days
    if(n == 1)
        return;
        
    // solution array
    Interval sol[n/2 + 1];
    
    int count = 0; // count of solution pairs
    
    // Traverse through given price array
    int i = 0;
    while(i < n-1){
        // Find local minima. Note that the limit is (n-2) as we are 
        // comparing present element to the next element.
        while((i < n-1) && (price[i+1] <= price[i]))
            i++;
            
        // if we reached the end, break
        // as no further solution possible
        if(i == n-1)
            break;
        
        // store the index of minima
        sol[count].buy = i;
        
        // get to next element
        i++;
        
        // Find local maxima. Note that the limit is (n-1) as we are 
        // comparing to previous element
        while((i < n) && (price[i] >= price[i-1]))
            i++;
        
        // store the index of maxima    
        sol[count].sell = i-1;
        
        // Increment count of buy/sell pairs
        count++;
    }
    
    if(count == 0){
        cout << "No Profit" << endl;
    }else{
        for(int i=0;i<count;i++){
            printf("(%d %d) ", sol[i].buy, sol[i].sell);
        }
        cout << endl;
    }
}