#include <iostream>
#include <string>

using namespace std;

class Polos{
    public:
        string dataString;
        int dataInteger;
};

class Mahasiswa{
    public:
        string nama,NIM,jurusan;
        double IPK;
        // contructor tanpa parameter
        Mahasiswa(){
            cout << "ini adalah contructor\n";
        }
        // contructor dengan parameter
        Mahasiswa(string inputNama,string inputNIM,string inputJurusan, double inputIPK){

            Mahasiswa::nama = inputNama;
            Mahasiswa::NIM = inputNIM;
            Mahasiswa::jurusan = inputJurusan;
            Mahasiswa::IPK = inputIPK;

            cout << Mahasiswa::nama << endl;
            cout << Mahasiswa::NIM << endl;
            cout << Mahasiswa::jurusan << endl;
            cout << Mahasiswa::IPK << endl;
        }
};

int main(int argc, char const *argv[])
{
    Mahasiswa maba = Mahasiswa("momo","121213","teknik informatika",4.00);
    Mahasiswa baru = Mahasiswa("tanu","121673","teknik komputer",3.59);
    
    return 0;
}
