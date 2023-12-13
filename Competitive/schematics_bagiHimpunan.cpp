#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll factorial(ll i){
	if(i == 0) return 1;
	else if(i == 1) return 1;
	else return i*factorial(i - 1);

}

int main()
{
	ll n, h;
	cin >> n >> h;
	ll ans = 0,bound = 1000000007;
	if(n-h == 1) cout << "0";
	else cout << (factorial(n)/(factorial(h)*(factorial(n-h))))%bound - (n - (h - 1));

	return 0;
}
