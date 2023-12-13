#include <bits/stdc++.h>
using namespace std;

int D;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(0);
	int max = -99999999,min = 99999999;
	int n;

	cin >> n >> D;
	int x[n],y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int count = pow(abs(x[j] - x[i]),D) + pow(abs(y[j] - y[i]),D);
			if(count < min) min = count;
			if (count > max) max = count; 
		}
	}

	cout << min << " " << max << "\n";


	return 0;
}
