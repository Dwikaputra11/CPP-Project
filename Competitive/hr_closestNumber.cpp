#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

 // link : https://www.hackerrank.com/challenges/closest-number/problem

int main() {
  int T, a, b, x;
  int p; 
  cin >> T;
  vector<int> result;
 for (int i=0; i<T; i++){
  cin >> a >> b >> x;
  p = pow(a,b) + x/2;
  result.push_back(p - (p%x));
 }

 for(int i = 0; i < result.size(); i++){
   cout << result[i] << endl;
 }

 return 0;
}