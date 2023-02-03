#include <bits/stdc++.h>
using namespace std;

long long int findMinCost(long long int m, long long int r1, long long int r2, long long int r3);

int main()
{
  int t;
  long long int m, r1, r2, r3;
  
  cin >> t;
  
  while(t--){
    cin >> m >> r1 >> r2 >> r3;
    cout << findMinCost(m, r1, r2, r3) << endl;
  }
  
  return 0;
}

long long int findMinCost(long long int m, long long int r1, long long int r2, long long int r3){
  int rem;
  
  rem = m % 4;
  
  if(rem == 0){
    return 0;
  }else if(rem == 1){
    return min(r3, min(r2+r1, r1+r1+r1));
  }else if(rem == 2){
    return min(r2, min(r1+r1, r3+r3));
  }else if(rem == 3){
    return min(r1, min(r3+r2, r3+r3+r3));
  }
  
  return 0;
}
