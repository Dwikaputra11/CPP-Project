#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>

using namespace std;

char namafile[30];
int banyak,pilih;
char cari[30];
struct data {
	int nonpwp[999];
	string nama[999];
	string alamat[999];
	string jk[999];
	int penghasilan[999];
	string cabang[999];
}npwp;



void inputdata();
void outputdata();
void seqSearch(data &d,int n);
void searchdata();
void sorting();

int main () {
    int pil;

    cout<<"========================="<<endl;
    cout<<" TUGAS PROJECT ALGO 2021 "<<endl;
    cout<<"========================="<<endl;
    cout<<"        1. INPUT DATA"<<endl;
    cout<<"        2. TAMPILKAN DATA"<<endl;
    cout<<"        3. SEARCHING DATA"<<endl;
    cout<<"        4. SORTING DATA"<<endl;
    cout<<"        5. TRANSAKSI"<<endl;
    cout<<"        6. KELUAR"<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"Masukkan Pilihan        = :"; cin>>pil;
	switch(pil){
        case 1 :
            inputdata();
        break;
        case 2 :
            outputdata();
        break;
        case 3 :
            searchdata();
        break;
        case 4 :

        break;
        case 5 :

        break;
        case 6 :
            exit;
        break;
	}
system("pause");
return 0;
}

void inputdata() {
    cout << "Masukkan Nama File : "; cin >>namafile;
    cout <<endl;
    ofstream datanpwp(namafile, ios::out);
    if (datanpwp.is_open())
    {
        cout << "Masukkan Banyak Data Yang Akan Diinputkan : "; cin >> banyak;
        cout <<endl;
        for (int i = 0; i < banyak; i++){
            cout << "Nomor NPWP\t: "; cin >> npwp.nonpwp[i]; cin.ignore();
            cout << "Nama\t\t: "; getline(cin,npwp.nama[i]);
            cout << "Jenis Kelamin\t: "; getline(cin,npwp.jk[i]);
            cout << "Alamat\t\t: "; getline(cin,npwp.alamat[i]);
            cout << "Penghasilan\t: "; cin >> npwp.penghasilan[i];
            cout << "Cabang\t\t: "; cin >> npwp.cabang[i];
            datanpwp << npwp.nonpwp[i] << "\n" << npwp.nama[i] << "\n" << npwp.jk[i] << "\n" << npwp.alamat[i] << "\n" << npwp.penghasilan[i] << "\n"  << npwp.cabang[i] << "\n";
			cout <<endl;
        }
    }
    else {
        cout << "File tidak dapat dibuat " << endl;
    }
    datanpwp.close();

}

void outputdata(){
	int i=0;
    cout << "Masukkan Nama File Yang Akan Digunakan : "; cin >>namafile;

    ifstream datanpwp(namafile);

    if (datanpwp.is_open()){
		cout << "Daftar Data NPWP Yang Tersedia" << endl;
        cout << "=========================================================================================================" << endl;
        cout << "Nomor NPWP" << "\t" << "Nama" << "\t\t" << "Jenis Kelamin" << "\t\t" << "Alamat" << "\t\t" << "Penghasilan" << "\t" << "Cabang" << endl;
        cout << "=========================================================================================================" << endl;
        datanpwp >> npwp.nonpwp[i] >> npwp.nama[i] >> npwp.jk[i] >> npwp.alamat[i] >> npwp.penghasilan[i]  >> npwp.cabang[i];
        while(datanpwp.eof()==0){
            cout << npwp.nonpwp[i] << "\t\t" << npwp.nama[i] << "\t\t" << npwp.jk[i] << "\t\t\t" << npwp.alamat[i] << "\t\t" << npwp.penghasilan[i] << "\t\t" << npwp.cabang[i] << endl;
            datanpwp >> npwp.nonpwp[i] >> npwp.nama[i] >> npwp.jk[i] >> npwp.alamat[i] >> npwp.penghasilan[i]  >> npwp.cabang[i];
        }
    } else{
        cout << "File Tidak ditemukkan";
    }
    datanpwp.close();

}

