#include <iostream>

using namespace std;

int main()
{
	//assignment
	int a = 10;
	cout << "Nilai awal a adalah: " << a << endl;

	// assignment operator
	// variabel = variabel operator ekspresi
	//    a     =    a        -        3
	// variabel operator= ekspresi
	//    a         +=      3

	a += 3; 
	cout << "ditambah 3 menjadi " << a << endl;
	a -= 3; 
	cout << "dikurang 3 menjadi " << a << endl;
	a /= 3; 
	cout << "dibagi 3 menjadi " << a << endl;
	a *= 3; 
	cout << "dikali 3 menjadi " << a << endl;
	a %= 3; 
	cout << "dimodulus 3 menjadi " << a << endl;


	cin.get();
	return 0;
}
