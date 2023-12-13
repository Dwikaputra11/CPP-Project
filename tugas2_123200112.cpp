#include <iostream>

using namespace std;

int main()
{
	int d1, d2, r, a;
	int total;
	int umurayah, umuribu, umuranak1, umuranak2;

	cout << "Umur Ayah 	: ";
	cin >> umurayah;
	if (umurayah > 20){
		d1 = 30000;
	} else if (umurayah > 12 && umurayah <= 20){
		d1 = 20000;
	} else if (umurayah <= 12){
		d1 = 15000;
	}

	cout << "umur Ibu 	: ";
	cin >> umuribu;
	if (umuribu > 20){
		d2 = 30000;
	} else if (umuribu > 12 && umuribu <= 20){
		d2 = 20000;
	} else if (umuribu <= 12){
		d2 = 15000;
	}


	cout << "Umur Anak 1 	: ";
	cin >> umuranak1;
	if (umuranak1 > 20){
		r = 30000;
	} else if (umuranak1 > 12 && umuranak1 <= 20){
		r = 20000;
	} else if (umuranak1 <= 12){
		r = 15000;
	}


	cout << "Umur Anak 2 	: ";
	cin >> umuranak2;
	if (umuranak2 > 20){
		a = 30000;
	} else if (umuranak2 > 12 && umuranak2 <= 20){
		a = 20000;
	} else if (umuranak2 <= 12){
		a = 15000;
	} 


	total = 30*(d1 + d2 + r + a);

	cout << "Tagihan satu bulan adalah " << "Rp" << total << endl;  

	cin.get();
	cin.get();
	return 0;
}
