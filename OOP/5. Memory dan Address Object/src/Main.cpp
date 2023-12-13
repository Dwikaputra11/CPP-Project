#include <iostream>
#include <string>
#include <chrono>

using namespace std;

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Kosong{
    public :
        int data(){
            return 1;
        }
};

class Isi{
    public :
        int int1; // 4 byte
        int int2; // 4 byte
        double dataDouble; // 8 byte
        string dataString; // 24 byte
};

class Mahasiswa{
    public:
        string nama; // 24
        string NIM; // 24
        string jurusan; // 24

        Mahasiswa(const char* nama){
            Mahasiswa::nama = nama;
        }
};

int main(int argc, char const *argv[])
{
    // menampilkan memory kelas kosong

    cout << "Alokasi class kosong : " << sizeof(Kosong) << " byte" << endl;

    // alokasi memorik sebuah kelas bergantung pada jumlah ato tipe data yang ada dalam class
    cout << "Alokasi class isi : " << sizeof(Isi) << " byte" << endl;

    cout << "Alokasi class Mahasiswa : " << sizeof(Mahasiswa) << " byte" << endl << endl;
    
    // Address
    string a;
    string b;
    Mahasiswa object1 = Mahasiswa("ucup");
    Mahasiswa* object2 = new Mahasiswa("mario");
    string c; 
    string d;
    cout << &a << endl; // memori berada di stack
    cout << &b << endl; // memori berada di stack
    cout << &object1 << endl; // memori berada di stack
    // bedakan &object2 dengan object2
    /**
     * &object2
     * menupakan address dari variabel object2 itu sendiri
     * 
     * object2
     * merupakan address dari isi object2 yaiut Mahasiswa di heap 
     * karena alokasinya di heap maka object2 diletakkan di heap berupa address
     * 
     */
    cout << object2 << endl; // memori berada di heap
    cout << &c << endl; // memori berada di stack
    cout << &d << endl; //  memori berada di stack

    /**
     * @attention Stack
     * merupakan tempat memori sementara ketika program dijalankan
     * memori yang berada di stack khusus digunakan untuk program
     * setiap pendeklarasian akan menempati 1 tempat di stack berurutan termasuk array tiap indeknya
     * Karna memori di stack terbatas maka ketika lebih dari batas maka error stack overflow
     * 
     * @attention Heap
     * disediakanlah memori heap yang mana lebih besar dari stack
     * memori heap tidak untuk program saja, bisa ada game dan app lainnya
     * sistem akan mencari tempat kosong dalam heap
     * untuk menggunakan memori heap gunakan new
     */

    TimePoint *tStackStart = new TimePoint();
    TimePoint *tStackEnd = new TimePoint();
    TimePoint *tHeapStart = new TimePoint();
    TimePoint *tHeapEnd = new TimePoint();

    // cin.get();
    *tStackStart = Clock::now();
    Mahasiswa object3 = Mahasiswa("ucup");
    *tStackEnd = Clock::now();

    // cin.get();
    *tHeapStart = Clock::now();
    Mahasiswa* object4 = new Mahasiswa("otong");
    *tHeapEnd = Clock::now();

    chrono::duration<float> durasi = *tStackEnd - *tStackStart;
    cout << "Waktu pembuatan object di stack : " << durasi.count() << endl;
    durasi = *tHeapEnd - *tHeapStart;
    cout << "Waktu pembuatan object di Heap : " << durasi.count() << endl;
    // pembuatan object pada stack lebih cepat dari pada di heap

    return 0;
}
