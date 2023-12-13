#include <iostream>
using namespace std;

 // link : https://www.hackerrank.com/challenges/game-with-cells/problem

int main() {
  int sum =0;
  int n,m;
  cin >> n >> m;
   
cout << (n+n%2)*(m+m%2)/4;
  return 0;
}