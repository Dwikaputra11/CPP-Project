#include <iostream>
using namespace std;

// link : https://tlx.toki.id/problems/ngoding-seru-2015-oct-pemula/D

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int s,n,d;
	cin >> s >> n >> d;
	while(n--){
		cout << s <<"\n";
		s += d;
	}

	return 0;
}
