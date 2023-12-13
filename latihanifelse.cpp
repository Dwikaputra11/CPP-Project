#include <iostream>

using namespace std;

int main(){
	float angka1, angka2;
	float hasil = 0;
	int pilih_menu;
	
	cout << "--------------------" << endl;
	cout << "Kalkulator Sederhana" << endl;
	cout << "--------------------\n\n";
	cout << "- MENU KALKULATOR SEDERHANA -" << endl;
	cout << "\t- 2 BILANGAN - \t" << endl;
	cout << "1. Program Pekalian\n";
	cout << "2. Program Pembagian\n"; 
	cout << "3. Program Pengurangan\n"; 
	cout << "4. Program Pertambahan\n"; 
	cout << "Masukkan pilihan menu: "; cin >> pilih_menu;
	
	if(pilih_menu < 4 && pilih_menu > 0){ 
		// BLOK BENAR
		cout << "- INPUT ANGKA -\n";
		cout << "Masukkan angka 1: "; cin >> angka1;
		cout << "Masukkan angka 2: "; cin >> angka2;
		
		int opsi_display;
		cout << "-OPSI TAMPILAN-\n";
		cout << "1. IF-ELSE\n";
		cout << "2. SWITCH CASE\n";
		cout << "Pilih Opsi: "; cin >> opsi_display;
		
		switch (opsi_display){
			case 1:{
				if(pilih_menu == 1){
					hasil = angka1 * angka2;
					cout << "Hasil Perkalian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
				}else if(pilih_menu == 2){
					hasil = angka1/angka2;
					cout << "Hasil Pembagian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
				}else if(pilih_menu == 3){
					hasil = angka1 - angka2;
					cout << "Hasil Pengurangan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
				}else if(pilih_menu == 4){
					hasil = angka1 + angka2;
					cout << "Hasil Pertambahan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
				}
				break;
			}
			case 2: {
				switch(pilih_menu){
					case 1:{
						hasil = angka1 * angka2;
						cout << "Hasil Perkalian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
						break; // ingat isi break!
					}
					case 2: {
						hasil = angka1 / angka2;
						cout << "Hasil Pembagian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
						break;
					}
					case 3: {
						hasil = angka1 - angka2;
						cout << "Hasil Pengurangan" << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
						break;
					}
					case 4: {
						hasil = angka1 + angka2;
						cout << "Hasil Penjumlahan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
						break;
					}
				}
				break;
			}
		}
	}else{
		if(pilih_menu > 4) {
			cout << "Opsi lebih dari empat\n";
		}
		if(pilih_menu == 10){
			cout << "Pilih adalah sepuluh\n";
		}
		cout << "Opsi menu tidak terdaftar, silahkan input opsi yang sesuai!\n";
	}
	
	
	return 0;
}
