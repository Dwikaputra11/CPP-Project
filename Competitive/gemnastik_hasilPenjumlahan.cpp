#include <iostream>
using namespace std;

int main()
{
	int n,m,q;

	cin >> n >> m >> q;

	int arr[n + 5][m + 5];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}

	int x1,y1,x2,y2;
	for(int i = 0; i < q; i++){
		int sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = x1; j <= x2; j++){
			for(int k = y1; k <= y2; k++){
				sum += arr[j][k];
			}
		}
		cout << sum << endl;
	}


	return 0;
}
