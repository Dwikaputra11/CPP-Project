#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	unsigned long long m,split = 1;
	int n;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) split = (long long)(split*2);
	if(split <= m) cout << "kalah";
	else cout << "menang";

	return 0;
}
