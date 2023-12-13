#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// int sisi; 
	// cout << "Gambar Persegi" << endl;
	// cout << "Masukkan Banyak Sisi: "; cin >> sisi; // 4

	// for(int i = 1; i <= sisi*sisi; i++){
	// 	if(i%sisi == 0)  cout << "*" << endl;
	// 	else cout << "* ";
	// 	// cout << "* ";
	// }
	// cout << "\ni : " << i;

	// int lebar,panjang;
	// cout << "Gambar Persegi Panjang" << endl;
	// cout << "Masukkan panjang: "; cin >> panjang;
	// cout << "Masukkan lebar: "; cin >> lebar;

	// for(int i = 1; i <= lebar; i++){
	// 	cout <<"loop " << i <<"->mulai ";
	// 	for(int j = 1; j <= panjang; j++){
	// 		cout << "* ";
	// 	}
	// 	cout << "-> selesai" << endl; 
	// }

	int sisi;
	cout << "Segitiga Siku Sama Kaki" << endl;
	cout << "Masukkan sisi: "; cin >> sisi;
	for(int i = 1; i<= sisi; i++){
		for(int j = 1; j <= i; j++){
			cout << "*";
		}
		cout << endl;
	}






	return 0;
}