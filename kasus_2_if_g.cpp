#include <iostream>

using namespace std;

int main() {
  string nama;
  int beras, minyak, telur, jamDatang, uangBayar, kembalian;
  char punyaMember;

  cout << "Kasir Supermaket X\n";
  cout << "Masukkan Nama: ";
  getline(cin, nama);
  cout << "Masukkan Jam Datang: ";
  cin >> jamDatang;
  cout << "\nJenis Barang Belanja:\n";
  cout << "1. Telur (butir): ";
  cin >> telur;
  cout << "2. Beras (karung): ";
  cin >> beras;
  cout << "3. Minyak (liter): ";
  cin >> minyak;
  cout << "\nUang Bayar: ";
  cin >> uangBayar;
  cout << "Ada Kartu Member(Y/N): ";
  cin >> punyaMember;

  int totalHarga = telur * 2000 + beras * 30000 + minyak * 14000;

  if (jamDatang >= 7 && jamDatang <= 9)
    totalHarga -= totalHarga * 0.2;
  else if (jamDatang <= 15 && jamDatang >= 13)
    totalHarga -= totalHarga * 0.1;
  else if (jamDatang >= 19 && jamDatang <= 20)
    totalHarga -= totalHarga * 0.25;

  totalHarga -=
      (punyaMember == 'Y' || punyaMember == 'y') ? totalHarga * 0.2 : 0;

  kembalian = uangBayar - totalHarga;
  string status = (kembalian >= 0) ? "LUNAS" : "BELUM LUNAS";

  cout << "\n==== STRUK BELANJA ====\n";
  cout << "Nama Pelanggan: " << nama << endl;
  cout << "Jam Datang: " << jamDatang << ":00\n";
  cout << "\nDaftar Belanja: \n";
  cout << "Telur : " << telur << " butir\n";
  cout << "Beras : " << beras << " karung\n";
  cout << "Minyak: " << minyak << " liter\n";

  cout << "\nTotal Harga : Rp " << totalHarga << endl;
  cout << "Uang Bayar : Rp " << uangBayar << endl;
  cout << "Kembalian : Rp " << kembalian << endl;
  cout << "\nStatus : " << status << endl;
}