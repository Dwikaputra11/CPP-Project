#include <iostream>
using namespace std;

int main()
{	
	int warna ,a , b, c, d ;
	char pilihan;
	string notasi, sifat;

	cout <<"------------------------------------------------------------------------------\n";
	cout <<"\t\tNama : \n";
	cout <<"\t\tNIM  : \n";
	cout <<"------------------------------------------------------------------------------\n";
	cout <<"Program Menentukkan Notasi, Sifat, dan Perpaduan Warna Harmonis Warna- warni:\n"; 
	cout <<"1. Orange\t\t2. Red-Orange\t\t3. Red\n";
	cout <<"4. Red-Violet\t\t5. Violet\t\t6. Blue-Violet\n";
	cout <<"7. Blue\t\t\t8. Blue-Green\t\t9. Green\n";
	cout <<"10. Yellow-Green\t11. Yellow\t\t12.Yellow-Orange\n";

	cout << endl;

	cout <<"Pilihan Warna Nomor : "; cin >> warna;
	cout << endl;
	if(warna == 1 || warna == 5 || warna == 9){
		notasi = "Sekunder";
	}else if(warna == 11 || warna == 3 || warna == 7){
		notasi = "Primer";
	}else{
		notasi = "Tersier";
	}
	sifat = (warna >= 1 && warna <= 6)? "Hangat" : "Sejuk";
	if(warna <= 12){
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
			a = warna + 1; // penjumlahan
			b = warna - 1; // pengurangan
			c = warna + 2;
			d = warna - 2;
			if(b <= 0){
				b = b + 12;
			}
			if(d <= 0){
				d = d + 12;
			}
			if(a > 12){
				a = a - 12;
			}
			if(c > 12){
				c = c - 12; 
			}
			cout << "Perpaduan Warna Analogues dengan warna nomor: " << endl;
			cout << a << "," << c << " Atau " << d << "," << b << " Atau " << a << "," << b;
		}else if(pilihan == 'b'){
			a = warna + 6;
			if(a > 12){
				a = a - 12;
			}
			cout << "Perpaduan Warna Complementary dengan warna nomor: \n";
			cout << a << endl;
		} else if(pilihan == 'c'){
			a = warna + 5;
			b = a + 2;
			if(a > 12){
				a = a - 12;
			}
			if(b > 12){
				b = b - 12;
			}
			cout << "Perpaduan Warna Split Complementary dengan warna nomor: \n";
			cout << a << "," << b << endl;
		} else if(pilihan == 'd'){
			a = warna + 4;
			b = a + 4;
			if(a > 12){
				a = a - 12;
			}
			if(b > 12){
				b = b - 12;
			}
			cout << "Perpaduan Warna Triadic Complementary dengan warna nomor: \n";
			cout << a << "," << b << endl;
		} else if(pilihan == 'e'){
			a = warna + 3;
			b = a + 3;
			c = b + 3;
			if(c > 12){
				c = c - 12;
			}
			if(a > 12){
				a = a - 12;
			}
			if(b > 12){
				b = b - 12;
			}
			cout << "Perpaduan Warna Split Complementary dengan warna nomor: \n";
			cout << a << "," << b << "," << c << endl;
		} else{
			cout << "Yang Anda Pilih Tidak Ada" << endl;
		}
	}else{
		cout << "nomor yang anda pilih tidak tersedia\n";
	}

	cin.get();
	return 0;
}