#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream myFile;
	string output,buffer,simpang;
	bool isData = false;
	int no;
	string nama;

	myFile.open("data.txt");

	// menampilkan kata 
	// myFile >> data;
	// ketika membaca filenya lagi maka yang akan dibaca adalah kata selanjutnya
	// myFile >> data;
	// yang ditampilkan adalh kata yang pertama sebelum spasi

	// menampilkan satu baris kaliamta dengan ditambah kalimat setelah enter
	// getline(myFile,buffer);
	// output.append("\n" + buffer);
	// getline(myFile,buffer);
	// output.append("\n" + buffer);

	// ada beberapa mode flag
	// ios:: in -> keadaan default
	// ios:: ate -> memulai pada baris terakhir
	// ios:: binary -> membaca file biner(hexadecimal)

	//menampilkan data sampai kata "data"
	while(!isData){
		getline(myFile,buffer);
		output.append("\n" + buffer);
		if(buffer == "data"){
			isData = true;
		} 
	}
	cout << output << endl; //menampilkan hasil baca data dari file
	getline(myFile,buffer); // membaca data dan dimasukkan ke variabel buffer
	simpang = buffer;
	cout << simpang << endl; //untuk menampilakan "no  nama"
	// menampikan data nomer dan nama
	// eof() digunakan untuk menyatakan akhir dari file, jika bukan akhir dari file maka program tetap berjalan
	while(!myFile.eof()){
		myFile >> no;
		myFile >> nama;
		cout << no <<"\t" << nama << endl;
	}

	return 0;
}