void seqSearch(data &d,int n){
	cout << "Pencarian Data Dengan Metode Sequential" << endl;
		cout << "1. Nomor NPWP" <<endl;
		cout << "2. Nama" <<endl;
		cout << "3. Cabang" <<endl;
		cout << "Masukkan Pilihan : ";  cin >> pilih;
		if (pilih==1) {
				int carino;
				cout <<"Masukkan Nomor NPWP : "; cin >> carino;
						for(int i=0; i<n; i++){
		                    if (carino == npwp.nonpwp[i]) {
		                        cout << "Data Ditemukan !" <<endl;
								cout << "Nomor NPWP\t: "; cout << npwp.nonpwp[i] << endl;
								cout << "Nama\t\t: "; cout << npwp.nama[i] << endl;
								cout << "Jenis Kelamin\t: "; cout << npwp.jk[i] << endl;
								cout << "Alamat\t\t: "; cout << npwp.alamat[i] << endl;
								cout << "Penghasilan\t: "; cout << npwp.penghasilan[i] << endl;
								cout << "Cabang\t\t: "; cout << npwp.cabang[i] <<  endl << endl;
		                    } else {
		                        cout<<"Data tidak ditemukan"<<endl;
		                    }
						}		
		} else if (pilih==2) {

		} else {
			cout <<endl;
		}
}
void binSearch(data &d,int n){

}
void searchdata() {
	int sumData=0,i = 0, carino,y;
	bool found;
	found=false;
	int x=0,z;
    cout << "Masukkan Nama File Yang Akan Digunakan : "; cin >>namafile;
    int pilih;

    // int readData(data &d,string namafile);
    ifstream datanpwp(namafile);
    while(datanpwp >> npwp.nonpwp[i]){
            datanpwp >> npwp.nama[i] >> npwp.jk[i] >> npwp.alamat[i] >> npwp.penghasilan[i]  >> npwp.cabang[i];
            i++;
            sumData++;
            cout << "dibaca\n";
        }
        // return sumData;
        y = sumData;//readData(data &d,string namafile);
    if (datanpwp.is_open()){
		cout << "Cari Data NPWP" << endl;
        cout << "1. Sequential Search" <<endl;
        cout << "2. Binary Search" <<endl;
        cout << "Masukkan Pilihan : "; cin >> pilih;
        if (pilih==1) {
			seqSearch(npwp,sumData);
		} if (pilih==2) {
			cout << "Pencarian Data Dengan Metode Binary" << endl;
			cout << "1. Nomor NPWP" <<endl;
			cout << "2. Nama" <<endl;
			cout << "3. Cabang" <<endl;
			cout << "Masukkan Pilihan : ";  cin >> pilih;
			if (pilih==1) {
				cout <<"Masukkan Nomor NPWP : "; cin >>carino;
				while ((!found) & (x<=y)) {
					z=(x+y)/2;
					if (carino==npwp.nonpwp[z]) {
						found=true;
					} else {
						if (carino<npwp.nonpwp[z]) {
							y=z-1;
						} else {
						x=z+1;
						}
					}
				}
				if (found) {
					cout << "Data Ditemukan !" <<endl;
					cout << "Nomor NPWP\t: "; cout << npwp.nonpwp[z] << endl;
					cout << "Nama\t\t: "; cout << npwp.nama[z] << endl;
					cout << "Jenis Kelamin\t: "; cout << npwp.jk[z] << endl;
					cout << "Alamat\t\t: "; cout << npwp.alamat[z] << endl;
					cout << "Penghasilan\t: "; cout << npwp.penghasilan[z] << endl;
					cout << "Cabang\t\t: "; cout << npwp.cabang[z] <<  endl << endl;
				} else {
					cout <<"Data Tidak Ditemukan !";
				}

			} else if (pilih==2){

			} else {

			}

		}
	} else{
        cout << "File Tidak ditemukkan";
    }
    datanpwp.close();

}

void sorting(){

}
