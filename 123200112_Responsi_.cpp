#include <iostream>

using namespace std;
typedef struct Undangan *ptr;
struct Undangan{
    string nama;
    int anggota;
    string warna;
    ptr next;
};
typedef struct barangSouvenir *nodeWarna;
struct barangSouvenir{
    string warna;
    nodeWarna next;
};

ptr awalTamu, akhirTamu, awalAntrian, akhirAntrian;

nodeWarna lusinAtas, lusinBawah,sortAtas, sortBawah;

int tamu = 0;
int antri = 0;
int souvenir = 0;
int dalamRuangan = 5;

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

    create();
    lihatSouvenir();
    souvenirMeja();
    while(ulang){
        char pil;
        int no = menu();
        switch(no){
            case 1:
                inputTamu();
            break;
            case 2:
                tamuRuangan();
            break;
            case 3: 
                lihatAntrian();
            break;
            case 4:
                tamuKeluar();
            break;
            case 5:
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
    cout << "Menu :\n";
    cout << "1. Masuk\n";
    cout << "2. Tamu yang Masuk\n";
    cout << "3. Antrian\n";
    cout << "4. Tamu keluar\n";
    cout << "5. Souvenir\n";
    cout << "0. Exit\n";
    cout << "Pilih : "; cin >> no;

    return no;
}

void create(){
    awalTamu = new Undangan;
    akhirTamu = new Undangan;
    awalAntrian = new Undangan;
    akhirAntrian = new Undangan;
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
void inputTamu(){
    if(souvenir != 0){
        string nama;
        int anggota;
        cout << "Nama Yang diundang : "; cin.ignore(); getline(cin,nama);
        cout << "Jumlah orang yang datang : "; cin >> anggota;

        if(anggota <= 2){
             ptr node;
            nodeWarna temp;
            temp = new barangSouvenir;
            temp = sortAtas;
            node = new Undangan;
            node -> nama = nama;
            node -> anggota = anggota;
            node -> warna = temp->warna;

            if(anggota <= dalamRuangan){
                nodeWarna hapusSouvenir;
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
    }else{
        cout << "Souvenir Habis, Push Terlebih Dahulu\n";
    }
}

void tamuKeluar(){
    ptr hapus;
    hapus = new Undangan;
    hapus = awalTamu;
    awalTamu = hapus -> next;
    free(hapus);
    if(antri > 0){
        ptr node;
        hapus = new Undangan;
        node = new Undangan;
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
            awalAntrian = new Undangan;
            awalAntrian = NULL;
        }
    }else{
        cout << "Belum ada yang mengantri\n";
        dalamRuangan++;
    }
}
void tamuRuangan(){
    ptr temp;
    temp = awalTamu;
    while(temp != NULL){
        cout << "Nama Undangan : " << temp -> nama << endl;
        cout << "Jumlah Anggota : " << temp -> anggota << endl;
        cout << "Warna Souvenir : " <<  temp -> warna << endl;
        temp = temp ->next;
    }
}

void antrian(string nama, int anggota, string warna){
    ptr node;
    node = new Undangan;
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
    ptr temp;
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
    nodeWarna temp;
    temp = new barangSouvenir;
    temp = lusinAtas;
    while(i < 3 && temp != NULL){
        nodeWarna node;
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
    nodeWarna node,temp,bantu;
    int no;
    bantu = sortAtas;
    cout << endl;
    while(bantu != NULL){
        cout << bantu -> warna << endl;
        bantu = bantu -> next;
    }
    cout << "====\n";
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
            cout << "\numpukan Souvenir pada batas maksimal\n";
        }
    }
}

void lihatSouvenir(){
    string warna[3] = {"Hijau","Kuning","Merah"};
    int i = 0;
    while(i < 12){
        nodeWarna node;
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