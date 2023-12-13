#include <iostream>
using namespace std;

int main()
{
	int a = 5;


	//pointer
	int *aPtr = nullptr; //untuk addres kosong pakai nullptr <*aPtr = nullptr>
	aPtr = &a; // &a = addres dari a
	//tanda * merupakan simbol dari pointer

	cout << "Nilai dari a: " << a << endl;
	cout << "aPtr menunjuk alamat dari a : " << aPtr << endl; 
	cout << "address a : " << &a << endl;
	cout << "address aPtr: " << &aPtr << endl;

	//deferencing, mengambil nilai data dari sebuah pointer

	int b = a;
	cout << "Mengambil nilai dari pointer a: " << *aPtr << endl;

	int c = 'D' + 'K' + ' ' + '1' + '2' + '1' + '2' + ' ' + 'P' ;
	cout << c << endl;
	c = 'D' + 'K' + ' ' + '3' + '4' + '3' + ' ' + 'F';
	cout << c << endl;
	c = 'D' + 'K' + ' ' + '1' + '2' + '3' + ' ' + 'P' + 'P' ;
	cout << c << endl;
	// c = ':';
	// cout << c << endl;
	// c = '4';
	// cout << c << endl;

	return 0;
}