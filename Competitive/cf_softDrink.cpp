#include <iostream>
#include <algorithm>

// link : https://codeforces.com/problemset/problem/151/A#

using namespace std;

bool comp(long a, long b){
	return (a < b);
}

int main()
{
	long n,k,l,c,d,p,nl,np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;

	long drink = k*l/n;
	long slice = c*d;
	long salt = p/np;
	// cout << min({drink,slice,salt},comp) << endl;
	cout << min({drink,slice,salt},comp)/n;
	return 0;
}

