#include <iostream>

using namespace std;

int main()
{
	int umur;
	string jabatan;

	cout << "Masukkan umur	: ";
	cin >> umur;

	cout << "Masukkan jabatan	:";getline(cin,jabatan);

	if (umur <= 20 && jabatan == "boss"){
		cout << "Dia Boss Muda" << endl;
	}
	else if(umur >=21 && jabatan == "boss"){
		cout << "Dia Boss Tua" << endl;
	}


	cin.get();
	return 0;
}
