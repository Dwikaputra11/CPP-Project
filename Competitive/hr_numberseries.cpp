#include <iostream>
using namespace std;

//link : https://www.hackerrank.com/challenges/summing-the-n-series/problem

int main()

{
unsigned long long int t,n;

cin >> t;

for(int i=1;i<=t;i++)

{

cin >> n;

n=(n%1000000007)*(n%1000000007)%1000000007;

cout << n << endl;

}

}
