#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	int b = 3;

	bool hasil;

	//opretaor logika: not, and, or

	//not
	cout << "untuk not \n";
	hasil = !(a == 2);
	cout << hasil << endl;

	//and : kedua nilai harus benar untuk mendapatkan nilai true
	cout << "untuk and \n";
	hasil = (a == 2) and (b==3); // true and true
	cout << hasil << endl;
	hasil = (a == 4) and (b==3); // false and true
	cout << hasil << endl;
	hasil = (a == 2) && (b==4); // true and false
	cout << hasil << endl;
	hasil = (a == 6) && (b==5); // false and false
	cout << hasil << endl;

	//or : salah satu bernilai benar maka nilainya true
	cout << "untuk or \n";
	hasil = (a == 2) or (b==3); // true and true
	cout << hasil << endl;
	hasil = (a == 4) or (b==3); // false and true
	cout << hasil << endl;
	hasil = (a == 2) || (b==4); // true and false
	cout << hasil << endl;
	hasil = (a == 6) || (b==5); // false and false
	cout << hasil << endl;

	cin.get();
	return 0;
}
