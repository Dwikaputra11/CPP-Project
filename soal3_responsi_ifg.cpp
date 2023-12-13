// Program_administrasi_cuci_kendaraan
#include <iomanip>
#include <iostream>

using namespace std;

void header(), salah();
string kp, tgl;
int m, n, i = 1, hmot = 0, hmob = 0, tot = 0;
int jml = 0, tol = 1, jmlb = 0, tolb = 1;

void inputBuku() {
  cout << "Masukkan jumlah buku yang terjual pada hari ini : ";
  cin >> n;
  string tipeBuku[n + 1], namaBuku[n + 1];
  int harga[n + 1];
  int totalHarga = 0, tipe;
  cout << "\n\n";
  system("cls");
  header();
  for (i = 0; i < n; i++) {
    cout << "\nBuku ke-" << i + 1 << endl;
    cin.ignore();
    cout << "Masukkan nama Buku  : ";
    getline(cin, namaBuku[i]);
    cout << "Tipe Buku    : \n";
    cout << "1. Novel\n";
    cout << "2. Biografi\n";
    cout << "3. Ilimiah\n";
    cout << "Pilih tipeBuku: ";cin >> tipe;

    switch (tipe) {
    case 1: {
      tipeBuku[i] = "Novel";
      harga[i] = 30000;
      break;
    }
    case 2: {
      tipeBuku[i] = "Biografi";
      harga[i] = 40000;
      break;
    }
    case 3: {
      tipeBuku[i] = "Ilimiah";
      harga[i] = 50000;
      break;
    }
    }

    cout << "Harga Buku    : Rp." << harga[i];
    totalHarga += harga[i];
    cout << endl;
  }

  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  cout << " NO | Nama Buku      | Tipe Buku          | Harga      "
          "       |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  for (i = 0; i < n; i++) {
    cout << resetiosflags(ios::adjustfield) << " " << setiosflags(ios::left)
         << setw(3) << i + 1 << "|";
    cout << " " << setiosflags(ios::left) << setw(15) << namaBuku[i]
         << "|";
    cout << " " << setiosflags(ios::left) << setw(19) << tipeBuku[i] << "|";
    cout << " " << setiosflags(ios::right) << setw(18) << harga[i] << "|\n";
  }
  cout << "--------------------------------------------------------------------"
          "--------"
       << endl;
  cout << "Total pemasukkan dari penjualan buku : Rp " << totalHarga;
  cout << "\n\n";
}

/* ---Program_Utama--- */
int main() {
  char pilih;
  header();
  cout << "Pilihan menu :\n";
  cout << "1. Input Buku\n";
  cout << "2. Keluar\n";
  cout << "Masukkan pilihan : ";
  cin >> pilih;
  switch (pilih) {
  case '1':
    inputBuku();
    break;

  case '2':
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
  cout << "         BAGAN ADMINISTRASI TOKO BUKU\n\n";
  cout << "-----------------------------------------------------------\n";
}