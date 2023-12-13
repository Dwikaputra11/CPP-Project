#include <iostream>
using namespace std;

//ini untuk deklarasi fungsi yang ada sesudah main 
//prototipe 
double hitung_luas(double p, double l);

void hasil_hitung(double x);
int main()
{
	double p, l, hasil;
	cout <<"Masukkan lebar: ";
	cin >> l;

	cout << "Masukkan panjang: ";
	cin >> p;

	hasil = hitung_luas(p,l);

	cout << hasil << endl;

	cin.get();
	return 0;
}

double hitung_luas(double p, double l){
	return p * l; // bisa langsung dimasukkin rumusnya
}

void hasil_hitung(double x){
	cout << x << endl;
}