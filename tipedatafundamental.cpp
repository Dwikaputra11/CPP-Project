#include <iostream>

using namespace std;

int main()
{
	int a = 1;

	cout << a << endl;
	//mencari besar data memori a
	cout << sizeof(a) << " byte" << endl;
	//besar data 1 byte yaitu: 8-bit yang berisi angka biner 0&1
	//jika besar data 4 byte maka sama dengan 32-bit
	/* pada interger (int) nilai maksimum yang bisa dipakai yaitu 2^(n-1)(karena posisi terdepan adalah simbol +/-)
	jadi niali maksimum data 4byte adalah 2^31 yaitu 2147483647 (harusnya 2147483648 tapi angka 0 juga termasuk maka dikurang satu)
	dan untuk nilai minimumnya -2147483648 (kenapa gk berukurang, karena nilai 0 sudah termasuk dalam nilai maksimum)*/
	//untuk melihat nilai maksimum&minimum suatu int atau tipe data lain :
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<int>::min() << endl;
	cin.get();
	return 0;
}
