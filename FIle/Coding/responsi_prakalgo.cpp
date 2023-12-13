#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct kegiatan{
	string namaKegiatan[30];
	int tanggal[30];
	int bulan[30];
	int tahun[30];
};

int MainMenu();
void InputFile();
int ReadData(kegiatan &k,string namaFile);
void OutputFile();
	void Sorting(kegiatan &k,int sumData);
		void Swap(int *a, int *b);
		void Swap(string *a, string *b);
	void OutputData(kegiatan &k, int sumData);
void Searching();
	void OutputSubData(kegiatan &k, int sama[],int n);

/*============= MAIN CODE =============*/
int main(int argc, char const *argv[])
{
	int pilihan = MainMenu();
	char loop;

	enum opsi{INPUT = 1, OUTPUT,SEARCH,FINISH};

	while(pilihan != FINISH){
		switch(pilihan){
			case INPUT:
			InputFile();
			break;
			case OUTPUT:
			OutputFile();
			break;
			case SEARCH:
			Searching();
			break;
		}
		ulang:
		cout << "\n\nKembali ke Menu Utama? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : ";cin >> loop;
		if(loop == 'y' | loop == 'Y'){
			system("cls");
			pilihan = MainMenu();
		}else if(loop == 'n' | loop == 'N'){
			cout << "\n\n\t===== TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI =====\n\n";
			system("pause");
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang;
		}
	}
	return 0;
}
/*============= AKHIR MAIN CODE =============*/

/*============= MAIN MENU =============*/
int MainMenu(){
	int pilih;
	cout << string(30,'=') << endl;
	cout << "\tTO DO LIST\n";
	cout << string(30,'=') << endl;
	cout << "1. Input Kegiatan\n";
	cout << "2. Output Kegiatan\n";
	cout << "3. Searching Kegiatan\n";
	cout << "4. Keluar\n";
	cout << string(30,'=') << endl;
	cout << "Pilih : "; cin >> pilih;
	if(pilih > 4){
		cout << "Keyword Anda SALAH, Silahkan Input Lagi..\n";
		system("pause");
		system("cls");
		MainMenu();
	}
	system("cls");
	return pilih;
}
/*============= AKHIR MAIN MENU =============*/

/*============= INPUT FILE =============*/
void InputFile(){
	char loop;
	cout << string(30,'=') << endl;
	cout << "INPUT KEGIATAN\n";
	cout << string(30,'=') << endl;
	kegiatan k;
	string namaFile;
	int jml;
	string f = ".txt";
	cout <<"Input nama File: "; cin >> namaFile;
	system("cls");
	namaFile += f;
	ofstream myFile;
	myFile.open(namaFile, ios::app);
	cout << string(30,'=') << endl;
	cout << "INPUT KEGIATAN\n";
	cout << string(30,'=') << endl;
	cout << "\nMasukkan Banyak Kegiatan : "; cin >> jml;cin.ignore();
	for(int i = 0; i < jml; i++){
		cout << "\tKegiatan ke-" << i + 1 << endl;
		cout << "\t\tNama Kegiatan : ";getline(cin,k.namaKegiatan[i]);myFile << k.namaKegiatan[i] << endl ;
		cout << "\t\tTanggal       : ";	cin >> k.tanggal[i];myFile << k.tanggal[i] << endl;
		cout << "\t\tBulan         : "; cin >> k.bulan[i];myFile << k.bulan[i] << endl;
		cout << "\t\tTahun         : "; cin >> k.tahun[i];cin.ignore();myFile << k.tahun[i] << endl;
		cout << endl;
	}
	ulang_opsi:
	cout << "\n\nInput Kegiatan Lagi? \n";
	cout << "Y -> Iya\n";
	cout << "N -> Tidak\n";
	cout << "Pilih : " ; cin >> loop;
	if(loop == 'y' | loop == 'Y'){
		InputFile();
		system("cls");
	}else if(loop == 'n' | loop == 'N'){
		cout << endl;
	}else{
		cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
		goto ulang_opsi;
	}
}

