#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Masukkan banyak pola n: ";
	cin >> n;

	cout << "Pola ke 1\n";
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1; j <= i ; j++){
			cout << "*";
		}
		cout << endl;
	}

	cout << "Pola ke 2\n";
	for (int i = 1 ; i <= n ; i++){
		for (int j = n; j >= i ; j--){
			cout << "*";
		}
		cout << endl;
	}

	cout << "Pola ke 3\n";
	for (int i = 1 ; i <= n ; i++){
		for (int j = n; j >= i ; j--){
			cout << " ";
		}
		for (int k = 1; k <= i; k++){
			cout << "*";
		}
		cout << endl;
	}

	cout << "Pola ke 4\n";
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1; j <= i ; j++){
			cout << " ";
		}
		for (int k = n; k >= i; k--){
			cout << "*";
		}
		cout << endl;
	}

	cout << "Pola ke 5\n";
	for(int i = 1; i <= n ; i++){
		for (int j = n; j >= i; j--){
			cout << " ";
		}
		for (int k = 1 ; k <= (2*i - 1) ; k++){
			cout << "*";
		}
		cout << endl;
	}

	cout << "Pola ke 6\n";
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1; j <= i ; j++){
			cout << " ";
		}
		for (int k = (2*n-1); k >= (2*i-1); k--){
			cout << "*";
		}
		cout << endl;
	}

	//cara lain
	/* cout << "Pola ke 6\n";
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1; j <= i ; j++){
			cout << " ";
		}
		for (int k = n; k >= (2*i-n); k--){
			cout << "*";
		}
		cout << endl;
	}*/

	cout << "Pola ke 7\n";
	//pola ke 5
	for(int i = 1; i <= n ; i++){
		for (int j = n; j >= i; j--){
			cout << " ";
		}
		for (int k = 1 ; k <= (2*i - 1) ; k++){
			cout << "*";
		}
		cout << endl;
	}

	//pola ke 6
	for (int i = 2 /*menghilangkann 1 baris*/ ; i <= n ; i++){
		for (int j = 1; j <= i ; j++){
			cout << " ";
		}
		for (int k = (2*n-1); k >= (2*i-1); k--){
			cout << "*";
		}
		cout << endl;
	}


	
	
	

	cin.get();
	return 0;
}
