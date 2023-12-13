#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	fstream myFile;
	int number = 123456;
	// untuk membuat filenya perlu mamanggil file ke command prompt
	myFile.open("data.bin",ios::out | ios::binary);

	// digunakan untuk menulis ulang bentuk angka menjadi hexadecimal pada file
	myFile.write(reinterpret_cast<char*>(&number),sizeof(number));
	// .write untuk menulis variabel ke dalam file

	myFile.close();

	return 0;
}
