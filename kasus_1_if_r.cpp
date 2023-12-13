#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int angka;
	cin >> angka;

	if(angka > 0 && angka < 10) cout << "satuan";
	else if(angka > 9 && angka < 100)cout << "puluhan";
	else if(angka > 99 && angka < 1000)cout << "ratusan";
	else if(angka > 999 && angka < 10000)cout << "ribuan";
	else if(angka  > 9999 && angka < 100000)cout << "puluhribuan"; 


	return 0;
}
