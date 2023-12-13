#include <iostream>
using namespace std;

int main()
{	
	int warna ,b , c, d, e ;
	char pilihan;
	string notasi, sifat;

	cout <<"------------------------------------------------------------------------------\n";
	cout <<"\t\tNama : I Made Dwika Putra Riswanda\n";
	cout <<"\t\tNIM  : 123200112\n";
	cout <<"------------------------------------------------------------------------------\n";
	cout <<"Program Menentukkan Notasi, Sifat, dan Perpaduan Warna Harmonis Warna- warni:\n";
	cout <<"1. Orange\t\t2. Red-Orange\t\t3. Red\n";
	cout <<"4. Red-Violet\t\t5. Violet\t\t6. Blue-Violet\n";
	cout <<"7. Blue\t\t\t8. Blue-Green\t\t9. Green\n";
	cout <<"10. Yellow-Green\t11. Yellow\t\t12.Yellow-Orange\n";

	cout << endl;

	cout <<"Pilihan Warna Nomor : "; cin >> warna;
	cout << endl;
	if(warna == 1 || warna == 5 || warna == 9 ){
		notasi = "Sekunder";
	} else if(warna == 11 || warna == 3 || warna == 7){
		notasi = "Primer";
	}else{
		notasi = "Tersier";
	}
	sifat = (warna >= 1 && warna <= 6)? "Hangat" : "Sejuk";
	if(warna >= 1 && warna <=6){
		sifat = "Hangat";
	}else{
		sifat = "Sejuk";
	}
	cout << "Notasi Warna : " << notasi << endl;
	cout << "Sifat Warna  : " << sifat << endl;

	cout <<"Perpaduan Warna Harmonis\n";
	cout <<"a. Perpaduan warna Analogues\n";
	cout <<"b. Perpaduan Warna Complementary\n";
	cout <<"c. Perpaduan Warna Split Complementary\n";
	cout <<"d. Perpaduan Warna Triadic Complementary\n";
	cout <<"e. Perpaduan Warna Tetrad Complementary\n";
	cout <<"Pilihan : "; cin >> pilihan;

	if(pilihan == 'a'){
		b = warna + 1;
		c = warna - 1;
		d = warna + 2;
		e = warna - 2;
		if(c <= 0){
			c = c + 12;
		}
		if(e <= 0){
			e = e + 12;
		}
		if(b > 12){
			b = b - 12;
		}
		if(d > 12){
			d = d - 12; 
		}
		cout << "Perpaduan Warna Analogues dengan warna nomor: " << endl;
		cout << b << "," << d << " Atau " << e << "," << b << " Atau " << b << "," << c;
	} else if(pilihan == 'b'){
		b = warna + 6;
		if(b > 12){
			b = 12 -b;
		}
		cout << "Perpaduan Warna Complementary dengan warna nomor: \n";
		cout << b << endl;
	} else if(pilihan == 'c'){
		b = warna + 5;
		c = b + 2;
		if(b > 12){
			b = b - 12;
		}
		if(c > 12){
			c = c - 12;
		}
		cout << "Perpaduan Warna Split Complementary dengan warna nomor: \n";
		cout << b << "," << c << endl;
	} else if(pilihan == 'd'){
		b = warna + 4;
		c = b + 4;
		if(b > 12){
			b = b - 12;
		}
		if(c > 12){
			c = c - 12;
		}
		cout << "Perpaduan Warna Triadic Complementary dengan warna nomor: \n";
		cout << b << "," << c << endl;
	} else if(pilihan == 'e'){
		b = warna + 3;
		c = b + 3;
		d = c + 3;
		if(d > 12){
			d = d - 12;
		}
		if(b > 12){
			b = b - 12;
		}
		if(c > 12){
			c = c - 12;
		}
		cout << "Perpaduan Warna Split Complementary dengan warna nomor: \n";
		cout << b << "," << c << "," << d << endl;
	} else{
		cout << "Yang Anda Pilih Tidak Ada" << endl;
	}

	cin.get();
	return 0;
}