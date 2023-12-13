#include <iostream>
#include <array>

using namespace std;

//looping array untuk c++11 keatas
/*
	for(deklarasi variabel : array){
		statement
	}
*/
int main()
{
	array <int,10> arrayNilai = {0,1,2,3,4,5,6,7,8,9};

	for(int nilai : arrayNilai){
		cout << "Address " << &nilai << " Nilainya: " << nilai << endl;
	}

	cout << endl;
	//memodifikasi array dengan referensi
	for(int &nilaiRef : arrayNilai){
		nilaiRef *= 2;
	}

	for(int &nilaiRef : arrayNilai){
		cout << "Address " << &nilaiRef << " Nilainya: " << nilaiRef << endl;
	//addressnya kembali ke asal arraynya masing masing alias tidak sama
	}

	cin.get();
	return 0;
}
