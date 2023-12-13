#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll gcd(ll a, ll b){
	if(a == 0)
		return b;
	return gcd(b%a,a);
}

ll findlcm(ll arr[],int n){
	ll bound = 1000000009;
	ll ans = arr[0];

	for(int i = 1; i < n; i++){
		ans = (((arr[i]*ans))/
			(gcd(arr[i],ans)));
	}
	return ans%bound;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	ll arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	ll lcm = findlcm(arr,n);

	cout << (long long) lcm;

	return 0;
}