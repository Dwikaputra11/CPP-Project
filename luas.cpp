#include <iostream>

using namespace std;

//tipe data double agar bisa bilangan desimal
double luas(double p, double l, double t){
	double s;
	s = 2*(p*l + p*t + l*t);
	return s;
}

double volume(double p, double l, double t){
	double v;
	v = p*l*t;
	return v;
}

int main()
{
	double p, l, t, lp, vol;

	cout << "masukkan panjang balok : " ;
	cin >> p;

	cout << "Masukkan lebar balok : " ;
	cin >> l;

	cout << "Masukkan tinggi balok : ";
	cin >> t;

	lp = luas(p, l, t);
	cout << "Luas Permukaan balok adalah " << lp << endl;

	vol = volume(p, l, t);
	cout << "Volume balok adalah " << vol << endl;

	cin.get();
	cin.get(); 
	return 0;
}
