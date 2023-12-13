#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, nilaiMat, nilaiAlgo, nilaiKal;
    cout << "Masukkan banyak mahasiswa: "; cin >> num;

    for(int i = 0; i < num; i++){
        cout << "\nMahasiswa " << i + 1 << endl;
        cout << "Masukkan nilai Matdis: "; cin >> nilaiMat;
        cout << "Masukkan nilai Algoritma: "; cin >> nilaiAlgo;
        cout << "Masukkan nilai Kalkulus: "; cin >> nilaiKal;
        int total = nilaiAlgo + nilaiMat + nilaiKal;
        double rata = total/3;
        cout << "Total Nilai: " << total << endl;
        cout << "Rata-rata: " << rata << endl;
    }


    return 0;
}
