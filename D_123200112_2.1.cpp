#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	
	float x,y,z;
	int a = 4;
	int b = 2;
	int c = 2;
	int d = 1;

	cout << "Nama 	: I Made Dwika Putra Riswanda\n" ; 
	cout << "NIM 	: 123200112\n" ;

	// operasi hitung 

	cout << "a" << " = " << a << endl;
	cout << "b" << " = " << b << endl;
	cout << "c" << " = " << c << endl;
	cout << "d" << " = " << d << endl;

	//prioritas hitungan adalal yang paling terakhir ditulis
	//hitung 
	x = (a + b)*c - d % c;
	y = x/(a - b * c + d);
	z = x + d * y;
	x = z - y + 2;


	cout << "x" << " = " << x << endl;
	cout << "y" << " = " << y << endl;
	cout << "z" << " = " << z << endl;

 




	cin.get();
	cin.get();
	return 0;
}
