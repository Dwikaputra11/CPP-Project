
// C++ program to find LCM of n elements
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
// Utility function to find
// GCD of 'a' and 'b'
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
// Returns LCM of array elements
ll findlcm(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}

int main()
{
	int t,i = 0, count = 0,bound = 1;bool found = false; 
	cin >> t;
	int p[t + 1];

	for(int i = 0; i < t; i++){
		cin >> p[i];
	}

	int lcm = findlcm(p,t);
	cout << lcm;


	return 0;
}
