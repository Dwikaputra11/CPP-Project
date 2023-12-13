#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v;

	int a = 1,b = 2, temp = 0;
	v.push_back(a); v.push_back(b);
	while(b + a < n){
		temp = a + b;
		a = b;
		b = temp;
		v.push_back(temp);
	}
	for(int i = v.size() - 1; i >= 0; i--){
		if(v[i] <= n){
			n -= v[i];
			cout << "1";
		}else cout << "0";
	}
}

int main()
{
	int n;
	cin >> n;
	while(n--){
		solve();
		cout << "\n";
	}


	return 0;
}
