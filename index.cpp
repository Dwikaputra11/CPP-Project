#include <iostream>
#include <exception>

using namespace std;

typedef struct data *typeptr;
struct data {
	int nim;
	string nama,alamat;
};
typeptr mhs[100];
data ad;

void menupilih(int *menu){
	cout << "Menu : " << endl;
	cout << "1. Input Data\n2. Lihat Data\n3. Cari Data" << endl;
	cout << "Pilih menu : "; cin >> *menu;
}

void input(){
	int banyak,nim;
	string alamat,nama;
	cout << " - - - Input Data - - -" << endl << endl;
	cout << "Masukkan banyak mahasiswa : "; cin >> banyak;
	typeptr temp[banyak];
	for(int i=0; i<banyak; i++){
		temp[i] = (data*)malloc(sizeof(data));
		cout << "Mahasiswa ke- " << i+1 << endl;
		cout << "NIM\t\t: ";cin >> nim;
		// cin.ignore();
		cout << "Nama\t\t: ";cin >> nama;
		cout << "Alamat\t: ";cin >> alamat;
		try{
			temp[i] -> nim = nim;
			temp[i] -> nama = nama;
			temp[i] -> alamat = alamat;
		}catch(exception &e){
			cout << e.what() << endl;
		}
		
		// cout << "Selesai" << endl;
	}
	for(int i=0; i<banyak; i++){
		cout << "Mahasiswa ke- " << i+1 << endl;
		cout << "NIM\t\t: " << temp[i] ->nim << endl;
		cout << "Nama\t\t: " << temp[i] ->nama << endl;
		cout << "Alamat\t: " << temp[i] ->alamat << endl;
		mhs[i] = &ad;
	}

	system("pause");
	

}

int main() {
	
	int menu = 0;
	menupilih(&menu);
	input();
	return 0;
}
