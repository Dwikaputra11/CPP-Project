#include <iostream>

using namespace std;

int main()
{

	float a,b,hasil ;
	char aritmatika;

	cout << "Selamat Datang di Program Kalkulator \n \n" ;

	//memasukkan nilai dari user 
	cout << "Masukkan nilai pertama: ";
	cin >> a;
	cout << "Pilih operator +,-,/,*: ";
	cin >> aritmatika; 	
	cout << "Masukkan nilai kedua: ";
	cin >> b;

	cout << "\nHasil Perhitungan: ";
	cout << a << aritmatika << b ;
	
	if (aritmatika == '+'){
		hasil = a + b;
	} else if (aritmatika == '-'){
		hasil = a - b;
	} else if (aritmatika == '/'){
		hasil = a / b;
	} else if (aritmatika == '*')
		hasil = a * b;
	} else {
		cout << "operator anda salah";
	}

	cout << " = " << hasil << endl;

	cin.get();
	cin.get();
	return 0;
}
