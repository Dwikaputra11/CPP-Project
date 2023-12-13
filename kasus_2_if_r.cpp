#include <iomanip>
#include <iostream>

using namespace std;

const int MENIT_30 = 1800;
const int JAM_2 = 7200;

int main() {
  string nama, plat;
  int jmlRoda, jamMasuk, mntMasuk, dtkMasuk;
  int jamKeluar, mntKeluar, dtkKeluar;
  int masuk, keluar, lamaParkir;
  int totalBayar;
  char opsiKartu;
  bool punyaKartu, valid;

  cout << "====PARKIR SERGUN====\n";
  cout << "Input Data:\n";
  cout << "Nama: ";
  getline(cin, nama);
  cout << "Plat Kendaraan: ";
  getline(cin, plat);
  cout << "Jumlah Roda Kendaraan: ";
  cin >> jmlRoda;
  cout << "Durasi Parkir: \n";
  cout << "\nWaktu Masuk\n";
  cout << "===========\n";
  cout << "Masukkan jam : ";
  cin >> jamMasuk;
  cout << "Masukkan menit : ";
  cin >> mntMasuk;
  cout << "Masukkan detik : ";
  cin >> dtkMasuk;
  cout << "\nWaktu Keluar\n";
  cout << "============\n";
  cout << "Masukkan jam : ";
  cin >> jamKeluar;
  cout << "Masukkan menit : ";
  cin >> mntKeluar;
  cout << "Masukkan detik : ";
  cin >> dtkKeluar;

  cout << "Punya Kartu Member (Y/N): ";
  cin >> opsiKartu;

  // KALKULASI
  masuk = (jamMasuk * 3600) + (mntMasuk * 60) + dtkMasuk;
  keluar = (jamKeluar * 3600) + (mntKeluar * 60) + dtkKeluar;
  lamaParkir = keluar - masuk;

  // Pastikan Jam masuk lebih kecil dari jam keluar
  if (jamMasuk < jamKeluar) {
    valid = true;
  } else if (jamMasuk == jamKeluar) {
    if (mntMasuk < mntKeluar)
      valid = true;
    else if (mntMasuk == mntKeluar) {
      if (dtkMasuk < dtkKeluar)
        valid = true;
      else
        valid = false;
    } else
      valid = false;
  } else
    valid = false;

  // check apakah input waktu parkit valid
  if (valid) {
    if (jmlRoda >= 2) {
      switch (jmlRoda) {
      case 2: {
        if (lamaParkir <= MENIT_30)
          totalBayar = 3000;
        else if (lamaParkir > MENIT_30 && lamaParkir <= JAM_2)
          totalBayar = 5000;
        else
          totalBayar = 10000;
        break;
      }
      case 3: {
        if (lamaParkir <= MENIT_30)
          totalBayar = 4000;
        else if (lamaParkir > MENIT_30 && lamaParkir <= JAM_2)
          totalBayar = 8000;
        else
          totalBayar = 15000;
        break;
      }
      case 4: {
        if (lamaParkir <= MENIT_30)
          totalBayar = 5000;
        else if (lamaParkir > MENIT_30 && lamaParkir <= JAM_2)
          totalBayar = 10000;
        else
          totalBayar = 20000;
        break;
      }
      default: {
        if (lamaParkir <= MENIT_30)
          totalBayar = 8000;
        else if (lamaParkir > MENIT_30 && lamaParkir <= JAM_2)
          totalBayar = 15000;
        else
          totalBayar = 30000;
        break;
      }
      }
      // cek kepemilikan member
      punyaKartu = (opsiKartu == 'Y' || opsiKartu == 'y');

      if (punyaKartu)
        totalBayar -= totalBayar * 0.2;

      cout << "\n====STRUK PARKIR====\n";
      cout << "Nama : " << nama << endl;
      cout << "Jumlah roda kendaraan : " << jmlRoda << endl;
      cout << "Waktu Masuk  : " << jamMasuk << " : ";
      cout << mntMasuk << " : " << dtkMasuk << endl;
      cout << "Waktu keluar : " << jamKeluar << " : ";
      cout << mntKeluar << " : " << dtkKeluar << endl;
      cout << "Total Bayar : Rp. " << totalBayar;
    } else {
      cout << "! PROSES GAGAL !\n";
      cout << "Jumlah roda kendaraan tidak vaild, silahkan ulangi proses "
              "lagi!\n";
    }
  } else {
    cout << "! PROSES GAGAL !\n";
    cout << "Waktu Masuk dan Waktu Keluar tidak seusai, Silahkan ulangi proses "
            "lagi\n";
  }
}