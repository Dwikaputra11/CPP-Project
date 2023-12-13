#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	
	int  jsks1, jsks2, jsks3;
	float mka1, mka2, mka3, ipk;

	cout << "INPUT NILAI MAHASISWA :" << endl;
	cout << "---------------------------------\n";
	cout << "NIM 	: 123200112" << endl;
	cout << "Nama 	: I Made Dwika Putra Riswanda" << endl;

	cout << "Nilai MKA 1 (0-4)	= "; cin >> mka1; 
	cout << "Jumlah SKS MKA 1	= "; cin >> jsks1;

	cout << "Nilai MKA 2 (0-4)	= "; cin >> mka2; 
	cout << "Jumlah SKS MKA 2	= "; cin >> jsks2;

	cout << "Nilai MKA 3 (0-4)	= "; cin >> mka3; 
	cout << "Jumlah SKS MKA 3	= "; cin >> jsks3;

	

	cout << "---------------------------------\n\n";

	ipk = (mka1*jsks1 + mka2*jsks2 + mka3*jsks3)/(jsks1 + jsks2 + jsks3);
	

	cout << "Mahasiswa dengan nama I Made Dwika Putra Riswanda " << "(123200112)" << " mendapatkan IPK = " << setprecision(3) << ipk << endl; 
	cin.get();
	cin.get();
	return 0;
}
