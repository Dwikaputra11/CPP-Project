#include <iostream>

using namespace std;

int main()
{
	// f(n) = f(n - 1) + f (n - 2)
	//f_n = f_n1 + f_n2
	int n;
	int f_n;
	int f_n1;
	int f_n2;

	cout << "Program Fibonacci\n";
	cout << "Masukkan Nilai awalnya: ";
	cin >> f_n1;
	cout << "Masukkan Nilai ke-n: ";
	cin >> n;

	
	f_n2 = 0; 
	f_n = f_n1 + f_n2;
	cout << f_n << " ";
	for (int i = 1; i<n; i++){
		f_n = f_n1 + f_n2;
		f_n2 = f_n1;
		f_n1 = f_n;
		cout << f_n << " ";
	}

	/*int n; //belum selesai
	int f_n;
	int f_n1;
	int f_n2;
	int i = 1;
	

	cout << "Program Fibonacci\n";
	cout << "Masukkan Nilai ke-n: ";
	cin >> n;


	do {
		f_n = f_n1 + f_n2; 
		f_n2 = f_n1;
		f_n1 = f_n;
		cout << i << endl; 
		i++;


	} while (i < n); */


	cin.get();
	cin.get();
	return 0;
}
