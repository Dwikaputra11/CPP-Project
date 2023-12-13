#include <iostream>
#include <string>

using namespace std;

class Mahasiswa{
    public: 
    string nama;
    double IPK;
    Mahasiswa(string nama,double IPK){
        Mahasiswa::nama = nama;
        Mahasiswa::IPK = IPK;
        // Mahasiswa:: digunakan untuk menunjut variabel local class
    } 
    // method digunakan untuk menambahkan sebuah fungsi dalam class
    void tampilkanData(){
        cout << nama << endl;
        cout << IPK << endl;
    }

    void ubahNama(const char* namaBaru){
        nama = namaBaru;
    }

    string getNama(){
        return Mahasiswa::nama;
    }
    double getIPK(){
        return Mahasiswa::IPK;
    }
    double tambahNilai(const double &nilai){
        return Mahasiswa::IPK + nilai;
    }
};


int main(int argc, char const *argv[])
{
    Mahasiswa mahasiswa1 = Mahasiswa("mugaro",3.78);
    Mahasiswa mahasiswa2 = Mahasiswa("otong",3.20);
    mahasiswa1.tampilkanData();
    mahasiswa2.tampilkanData();
    mahasiswa1.ubahNama("mario");
    mahasiswa1.tampilkanData();
    
    cout << "nama Mahasiswa1 : " << mahasiswa1.getNama() << endl;
    cout << "IPK Mahasiswa1 : " << mahasiswa1.getIPK() << endl;
    cout << "IPK Mahasiswa berubah menjadi : " << mahasiswa1.tambahNilai(.04) << endl; 

    return 0;
}
