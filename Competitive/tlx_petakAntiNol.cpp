#include <iostream>
using namespace std;

// link : https://tlx.toki.id/problems/troc-20/C

int main(int argc, char const *argv[])
{
	int n,m,t;
	cin >> n >> m;
	// int arr[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> t;
			if(t){
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";

	// for(int i = 0 ; i < n; i++){
	// 	for(int j = 0 ; j < m; j++){
	// 		cin >> arr[n][m];
	// 	}
	// }

	// int k = 0;
	// for(int i = k; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		if(i == 0){
	// 			if(j == 0){
	// 				if(arr[i][j] == 1){
	// 					arr[i + 1][j] = 1;
	// 					arr[i][j + 1] = 1;
	// 				}
	// 			}else if(j == m - 1){
	// 				if(arr[i][j] == 1){
	// 					arr[i][j-1] = 1;
	// 					arr[i + 1][j] = 1;
	// 				}
	// 			}else{
	// 				if(arr[i][j] == 1){
	// 					arr[i][j+1] = 1;

	// 				}
	// 			}
	// 		}else if(i == n - 1){
	// 			if(j == 0){

	// 			}else if(j == m - 1){

	// 			}else{
					
	// 			}
	// 		}
	// 	}
	// }


	// return 0;
}
