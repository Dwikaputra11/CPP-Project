#include <iostream>

using namespace std;

int luas(int p, int l, int t){
	int s;
	s = 2*(p*l + p*t + l*t);
	return s;
}

int volume(int p, int l, int t){
	int v;
	v = p*l*t;
	return v;
}

int main()
{
	int p, l, t, lp, vol;

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
	return 0;
}
