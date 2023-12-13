#include <iostream>

using namespace std;

int main()
{
	int a;

	cout << "masukkan nilai = ";
	cin >> a;

	switch (a){
		case 1: 
			cout << "a = 1" << endl;
			break;
		case 2: 
			cout << "a = 2" << endl;
			break;
		case 3: 
			cout << "a = 3" << endl;
			break;
		case 4: 
			cout << "a = 4" << endl;
			break;
		case 5: 
			cout << "a = 5" << endl;
			break;
		default: //mode ini digunakan seperti else 
			cout << "angka tidak memenuhi syarat" << endl;
			break;
	} // dalam pengggunaan switch case, ketika dieksekusi/ci compile jika dia bernilai benar maka sistem akan menggap yang dibawahnya jga benar
	//maka dri itu untuk membuat sistem hanya membaca satu angka saja maka perlu ditambahkan tag break
	// jangan terlalu banyak menggunakan break, opsi yang lebih baik adalah menggunakan if else

	cout << "akhir program" << endl;

	cin.get();
	return 0;
}
