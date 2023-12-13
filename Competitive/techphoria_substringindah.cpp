#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,k,n,p;
	double a,b;
	string s;
	cin >> t;
	while(t--){
		cin >> a >> b >> n >> p;
		n = pow(10,n);
		k = (a/b)*n;
		s = to_string(k);
		cout << s << endl;
	}

	return 0;
}
