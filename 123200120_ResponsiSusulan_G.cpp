#include <iostream>

using namespace std;
typedef struct Tamu *typeptr;
struct Tamu{
    string nama;
    int anggota;
    string warna;
    typeptr next;
};
typedef struct barangSouvenir *typeWarna;
struct barangSouvenir{
    string warna;
    typeWarna next;
};

typeptr awalTamu, akhirTamu, awalAntrian, akhirAntrian;

typeWarna lusinAtas, lusinBawah,sortAtas, sortBawah;

int tamu = 0;
int antri = 0;
int souvenir = 0;
int dalamRuangan = 5;

void create(){
    awalTamu = new Tamu;
    akhirTamu = new Tamu;
    awalAntrian = new Tamu;
    akhirAntrian = new Tamu;
    lusinAtas = new barangSouvenir;
    lusinBawah = new barangSouvenir;
    sortAtas = new barangSouvenir;
    sortBawah = new barangSouvenir;
    awalTamu = NULL;
    akhirTamu = NULL;
    awalAntrian = NULL;
    akhirAntrian = NULL;
    lusinAtas = NULL;
    lusinBawah = NULL;
    sortAtas = NULL;
    sortBawah = NULL;
}
int menu();
void lihatAntrian();
void create();
void tamuKeluar();
void antrian(string,int,string);
void tamuRuangan();
void souvenirMeja();
void pushSouvenir();
void inputTamu();
void lihatSouvenir();

int main(int argc, char const *argv[])
{
    bool ulang = true;

    enum{INPUT = 1, TAMU,ANTRIAN,TAMU_KELUAR,SOUVENIR};
    create();
    lihatSouvenir();
    souvenirMeja();
    while(ulang){
        char pil;
        int no = menu();
        switch(no){
            case INPUT:
                inputTamu();
            break;
            case TAMU:
                tamuRuangan();
            break;
            case ANTRIAN: 
                lihatAntrian();
            break;
            case TAMU_KELUAR:
                tamuKeluar();
            break;
            case SOUVENIR:
                pushSouvenir();
            break;
            case 0:
                ulang = false;
            break;
            default:
            cout << "Pilih Angka sesuai pilihan\n";
        }
    }
    
    return 0;
}

int menu(){
    int no;
    cout << "\n" <<  string(30,'=') << endl;
    cout << "Sisa orang yang boleh masuk : " << dalamRuangan << endl;
    cout << "Tumpukan Souvenir : " << souvenir << endl;
    cout << string(30,'=') << endl << endl;
    cout << "==== Menu ====\n";
    cout << "1. Masuk\n";
    cout << "2. Tamu yang Masuk\n";
    cout << "3. Antrian\n";
    cout << "4. Tamu keluar\n";
    cout << "5. Souvenir\n";
    cout << "0. Exit\n";
    cout << "Pilih : "; cin >> no;

    return no;
}
void inputTamu(){
    if(souvenir != 0){
        string nama;
        int anggota;
        cout << "\nNama Yang diundang : "; cin.ignore(); getline(cin,nama);
        cout << "Jumlah orang yang datang : "; cin >> anggota;

        if(anggota <= 2){
            typeptr node;
            typeWarna temp;
            temp = new barangSouvenir;
            temp = sortAtas;
            node = new Tamu;
            node -> nama = nama;
            node -> anggota = anggota;
            node -> warna = temp->warna;

            if(anggota <= dalamRuangan){
                typeWarna hapusSouvenir;
                hapusSouvenir = new barangSouvenir;
                hapusSouvenir = sortAtas;
                sortAtas = hapusSouvenir -> next;
                if(awalTamu == NULL){
                    awalTamu = node;
                    akhirTamu = node;
                    akhirTamu -> next = NULL;
                }else{
                    akhirTamu->next = node;
                    akhirTamu = node;
                    akhirTamu->next = NULL;
                }
                free(hapusSouvenir);
                dalamRuangan -= anggota;
                souvenir--;
            }else{
                antrian(nama,anggota,node -> warna);
                cout << "Harap bersabar, silahkan mengantri terlebih dahulu\n";
            }
        }else{
            cout << "Jumlah anggota tidak boleh melebihi 2 orang\n";
        }
        if(souvenir == 0){
            sortAtas = new barangSouvenir;
            sortAtas = NULL;
            sortBawah = new barangSouvenir; 
            sortBawah = NULL;
        }
    }else{
        cout << "Souvenir Habis, Push Terlebih Dahulu\n";
    }
}

