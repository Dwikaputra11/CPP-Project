#include <iostream>
#include <fstream>//terdiri darai -> ofstream(open file), ifstream(read file),fstream(file)

using namespace std;

// dalam menulis file eksternal ini kita perlu mendeklarasi standar library #include <fstream>
// dengan syntax"nya adalah ofstream,ifstream,dan fstream
// setelah kita mengcompile maka file yang kita buka akan dibuat, jangan lupa untuk mengisi namafile.close()
// agar file akan di berhentikan
// di file ini juga kita bisa menggunakan tipe data integer


int main()
{
	ofstream myFile;

	// ada 3 mode
	// ios::out -> operasi output ini bentuk default dari out file
	// ios::app(append) -> menuliskan pada akhir baris
	// ios::trunc -> default,membuat file jika tidak ada, dan kalau ada maka akan dihapus (seperti overwrite)


	myFile.open("data1.txt",ios::out);
	myFile << "penulisan pada data1\n";
	myFile.close();

	myFile.open("data2.txt",ios::trunc);
	myFile << "penulisan pada data2\n";
	myFile.close();

	int a=898989; //menuliskan int ke file eksternal
	myFile.open("data3.txt",ios::app);
	myFile << "penulisan pada data3\n";
	myFile << a;
	myFile.close();

	return 0;
}

