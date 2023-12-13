#include <iostream>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); 
#define ll unsigned long long

ll findgcd(ll a, ll b){
	if(a == 0)
		return b;
	return findgcd(b%a,a);
}


int main()
{
	fast;
	ll gcd;
	ll a,b,c,d;
	ll e,f;
	cin >> a >> b >> c >> d;
	gcd = findgcd(a,b);
	a/= gcd;
	b/= gcd; 
	gcd = findgcd(c,d);
	c/= gcd;
	d/= gcd; 
	e = a*d + c*b;
	f = b*d;
	gcd = findgcd(e,f);

	cout << (long long) e/gcd << " " << (long long) f/gcd;


	return 0;
}