#include <iostream>

using namespace std;

int main()
{
	char nama[1000];
	cout << "Masukkan Nama : ";
	cin >> nama;
	char nim [1000];
	cout << "Masukkan NIM : ";
	cin >> nim;

	//rata-rata uts dan uas
	float uts, uas, hasil;
	cout << "Masukkan nilai UTS : ";
	cin >> uts;
	cout << "Masukkan nilai UAS : ";
	cin >> uas;

	hasil = (uts + uas)/2;

	cout << "Atas nama " << nama <<" ," << " dengan NIM " << nim << " , \n"; 
	cout << "nilai rata-rata satu semester adalah " << hasil << endl; 
	


	cin.get();
	cin.get();
	return 0;
}
