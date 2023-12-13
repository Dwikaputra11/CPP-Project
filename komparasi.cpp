#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	int b = 3;

	//boolean adalah sebuah tag yang diisi oleh salah satu nilai true (1) atau false (0)
	bool hasil1, hasil2;
	// komparasi, relation 

	//sebanding
	hasil1 = ( a == b);
	

	//tidak sebanding
	hasil2 = ( a != b);
	

	//kurang dari
	hasil1 = ( a < b);


	//lebih dari
	hasil2 = ( a > b);

	cout << hasil1 << endl;
	cout << hasil2 << endl;

	cin.get();
	return 0;
}
