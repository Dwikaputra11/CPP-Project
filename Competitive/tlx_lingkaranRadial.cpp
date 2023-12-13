#include <iostream>
using namespace std;

int main(){
	int n,m;

	cin >> n >> m;

	int v[m],u[m];

	for(int i = 0 ; i < m; i++){
		cin >> v[i] >> u[i];
	}

	int ans = (1 + (n - 2)*2) - m;

	cout << ans;


	return 0;
}
