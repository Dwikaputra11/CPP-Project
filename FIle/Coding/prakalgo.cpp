#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <windows.h>
using namespace std;

struct penduduk{
	string golonganDarah[20];
	string status[20];
	string asalDaerah[20];
	string namaPenduduk[20];
	string TTL[20];
}dataPenduduk;

/*====================MAIN MENU====================*/
int MainMenu(){
	int pilih;
	cout << string(42,'=') << endl;
	cout << "DATA PENDUDUK DESA\n";
	cout << "PROVINSI BALI\n";
	cout << string(42,'=') << endl;
	cout << "1. INPUT DATA\n";
	cout << "2. OUTPUT DATA \n";
	cout << "3. SORTING DATA \n";
	cout << "4. FIND DATA \n";
	cout << "5. TRANSAKSI DATA \n";
	cout << "6. KELUAR\n";
	cout << "Pilih Nomor : "; cin >> pilih;
	system("cls");
	return pilih;
}
/*====================AKHIR MAIN MENU====================*/

/*====================MENULIS FILE====================*/
void WriteFile(){
	char loop;
	do{
		cout << string(30,'=') << endl;
		cout << "INPUT DATA PENDUDUK\n";
		cout << string(30,'=') << endl;
		penduduk p;
		string namaFile,input;
		int jml;
		string f = ".txt";
		cout <<"Masukkan Nama Desa : "; cin >> namaFile;
		namaFile += f;
		ofstream myFile;
		myFile.open(namaFile, ios::app);
		cout << "Masukkan Jumlah Data Penduduk yang Dimasukkan : "; cin >> jml;cin.ignore();
		system("cls");
		cout << string(30,'=') << endl;
		cout << "INPUT DATA PARKIR\n";
		cout << string(30,'=') << endl;
		for(int i = 0; i < jml; i++){
			cout << "Data ke-" << i + 1 << endl;
			cout << "Masukkan Nama Penduduk : ";getline(cin,p.namaPenduduk[i]);myFile << p.namaPenduduk[i] << endl ;
			cout << "Masukkan Asal Daerah : ";getline(cin,p.asalDaerah[i]);myFile << p.asalDaerah[i] << endl ;
			cout << "Masukkan Tanggal Lahir : ";getline(cin,p.TTL[i]);myFile << p.TTL[i] << endl;
			cout << "Masukkan Status Kawin : "; getline(cin,p.status[i]);myFile << p.status[i] << endl ;
			cout << "Masukkan Golongan Darah : "; cin >> p.golonganDarah[i];myFile << p.golonganDarah[i] << endl ;cin.ignore();
		}
		ulang_opsi:
		cout << "\n\nInput Data Lagi? \n";
		cout << "Y -> Iya\n";
		cout << "N -> Tidak\n";
		cout << "Pilih : " ; cin >> loop;
		if(loop == 'y' | loop == 'Y'){
			system("cls");
		}else if(loop == 'n' | loop == 'N'){
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang_opsi;
		}
		myFile.close();
	}while(loop == 'y' | loop == 'Y');
}
/*====================AKHIR MENULIS FILE====================*/

/*====================MEMBACA FILE====================*/

string ReadFile(){
	string namaFile;
	int i = 0;
	string f = ".txt";
	cout <<"Masukkan Nama Desa : "; cin >> namaFile;
	namaFile += f;
	string nama,tglLahir,golDarah,status,asal;
	ifstream myFile;
	myFile.open(namaFile);
	cout << "\n\n" + string(126,'=') << endl;
	cout << setw(5) <<"No" << setw(25) << "Nama Penduduk" << setw(20) <<"Asal Daerah" << setw(25) << "TTL" << setw(28) << "Golongan Darah" << setw(18) <<"Status" << endl;
	while(getline(myFile,nama)){
		i++;
		cout << string(126,'=') << endl;
		getline(myFile,asal);
		getline(myFile,tglLahir);
		getline(myFile,status);
		myFile >> golDarah;
		cout <<setw(5) << i << setw(25) << nama << setw(20) << asal << setw(30) << tglLahir << setw(18) << golDarah << setw(25) << status << endl;
		myFile.ignore(numeric_limits<streamsize>::max(),'\n');
		// masalah getline string : https://stackoverflow.com/questions/11039323/use-getline-and-when-read-file-c
	}
	return namaFile;
}
int ReadData(penduduk &p,string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,p.namaPenduduk[sumData])){
			getline(myFile,p.asalDaerah[sumData]);
			getline(myFile,p.TTL[sumData]);
			getline(myFile,p.status[sumData]);
			myFile >> p.golonganDarah[sumData];
			myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			sumData++;
		}
		cout<< "Data Berhasil Dibaca...\n";
	system("pause");
	system("cls");
	}else{
		cout << "Nama File tidak ditemukan!" << endl;
	}
	return sumData; 
}
/*====================AKHIR MEMBACA FILE====================*/

/*====================MAIN CODING====================*/
int main()
{
	int pilihan = MainMenu();
	string loop;
	char ulang;

	enum option{WRITE = 1,READ,SORT,FIND,EDIT,FINISH};
	while(pilihan != FINISH){
		switch(pilihan){
			case WRITE:
			WriteFile();
			break;
			case READ:
			do{
				cout << string(30,'=') << endl;
				cout << "OUTPUT FILE DATA PARKIR\n";
				cout << string(30,'=') << endl; 
				ReadFile();
				ulang_opsi:
				cout << "\n\nUlangi Output File? \n";
				cout << "Y -> Kembali\n";
				cout << "N -> Keluar\n";
				cout << "Pilih : ";cin >> ulang;
				if(ulang == 'y' | ulang == 'Y'){
					system("cls");
				}else if(ulang == 'n' | ulang == 'N'){
					break;
				}else{
					cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
					goto ulang_opsi;
				}
			}while(ulang == 'y' | ulang == 'Y');	
			break;
			case SORT:
			// SortFile();
			break;
			case FIND:
			// SearchFile();
			break;
			case EDIT:
			// EditFile();
			break;
		}
		ulang:
		cout << "\n\nKembali ke Menu Utama? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : ";cin >> loop;
		if(loop == "y" | loop == "Y"){
			system("cls");
			pilihan = MainMenu();
		}else if(loop == "n" | loop == "N"){
			cout << "\n\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI!\n\n";
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang;
		}
	}
	return 0;
}
/*====================AKHIR MAIN CODING====================*/