void tamuKeluar(){
    typeptr hapus;
    hapus = new Tamu;
    hapus = awalTamu;
    awalTamu = hapus -> next;
    free(hapus);
    if(antri > 0){
        typeptr node;
        hapus = new Tamu;
        node = new Tamu;
        node->nama = awalAntrian -> nama;
        node -> anggota = awalAntrian -> anggota;
        node -> warna = awalAntrian -> warna;
        hapus = awalAntrian;
        if(antri != 1){ 
            awalAntrian = hapus -> next;
        }
        cout << "Tamu atas nama " << node -> nama << " dipersilahkan masuk\n";
        node -> next = awalTamu;
        awalTamu = node;
        free(hapus);
        antri--;
        if(antri == 0){
            awalAntrian = new Tamu;
            awalAntrian = NULL;
        }
    }else{
        cout << "Belum ada yang mengantri\n";
        dalamRuangan++;
    }
}
void tamuRuangan(){
    typeptr temp;
    temp = awalTamu;
    while(temp != NULL){
        cout << "Nama Undangan : " << temp -> nama << endl;
        cout << "Jumlah Anggota : " << temp -> anggota << endl;
        cout << "Warna Souvenir : " <<  temp -> warna << endl;
        temp = temp ->next;
    }
}

void antrian(string nama, int anggota, string warna){
    typeptr node;
    node = new Tamu;
    node -> nama = nama;
    node -> anggota = anggota;
    node -> warna = warna;
    if(awalAntrian == NULL){
        awalAntrian = node;
        akhirAntrian = node;
        akhirAntrian->next = NULL;
    }else{
        akhirAntrian->next = node;
        akhirAntrian = node;
        akhirAntrian->next = NULL;
    }
    souvenir--;
    antri++;
}
void lihatAntrian(){
    typeptr temp;
    temp = awalAntrian;
    while(temp != NULL){
        cout << "Nama Undangan : " << temp -> nama << endl;
        cout << "Jumlah Anggota : " << temp -> anggota << endl;
        cout << "Warna Souvenir : " <<  temp -> warna << endl << endl;
        temp = temp ->next;
    }
}

void souvenirMeja(){
    int i = 0;
    typeWarna temp;
    temp = new barangSouvenir;
    temp = lusinAtas;
    while(i < 3 && temp != NULL){
        typeWarna node;
        node = new barangSouvenir;
        node -> warna = temp ->warna;
        if(sortAtas == NULL){
            sortAtas = node;
            sortBawah = node;
            sortBawah -> next = NULL;
        }else{
            node->next = sortAtas; 
            sortAtas = node;
        }
        temp = temp -> next;
        i++;
        souvenir++;
    }
}
void pushSouvenir(){
    typeWarna node,temp,bantu;
    int no;
    bantu = sortAtas;
    cout << endl;
    if(bantu != NULL){
        while(bantu != NULL){
            cout << bantu -> warna << endl;
            bantu = bantu -> next;
        }
    }
    cout << "\n====\n";
    cout << "1. Push\n";
    cout << "0. Kembali\n"; 
    cout << "Pilih : "; cin >> no;
    if(no == 1){
        temp = new barangSouvenir;
        temp = lusinAtas;
        lusinAtas = temp -> next;
        node = new barangSouvenir;
        if(souvenir < 3){
            node -> warna = temp ->warna;
            if(sortAtas == NULL){
                sortAtas = node;
                sortBawah = node;
                sortBawah -> next = NULL;
            }else{
                node->next = sortAtas; 
                sortAtas = node;
            }
            souvenir++;
        }else{
            cout << "\nTumpukan souvenir sudah maksimal\n";
        }
    }
}

void lihatSouvenir(){
    string warna[3] = {"Hijau","Kuning","Merah"};
    int i = 0;
    while(i < 12){
        typeWarna node;
        node = new barangSouvenir;
        node->warna = warna[i%3];
        if(lusinAtas == NULL){
            lusinAtas = node;
            lusinBawah = node;
            lusinBawah->next = NULL;
        }else{
            lusinBawah->next = node;
            lusinBawah = node;
            lusinBawah->next = NULL;
        }
        i++;
    }
}