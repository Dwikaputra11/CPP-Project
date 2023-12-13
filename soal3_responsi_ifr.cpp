// Program_administrasi_cuci_kendaraan
#include <iomanip>
#include <iostream>

using namespace std;

void header(), salah();
string kp, tgl;
int m, n, i = 1, hmot = 0, hmob = 0, tot = 0;
int jml = 0, tol = 1, jmlb = 0, tolb = 1;

void cuciMotor() {
  cout << "Masukkan jumlah motor yang dicuci pada hari ini : ";
  cin >> n;
  string merek[n + 1], namaPelanggan[n + 1];
  int harga[n + 1];
  int totalHarga = 0, pilihMerek;
  cout << "\n\n";
  system("cls");
  header();
  for (i = 0; i < n; i++) {
    cout << "Pelanggan ke-" << i + 1 << endl;
    cin.ignore();
    cout << "Masukkan nama pelanggan  : ";
    getline(cin, namaPelanggan[i]);
    cout << "Merek Motor    : \n";
    cout << "1. Vario\n";
    cout << "2. Supra\n";
    cout << "3. Vespa\n";
    cout << "Pilih merek: "; cin >> pilihMerek;

    switch (pilihMerek) {
    case 1: {
      merek[i] = "Vario";
      harga[i] = 20000;
      break;
    }
    case 2: {
      merek[i] = "Supra";
      harga[i] = 15000;
      break;
    }
    case 3: {
      merek[i] = "Vespa";
      harga[i] = 30000;
      break;
    }
    }

    cout << "Harga servis    : Rp." << harga[i];
    totalHarga += harga[i];
    cout << endl;
  }

  cout << "Motor\n";
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  cout << " NO | Nama Pelanggan      | Merk Motor          | Harga      "
          "       |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  for (i = 0; i < n; i++) {
    cout << resetiosflags(ios::adjustfield) << " " << setiosflags(ios::left)
         << setw(3) << i + 1 << "|";
    cout << " " << setiosflags(ios::left) << setw(20) << namaPelanggan[i]
         << "|";
    cout << " " << setiosflags(ios::left) << setw(20) << merek[i] << "|";
    cout << " " << setiosflags(ios::right) << setw(18) << harga[i] << "|\n";
  }
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  cout << "Total pemasukkan dari service motor : Rp " << totalHarga;
  cout << "\n\n";
}

void cuciMobil() {
  cout << "Masukkan jumlah mobil yang dicuci pada hari ini : ";
  cin >> n;
  string merek[n + 1], namaPelanggan[n + 1];
  int harga[n + 1];
  int totalHarga = 0, pilihMerek;
  cout << "\n\n";
  system("cls");
  header();
  for (i = 0; i < n; i++) {
    cout << "\nPelanggan ke-" << i + 1 << endl;
    cin.ignore();
    cout << "Masukkan nama pelanggan  : ";
    getline(cin, namaPelanggan[i]);
    cout << "Merek Mobil    : \n";
    cout << "1. BRV\n";
    cout << "2. Avanza\n";
    cout << "3. Pajero\n";
    cout << "Pilih merek: ";cin >> pilihMerek;

    switch (pilihMerek) {
    case 1: {
      merek[i] = "BRV";
      harga[i] = 70000;
      break;
    }
    case 2: {
      merek[i] = "Avanza";
      harga[i] = 50000;
      break;
    }
    case 3: {
      merek[i] = "Pajero";
      harga[i] = 100000;
      break;
    }
    }

    cout << "Harga servis    : Rp." << harga[i];
    totalHarga += harga[i];
    cout << endl;
  }

  cout << "Motor\n";
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  cout << " NO | Nama Pelanggan      | Merk Mobil          | Harga      "
          "       |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  for (i = 0; i < n; i++) {
    cout << resetiosflags(ios::adjustfield) << " " << setiosflags(ios::left)
         << setw(3) << i + 1 << "|";
    cout << " " << setiosflags(ios::left) << setw(20) << namaPelanggan[i]
         << "|";
    cout << " " << setiosflags(ios::left) << setw(20) << merek[i] << "|";
    cout << " " << setiosflags(ios::right) << setw(18) << harga[i] << "|\n";
  }
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  cout << "Total pemasukkan dari service mobil : Rp " << totalHarga;
  cout << "\n\n";
}

/* ---Program_Utama--- */
int main() {
  char pilih;
  header();
  cout << "Pilihan menu :\n";
  cout << "1. Input rekap cuci motor\n";
  cout << "2. Input rekap cuci mobil\n";
  cout << "3. Keluar\n";
  cout << "Masukkan pilihan : ";
  cin >> pilih;
  switch (pilih) {
  case '1':
    cuciMotor();
    break;

  case '2':
    cuciMobil();
    break;

  case '3':
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
  cout << "-----------------------------------------------------------\n\n";
  cout << "         BAGAN ADMINISTRASI CUCI SERBAGUNA\n\n";
  cout << "-----------------------------------------------------------\n";
}