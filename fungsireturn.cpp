#include <iostream>
using namespace std;

/*tipe data nama fungsi(input){
	perhitungan;
	statemen;
	return hasil;
}*/

int kuadrat(int x){
	int y;
	y = x * x;
	return y;
}

int tambah(int a, int b){
	int c;
	c = a + b;
	return c;
}

int main()
{
	int input, hasil, x, y, hasil2;//tipedata input harus sama dengan fungsi

	cout << "Nilai Kuadrat dari: ";
	cin >> input;

	hasil = kuadrat(input);

	cout << hasil << endl;

	cout << "Masukkan nilai x: ";
	cin >> x;

	cout << "Masukkan Nilai y: ";
	cin >> y;

	hasil2 = tambah(x , y);//input nilainya sesuai dengan rumusnya klo mau y jadi a maka ketik y duluan
	cout << "Hasil tambah: " << hasil2 << endl; 


	cin.get();
	return 0;
}
