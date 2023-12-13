#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mahasiswa{
    public:
        string nama,jurusan,NIM;

        Mahasiswa(string nama, string jurusan, string NIM){
            Mahasiswa::nama = nama;
            Mahasiswa::jurusan = jurusan;
            Mahasiswa::NIM = NIM;
        }

        void display(){
            cout << nama << endl;
            cout << jurusan << endl;
            cout << NIM << endl;
        }

        string getData(){
            return "\n" + nama + " " + jurusan + " " + NIM;
        }
};

class DBase{
    public:
    ifstream in;
    ofstream out;
    string fileName; 
    DBase(const char* fileName){
        DBase::fileName = fileName;
    }

    void save(Mahasiswa data){
        data.display();

        DBase::out.open(DBase::fileName, ios::app);

        DBase::out << data.getData();
        DBase::out.close();
    }

    void showAll(){
        DBase::in.open(DBase::fileName, ios::in);
        string nama,NIM,jurusan;
        int index = 1;

        while(!DBase::in.eof()){
            in>>nama;
            in>>NIM; 
            in>>jurusan;

            cout << index++ << " " << nama << " " << NIM << " " << jurusan << endl;
        }
        DBase::in.close();
    }
};

int main(int argc, char const *argv[])
{
    string nama,jurusan,nim;
    cout << "Nama : "; getline(cin,nama);
    cout << "Jurusan : "; getline(cin, jurusan);
    cout << "NIM : "; getline(cin,nim);
    Mahasiswa dataMahasiswa = Mahasiswa(nama,jurusan,nim); // ini disimpen di stack
    // Mahasiswa dataMahasiswa1(nama,jurusan,nim); bisa kita buat seperti ini
    
    // Mahasiswa* data = new Mahasiswa(nama,jurusan,nim); // ini disimpen di heap
    // cara aksesnya
    // (*data).display(); atau data->display();

    // kalo pingin bikin deklarasi 
    // Mahasiswa* data;
    // data = new Mahasiswa(...);
    // data->display();
    DBase database = DBase("data.txt");

    database.save(dataMahasiswa);

    cout << "Seluruh data mahasiswa : \n";
    database.showAll();
    return 0;
}
