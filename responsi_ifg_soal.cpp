#include <iostream>
using namespace std;

int main()
{
	// deklarasi tipe data

	do{
		cout << "Login Akun ==============\n";

		cout << "Username	: "; 
		// input username
		
		cout << "Password	: "; 
		// input password

		cout << "==========================" << endl;
		// syarat masuk akun
		if (){
			cout << "Login Berhasil!\n";
			cout << endl;
			cout << "Input Nilai Mata Kuliah" << endl;
			cout << "1. Algoritma dan Pemrograman" << endl;
			cout << "2. Kalkulus" << endl;
			cout << "Pilih : "; cin >> pilihan;
			if (pilihan == 1){
				// masukkan perintah
			}else if (pilihan == 2){
				// masukkan perintah	
			} else {
				cout << "input anda salah" << endl;
			}

		} else if(/*Jika password & username salah*/){
			// masukkan statement
		} else if (/*Jika username salah*/){
			// masukkan statement
		} else if (/*Jika password/username salah*/){
			// masukkan statement
		}

		cout << endl << endl;

		cout << "--------------------------" << endl;

		cout << "Ulang Program (Y/N)? "; cin >> ulangProgram;
	} while(/*Program diulang jika Y atau y*/);



	cin.get();
	cin.get();
	return 0;
}
