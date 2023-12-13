#include <iostream>

using namespace std;

int main(){
	float angka1, angka2; // efadsiofhdifj
	/*
	 * sidfds
	 * sdgksdjfsd]sdfhdf
	 * dkfgudf
	 * sdfljhsdfj
	 * sdfjdsjhf*/
	float hasil;
	int pilih_menu;
	int opsi;
	
	cout << "--------------------\n";
	cout << "KALKULATOR SEDERHANA\n";
	cout << "--------------------\n\n";
	
	cout << "- MENU KALKULATOR SEDERHANA -\n";
	cout << "1. Perkalian\n";
	cout << "2. Pembagian\n";
	cout << "3. Pengurangan\n";
	cout << "4. Penjumlahan\n";	
	cout << "Pilih Operasi: "; cin >> pilih_menu;
	
	cout << "- INPUT 2 ANGKA -\n";
	cout << "Masukkan angka 1: "; cin >> angka1;
	cout << "Masukkan angka 2: "; cin >> angka2;
	
	
	cout << "-\tTAMPILAN\t-\n";
	cout << "1. IF-ELSE\n";
	cout << "2. SWITCH-CASE\n";
	cout << "Pilih Opsi: "; cin >> opsi;
	
	switch(opsi){
		case 1: {
			if(pilih_menu == 1){
				hasil = angka1 * angka2;
				cout << "Hasil Perkalian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
			}else if(pilih_menu == 2){
				hasil = angka1 / angka2;
				cout << "Hasil Pembagian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
			}else if(pilih_menu == 3){
				hasil = angka1 - angka2;
				cout << "Hasil Pengurangan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
			}else if(pilih_menu == 4){
				hasil = angka1 + angka2;
				cout << "Hasil Penjumlahan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
			}else {
				cout << "Opsi tidak tersedia, silahkan pilih menu yag sesuai!\n";
			}
			break;	
		}
		case 2: {
			switch(pilih_menu){
				case 1: {
					hasil = angka1 * angka2;
					cout << "Hasil Perkalian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
					break;
				}
				case 2: {
					hasil = angka1 / angka2;
					cout << "Hasil Pembagian " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
					break;
				}
				case 3: {
					hasil = angka1 - angka2;
					cout << "Hasil Pengurangan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
					break;
				}
				case 4: {
					hasil = angka1 + angka2;
					cout << "Hasil Penjumlahan " << angka1 <<  " dan " << angka2 << " adalah " << hasil << endl;
					break;
				}
				default: {
					cout << "Opsi tidak tersedia, silahkan pilih menu yag sesuai!\n";
				}
			}
		}
	}
	
	
	
	return 0;
}
