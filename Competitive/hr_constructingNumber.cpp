#include <iostream>
using namespace std;
// link : https://www.hackerrank.com/contests/hourrank-25/challenges/constructing-a-number/problem

int main() {
  long t,n,num;
  cin >> t;
  for(int i = 0; i < t; i++){
      long sum = 0;
      cin >> n;
      for (int j = 0; j < n; j++) {
        cin >> num;
        sum+=num;
      }
      if(sum%3 == 0) cout << "Yes" << endl;
     else cout << "No" << endl; 
  }
    
    return 0;
}