/*============= AKHIR INPUT FILE =============*/

/*============= SORTING FILE =============*/
int ReadData(kegiatan &k,string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,k.namaKegiatan[sumData])){
			myFile >> k.tanggal[sumData];
			myFile >> k.bulan[sumData];
			myFile >> k.tahun[sumData];
			myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			sumData++;
		}
		cout<< "Data Berhasil Dibaca...\n";
	system("pause");
	system("cls");
		return sumData; 
	}else{
		cout << "Nama File tidak ditemukan!" << endl;
		system("pause");
		system("cls");
		return -1;
	}
}
void Swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Swap(string *a, string *b){
	string temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Sorting(kegiatan &k,int sumData){
	int gap = sumData;
	int arr[sumData];
	// Urut berdasarkan Tahun

	// shell sort Tahun
	for(int gap = sumData/2; gap > 0; gap/=2){
		for(int i = gap; i < sumData; i++){
			int j; 
			for(j = i; j >= gap && k.tahun[j - gap] < k.tahun[j]; j -= gap){
				Swap(&k.namaKegiatan[j],&k.namaKegiatan[j - gap]);
				Swap(&k.tanggal[j],&k.tanggal[j - gap]);
				Swap(&k.bulan[j],&k.bulan[j - gap]);
				Swap(&k.tahun[j],&k.tahun[j - gap]);
			}
		}
	}

	// shell sort bulan 
	for(int gap = sumData/2; gap > 0; gap/=2){
		for(int i = gap; i < sumData; i++){
			int j; 
			for(j = i; j >= gap && k.tanggal[j - gap] < k.tanggal[j] && k.tahun[j] == k.tahun[j - gap]; j -= gap){
				Swap(&k.namaKegiatan[j],&k.namaKegiatan[j - gap]);
				Swap(&k.tanggal[j],&k.tanggal[j - gap]);
				Swap(&k.bulan[j],&k.bulan[j - gap]);
				Swap(&k.tahun[j],&k.tahun[j - gap]);
			}
		}
	}

	// shell sort tanggal
	for(int gap = sumData/2; gap > 0; gap/=2){
		for(int i = gap; i < sumData; i++){
			int j; 
			for(j = i; j >= gap && k.tanggal[j - gap] < k.tanggal[j] && k.tahun[j] == k.tahun[j - gap] && k.bulan[j - gap] == k.bulan[j]; j -= gap){
				Swap(&k.namaKegiatan[j],&k.namaKegiatan[j - gap]);
				Swap(&k.tanggal[j],&k.tanggal[j - gap]);
				Swap(&k.bulan[j],&k.bulan[j - gap]);
				Swap(&k.tahun[j],&k.tahun[j - gap]);
			}
		}
	}
}
/*============= AKHIR SORTING FILE =============*/

/*============= OUTPUT FILE =============*/
void OutputData(kegiatan &k, int sumData){
	cout << "\n\n\t" + string(79,'=') << endl;
	cout << "\t" << "|" << setw(6) <<"No" << setw(4) << "|" << setw(25) << "Nama Kegiatan" << setw(20) << "Tanggal" << "-" << "Bulan" << "-" << "Tahun" << setw(11) << "|" << endl;
	for(int i = 0; i < sumData; i++){
		cout << "\t" + string(79,'=') << endl;
		cout << "\t" <<"|" << setw(5)  << i + 1 << setw(5) << "|" << setw(22) << k.namaKegiatan[i] << setw(24) << k.tanggal[i] << "-" << k.bulan[i] << "-" << k.tahun[i] << setw(15) << "|" << endl;
	}
	cout << "\t" + string(79,'=') << endl;
}
void OutputFile(){
	string namaFile;
	kegiatan k;
	int sumData;
	char loop;
	string f = ".txt";
	ulang_inputNama:
	cout << string(30,'=') << endl;
	cout << "OUTPUT DATA KEGIATAN\n";
	cout << string(30,'=') << endl;
	cout <<"\nInput nama File: "; cin >> namaFile;
	namaFile += f;
	sumData = ReadData(k,namaFile);
	if(sumData < 0) goto ulang_inputNama;
	Sorting(k,sumData);
	cout << string(30,'=') << endl;
	cout << "OUTPUT DATA KEGIATAN\n";
	cout << string(30,'=') << endl;
	OutputData(k,sumData);
	ulang_opsi:
	cout << "\n\nTampilkan Kegiatan Lagi? \n";
	cout << "Y -> Iya\n";
	cout << "N -> Tidak\n";
	cout << "Pilih : " ; cin >> loop;
	if(loop == 'y' | loop == 'Y'){
		system("cls");
		OutputFile();
	}else if(loop == 'n' | loop == 'N'){
		cout << endl;
	}else{
		cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
		goto ulang_opsi;
	}
}

/*============= AKHIR OUTPUT FILE =============*/

/*============= SEARCHING FILE =============*/
void OutputSubData(kegiatan &k, int sama[],int n){
	cout << "\n\n\t" + string(79,'=') << endl;
	cout << "\t" << "|" << setw(10) <<"Data ke-" << setw(4) << "|" << setw(25) << "Nama Kegiatan" << setw(20) << "Tanggal" << "-" << "Bulan" << "-" << "Tahun" << setw(7) << "|" << endl;
	int j = 0;
	for(int i = 0; i < n; i++){
		if(sama[i] > 0){
			cout << "\t" + string(79,'=') << endl;
			cout << "\t" <<"|" << setw(7)  << i + 1 << setw(7) << "|" << setw(22) << k.namaKegiatan[i] << setw(24) << k.tanggal[i] << "-" << k.bulan[i] << "-" << k.tahun[i] << setw(11) << "|" << endl;
		}
	}
	cout << "\t" + string(79,'=') << endl;
}
void Searching(){
	kegiatan k;
	string namaFile;
	string f = ".txt";
	ulang_inputNama:
	cout << string(30,'=') << endl;
	cout << "SEARCHING KEGIATAN\n";
	cout << string(30,'=') << endl;
	cout <<"\nInput nama File: "; cin >> namaFile;
	namaFile += f;
	int sumData = ReadData(k,namaFile);
	if(sumData < 0) goto ulang_inputNama;
	int tgl,bln,thn;
	char loop;
	cout << string(30,'=') << endl;
	cout << "SEARCHING KEGIATAN\n";
	cout << string(30,'=') << endl;
	cout << "\nMasukkan Tanggal : "; cin >> tgl;
	cout << "Masukkan Bulan   : "; cin >> bln;
	cout << "Masukkan Tahun   : "; cin >> thn;
	int dataSama[sumData] = {0};
	int i = 0;
	int found = 0;
	while(i < sumData){
		if(k.tanggal[i] == tgl){
			if(k.bulan[i] == bln){
				if(k.tahun[i] == thn){
					dataSama[i]++;
					i++;
					found++;
				}
				else i++;
			}
			else i++;
		}
		else i++;
	}
	if(found > 0){
		OutputSubData(k,dataSama,sumData);
	}else{
		cout << "\n\nTidak Ada Kegiatan yang Anda Lakukan pada Tanggal : " << tgl << "-" << bln << "-" << thn << endl;
	}
	ulang_opsi:
	cout << "\n\nSearching Kegiatan Lagi? \n";
	cout << "Y -> Iya\n";
	cout << "N -> Tidak\n";
	cout << "Pilih : " ; cin >> loop;
	if(loop == 'y' | loop == 'Y'){
		system("cls");
		Searching();
	}else if(loop == 'n' | loop == 'N'){
		cout << endl;
	}else{
		cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
		goto ulang_opsi;
	}
}

/*============= AKHIR SEARCHING FILE =============*/