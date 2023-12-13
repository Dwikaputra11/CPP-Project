#include <iostream>
using namespace std;

int main()
{
	string user;
	int pass;
	float rata, harian, uts, uas;
	int pilihan;
	cout << "Login Akun ==============\n";

	cout << "Username	: "; 
	cin >> user;
	
	cout << "Password	: "; 
	cin >> pass;

	cout << "==========================" << endl;

	if (user == "mahasiswa" && pass == 12345){
		cout << "Login Berhasil!\n";
		cout << endl;
		cout << "Input Nilai Mata Kuliah" << endl;
		cout << "1. Algoritma dan Pemrograman" << endl;
		cout << "2. Kalkulus" << endl;
		cout << "Pilih : "; cin >> pilihan;
		if (pilihan == 1){
			cout << "Nilai Harian \t:"; cin >> harian;
			cout << "Nilai UTS \t:"; cin >> uts;
			cout << "Nilai UAS \t:"; cin >> uas;
			rata = (harian + uts + uas)/3;
			if (rata >= 80){
				cout << "Anda lulus Algoritma dan Pemrograman dengan nilai " << rata << endl;
			} else {
				cout << "Anda tidak lulus Algoritma pemrograman dengan nilai " << rata << endl;
			}

		}else if (pilihan == 2){
			cout << "Nilai Harian \t:"; cin >> harian;
			cout << "Nilai UTS \t:"; cin >> uts;
			cout << "Nilai UAS \t:"; cin >> uas;
			rata = (harian + uts + uas)/3;
			cout << endl;
			if (rata >= 80){
				cout << "Anda lulus Kalkulus dengan nilai " << rata << endl;
			} else  {
				cout << "Anda tidak lulus Kalkulus dengan nilai " << rata << endl;}
		} else {cout << "input anda salah" << endl;}

	} else if(user != "mahasiswa" && pass != 12345){
		cout << "Username dan Password Anda Salah" << endl;
	} else if (user != "mahasiswa" && pass == 12345){
		cout << "Username Anda Salah" << endl;
	} else if (user == "mahasiswa" && pass != 12345){
		cout << "Password Anda Salah" << endl;
	}

	cout << endl << endl;

	cout << "--------------------------" << endl;


	cin.get();
	cin.get();
	return 0;
}
