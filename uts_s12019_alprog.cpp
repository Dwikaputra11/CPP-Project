#include <iostream>
#include <string>
using namespace std;

int main()
{
	string jjgStudi,prgStudi;
	int thnMasuk;
	string kode = "";
	cout << "Jenjang Studi : "; getline(cin,jjgStudi);
	if(jjgStudi == "S1"){
		kode = "12";
		cout << "Program Studi : "; getline(cin,prgStudi);
		if(prgStudi == "Teknik Kimia") kode += "1"; //"12" + "1" = "121"
		else if(prgStudi == "Teknik Industri") kode += "2";
		else if(prgStudi == "Informatika") kode += "3";
		else if(prgStudi == "Sistem Informasi") kode += "4";
	}
	else kode += "021";

	cout << "Tahun Masuk : "; cin >> thnMasuk;
	kode += to_string(thnMasuk%1000) + "0"; // konversi tipe integer ke string
	cout << kode;

	return 0;
}
