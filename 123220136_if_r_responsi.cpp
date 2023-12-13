#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
void header(), salah();
void cuciMotor() 
{
string nama[100], harga[100];
int motor, mermot[100],totalharmot;
string namamotor[3]={Vario, Supra, Vespa};
cout << "Masukkan jumlah motor yang dicuci pada hari ini : "; cin >> motor;
cout << "\n\n";
system("cls");
header();
for (int i=1;i<=motor;i++) {
cout << "\nPelanggan ke-" << i << endl;
cin.ignore();
cout << "Masukkan nama pelanggan : "; getline(cin, nama[i]);
cout << "Merek Motor : \n";
cout << "1. Vario\n";
cout << "2. Supra\n";
cout << "3. Vespa\n";
cout << "Pilih merek: ";cin >> mermot[i];
switch (mermot) {
case 1: {harga[i] = 20000;
break;
}
case 2: {harga[i] = 15000;
break;
}
case 3: {harga[i] = 30000;
break;
}
}
cout << "Harga servis : Rp."<< harga[i];
totalharmot = totalharmot + harga[i];
cout << endl;
}
cout << "Motor\n";
cout <<"----------------------------------------------------------------------------"<< endl;
cout << " NO | Nama Pelanggan | Merk Motor | Harga"" |"<< endl;
cout <<"----------------------------------------------------------------------------"<< endl;
for (int i = 0; i < n; i++) {
cout << resetiosflags(ios::adjustfield) << " " << setiosflags(ios::left) << setw(3) << i + 1 
<< "|";
cout << " " << setiosflags(ios::left) << setw(20) << nama[i]<< "|";
cout << nama[i];
cout << " " << setiosflags(ios::left) << setw(20) << namamotor[mermot] << "|";
cout << " " << setiosflags(ios::right) << setw(18) << harga[i]<< "|\n";
}
cout <<"----------------------------------------------------------------------------"<< endl;
cout << "Total pemasukkan dari service motor : Rp " << totalharmot;
cout << "\n\n";
}
void cuciMobil() {
string nama[100], harga[100];
int mobil, mermob[100],totalharmob;
string namamobil[3]={BRV, Avanza, Pajero};
// deklarasi variabel,array,dll
cout << "Masukkan jumlah mobil yang dicuci pada hari ini : ";cin >> mobil;
cout << "\n\n";
system("cls");
header();
for (int j=1;j<=mobil;j++) {
cout << "\nPelanggan ke-" << j << endl;
cin.ignore();
cout << "Masukkan nama pelanggan : "; getline(cin, nama[j]);
cout << "Merek Mobil : \n";
cout << "1. BRV\n";
cout << "2. Avanza\n";
cout << "3. Pajero\n";
cout << "Pilih merek: "; cin >> mermob[j];
switch (mermob) {
case 1: {harga[j]=70000;
break;
}
case 2: {harga[j]=50000;
break;
}
case 3: {harga[j]=100000;
break;
}
}
cout << "Harga servis : Rp." << harga[j];
totalharmob = totalharmob + harga[j];
cout << endl;
}
cout << "Motor\n";
cout <<"----------------------------------------------------------------------------"<< endl;
cout << " NO | Nama Pelanggan | Merk Mobil | Harga"" |"<< endl;
cout <<"----------------------------------------------------------------------------"<< endl;
for (int i = 0; i < n; i++) {
cout << resetiosflags(ios::adjustfield) << " " <<
setiosflags(ios::left)
<< setw(3) << i + 1 << "|";
cout << " " << setiosflags(ios::left) << setw(20) << nama[j]<< "|";
cout << " " << setiosflags(ios::left) << setw(20) << namamobil[mermob] << "|";
cout << " " << setiosflags(ios::right) << setw(18) <<harga[j]<< "|\n";
}
cout <<"----------------------------------------------------------------------------"<< endl;
cout << "Total pemasukkan dari service mobil : Rp " << totalharmob;
cout << "\n\n";
}
/* ---Program_Utama--- */
int main() {
int menu;
header();
cout << "Pilihan menu :\n";
cout << "1. Input rekap cuci motor\n";
cout << "2. Input rekap cuci mobil\n";
cout << "3. Keluar\n";
cout << "Masukkan pilihan : ";cin >> menu;
switch (menu) {
case 1:
cuciMotor();
break;
case 2:
cuciMobil();
break;
case 3:
exit(0);
break;
default:
cout << "\nMaaf inputan anda salah" << endl;
salah();
}
}
// Program_tambahan
/* ---Input_awal_salah--- */
void salah() {
char ab;
do {
cout << "Apakah anda ingin kembali melanjutkan? [Y/N] ";
cin >> ab;
switch (toupper(ab)) {
case 'Y':
system("cls");
main();
case 'N':
exit(0);
}
} while (toupper(ab != 'Y' || ab != 'N'));
}
/* ---Format_kop--- */
void header() {
cout <<
"-----------------------------------------------------------\n\n";
cout << " BAGAN ADMINISTRASI CUCI SERBAGUNA\n\n";
cout <<"-----------------------------------------------------------\n";
}