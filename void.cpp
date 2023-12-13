#include <iostream>
using namespace std;

//reporter : melaporkan kembali sebuah nilai
int kuadrat(int x){ //fungsi kembalian
	int y;
	y = x * x;
	return y;
}

/* void nama_fungsi(input){
	statment;
}*/

//worker : hanya mejalankan tanpa memberikan feedback ,tidak menggunakan return
void tampilkan(int input){
	cout <<"Hasil menggunakan void: ";
	cout << input << endl;
}


int main(int argc, char const *argv[])
{
	int input, hasil;
	cout << "Nilai Kuadrat dari: ";
	cin >> input;

	hasil = kuadrat(input);

	tampilkan(hasil);

	cin.get();
	cin.get();
	return 0;
}
