#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
    // Access Modifier --> public, private, protected
    public:
        string nama,jurusan,NIM;
        double IPK;
};

int main(int argc, char const *argv[])
{
    Mahasiswa data;
    data.nama = "dwika";
    data.NIM = "1232022";
    data.jurusan = "teknik informatika";
    data.IPK = 3.92;
    cout << "nama dari data : " << data.nama << endl;
    cout << "NIM dari data : " << data.NIM << endl;
    cout << "Jurusan dari data : " << data.jurusan << endl;
    cout << "IPK dari data : " << data.IPK << endl;
    Mahasiswa data1;
    data1.nama = "putra";
    data1.NIM = "1232024";
    data1.jurusan = "teknik komputer";
    data1.IPK = 3.80;
    cout << "nama dari data1 : " << data1.nama << endl;
    cout << "NIM dari data1 : " << data1.NIM << endl;
    cout << "Jurusan dari data1 : " << data1.jurusan << endl;
    cout << "IPK dari data1 : " << data1.IPK << endl;
    
    return 0;
}
