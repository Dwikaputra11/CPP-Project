#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main(){
  ll n,s;
  cin >> n >> s;
  ll last = n*s - n + 1;
  ll ans = 0;
  ans = (last*(2*n + (last - 1)))/2; 
  cout << (long long) ans%1000000007;
}