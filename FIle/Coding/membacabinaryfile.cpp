#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	fstream myFile;
	int hasil;
	myFile.open("data.bin", ios::in | ios::binary);
	// ios::in unruk membaca isi file
	myFile.read(reinterpret_cast<char*>(&hasil),sizeof(hasil));
	// .read untuk membaca 

	cout << "Besar Integer " << sizeof(hasil) << " byte" << endl;
	cout << hasil;
	myFile.close();	

	cin.get();
	return 0;
}

/*fstream myFile;
	int number = 12345;
	myFile.open("data.bin",ios::out | ios::binary);

	// digunakan untuk menulis ulang bentuk angka menjadi hexadecimal pada file
	myFile.write(reinterpret_cast<char*>(&number),sizeof(number));

	myFile.close();*/