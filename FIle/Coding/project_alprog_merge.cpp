#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <cstring>
using namespace std;

struct parkir{
	string jam[20];
	string namaKendaraan[20];
	string plat[20];
}dataParkir;
/*====================MAIN MENU====================*/
int MainMenu(){
	int pilih;
	cout << "==========================================\n";
	cout << "DAFTAR KENDARAAN PARKIR DI CAREFOUR\n";
	cout << "==========================================\n";
	cout << "1. INPUT DATA\n";
	cout << "2. OUTPUT DATA \n";
	cout << "3. SORTING DATA \n";
	cout << "4. FIND DATA \n";
	cout << "5. TRANSAKSI DATA \n";
	cout << "6. KELUAR\n";
	cout << "Pilih Nomor : "; cin >> pilih;
	return pilih;
}
/*====================AKHIR MAIN MENU====================*/

/*====================MENULIS FILE====================*/
void WriteFile(){
	parkir p;
	string namaFile,input;
	int jml;
	string f = ".txt";
	cout <<"Input nama File: "; cin >> namaFile;
	namaFile += f;
	ofstream myFile;
	myFile.open(namaFile, ios::trunc);
	cout << "Masukkan Jumlah data yang dimasukkan : "; cin >> jml;cin.ignore();
	for(int i = 0; i < jml; i++){
		cout << "Data ke-" << i + 1 << endl;
		cout << "Masukkan nomor plat kendaraan : ";getline(cin,p.plat[i]);myFile << p.plat[i] << endl ; //input.append(p.plat[i] + " \n"); 
		cout << "Masukkan nama mobil : ";getline(cin,p.namaKendaraan[i]);myFile << p.namaKendaraan[i] << endl;//input.append(p.namaKendaraan[i] + " \n");
		cout << "Masukkan waktu masuk kendaraan : "; cin >> p.jam[i];cin.ignore();myFile << p.jam[i] << endl ;//input.append(p.jam[i] + " \n");
	}
	myFile.close();
}
/*====================AKHIR MENULIS FILE====================*/

/*====================MEMBACA FILE====================*/

string ReadFile(){
	string namaFile;
	int i = 0;
	string f = ".txt";
	cout <<"Input nama File: "; cin >> namaFile;
	namaFile += f;
	string plat,nama,waktuMasuk,object;
	ifstream myFile;
	myFile.open(namaFile);
	cout << "\n\n" + string(90,'=') << endl;
	cout << setw(5) <<"No" << setw(25) << "Nama Kendaraan" << setw(28) << "Plat Kendaraan" << setw(22) << "Waktu Masuk" << endl;
	while(getline(myFile,plat)){
		i++;
		cout << string(90,'=') << endl;
		myFile >> nama;
		myFile >> waktuMasuk;
		cout <<setw(5) << i << setw(22) << nama << setw(28) << plat << setw(22) << waktuMasuk << endl;
		myFile.ignore(numeric_limits<streamsize>::max(),'\n');
		// masalah getline string : https://stackoverflow.com/questions/11039323/use-getline-and-when-read-file-c
	}
	return namaFile;
}
/*====================AKHIR MEMBACA FILE====================*/

/*====================SEARCH====================*/

void OutputSubData(parkir &p, int index){
	cout << "Nama Kendaraan\t: " << p.namaKendaraan[index] << endl;
	cout << "Jam Masuk\t: " << p.jam[index] << endl;
	cout << "Plat Kendaraan\t: " << p.plat[index] << endl;
}
int ReadData(parkir &p,string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,p.plat[sumData])){
			myFile >> p.namaKendaraan[sumData];
			myFile >> p.jam[sumData];
			myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			sumData++;
		}
		cout<< "Data Dibaca\n";
	system("pause");
	system("cls");
	}else{
		cout << "Nama File tidak ditemukan!" << endl;
	}
	return sumData; 
}
int BinarySearch(string arr[],string find,int n){
	int lower = 0;
	int upper = n;
	while(lower <= upper){
		int mid = (lower + upper)/2;
		if(arr[mid] == find)
			return mid;
		else if(find < arr[mid])
			upper = mid - 1;
		else
			lower = upper + 1;
	}
	return -1;
}
void SearchFile(){
	int pil,sumData,index;
	parkir dataParkir;
	string namaFile,name;
	string arrBinary[20];
	string f = ".txt";
	cout << "==========================================\n";
	cout << "CARI DATA KENDARAAN PARKIR\n";
	cout << "==========================================\n";
	cout << "Masukkan Nama File : ";cin >> namaFile;
	namaFile += f;
	sumData = ReadData(dataParkir,namaFile);
	system("cls");
	// enum pilihan
	cout << "==========================================\n";
	cout << "CARI DATA KENDARAAN PARKIR\n";
	cout << "==========================================\n";
	cout << "1. Sequential Search\n";
	cout << "2. Binary Search\n";
	cout << "Pilih : ";cin >> pil;
	int opsi = 1;
	switch(pil){
		while(opsi != 0){
			cout << "Cari Berdasarkan: \n";
			cout << "1. Nama Kendaraan\n";
			cout << "2. Jam Masuk\n";
			cout << "3. Plat Kendaraan\n";
			cout << "Pilih: "; cin >> opsi;
			case 1:
			if(opsi == 1){
				cout << "Masukkan Nama Kendaraan yang Dicari : ";cin >> name;
				bool find = false;
				int i = 0;
				while(!find){
					if(dataParkir.namaKendaraan[i] == name)
						find = true;
					else
						i++;
				} 
				if(find){
					OutputSubData(dataParkir,i);
				}else{
					cout << "Nama Kendaraan Tidak Ditemukan\n";
				}
			}else if(opsi == 2){
				cout << "Masukkan Jam Masuk Kendaraan yang Dicari : ";cin >> name;
				bool find = false;
				int i = 0;
				while(!find){
					if(dataParkir.namaKendaraan[i] == name)
						find = true;
					else
						i++;
				} 
				if(find){
					OutputSubData(dataParkir,i);
				}else{
					cout << "Tidak Ada Kendaraan yang Masuk Pada Jam " << name << endl;
				}
			}else if(opsi == 3){
				cout << "Masukkan Plat Kendaraan yang Dicari : ";cin >> name;
				bool find = false;
				int i = 0;
				while(!find){
					if(dataParkir.plat[i] == name)
						find = true;
					else
						i++;
				}
				if(find){
					OutputSubData(dataParkir,i);
				}else{
					cout << "Plat Kendaraan Kendaraan Tidak Ditemukan\n"; 
				}
			}
			break;
			case 2:
			for(int i = 0; i < sumData;i++){
				arrBinary[i] = dataParkir.namaKendaraan[i];
			}
			cout << "Masukkan Nama Kendaraan yang Dicari : ";cin >> name;
			index = BinarySearch(arrBinary,name,sumData);
			if(index == -1)
				cout << "Data Tidak Ditemukan\n";
			else
				OutputSubData(dataParkir,index);
			break;
		}
	}
}
/*====================AKHIR SEARCH====================*/

/*====================SORT====================*/

void OutputData(parkir &p, int sumData){
	cout << "\n\n" + string(90,'=') << endl;
	cout << setw(5) <<"No" << setw(25) << "Nama Kendaraan" << setw(28) << "Plat Kendaraan" << setw(22) << "Waktu Masuk" << endl;
	for(int i = 0; i < sumData; i++){
		cout << string(90,'=') << endl;
		cout <<setw(5) << i + 1 << setw(22) << p.namaKendaraan[i] << setw(28) << p.plat[i] << setw(22) << p.jam[i] << endl;
	}
}

void Swap(string *a, string *b){
 	string temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*			BUBBLE SORT 		*/
void BubbleSort(parkir &p, string arr[], int sumData){
	int l1,l2;
	cout << "\nSebelum Sort : ";
	for(int i = 0; i < sumData; i++){
		cout << arr[i] << " ";
	}
	for(int i = 0; i < sumData - 1; i++){
		for(int j = 0; j < sumData - i - 1;j++){
			l1 = arr[j].length();
			l2 = arr[j+1].length();
			char char_array1[l1 + 1];
			char char_array2[l2 + 1];
			strcpy(char_array1, arr[j].c_str());
			strcpy(char_array2, arr[j + 1].c_str());
			if(char_array1[0] > char_array2[0]){
				Swap(&arr[j],&arr[j+1]);
			 	Swap(&p.namaKendaraan[j],&p.namaKendaraan[j+1]);
				Swap(&p.plat[j], &p.plat[j+1]);
				Swap(&p.jam[j], &p.jam[j+1]);
			}
			else if(char_array1[0] == char_array2[0]){
				bool same = false;
				int index = 0;
				int  a,b;
				while(!same){
					++index;
					a = char_array1[index];
					b = char_array2[index];
					if(a == b){
						continue;
					}else if(a != b){
						if(a > b){
							Swap(&arr[j],&arr[j+1]);
						 	Swap(&p.namaKendaraan[j],&p.namaKendaraan[j+1]);
							Swap(&p.plat[j], &p.plat[j+1]);
							Swap(&p.jam[j], &p.jam[j+1]);
							same = true;
						}else{
							same = true;
						}
					}
				} 
			}
		}
	}
	cout << "\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
}
/*			AKHIR BUBBLE SORT 		*/


/* 			SELECTION SORT 			*/
void SelectionSort(parkir &p, string arr[], int sumData){
	int indexMin,l1,l2;
	cout << "Sebelum Sort : ";
	for(int i = 0; i < sumData; i++){
		cout << arr[i] << " ";
	}
	for(int i = 0; i < sumData; i++){
		indexMin = i;
		for(int j = i + 1; j < sumData; j++){
			l1 = arr[j].length();
			l2 = arr[j+1].length();
			char char_array1[l1 + 1];
			char char_array2[l2 + 1];
			strcpy(char_array1, arr[indexMin].c_str());
			strcpy(char_array2, arr[j].c_str());
			if(char_array1[0] > char_array2[0]){
				indexMin = j;
			}
			else if(char_array1[0] == char_array2[0]){
				bool same = false;
				int index = 0;
				int  a,b;
				while(!same){
					++index;
					a = char_array1[index];
					b = char_array2[index];
					if(a == b){
						continue;
					}else if(a != b){
						if(a > b){
							indexMin = j;
							same = true;
						}else{
							same = true;
						}
					}
				} 
			}
		}
		Swap(&arr[i],&arr[indexMin]);
		Swap(&p.namaKendaraan[i],&p.namaKendaraan[indexMin]);
		Swap(&p.plat[i], &p.plat[indexMin]);
		Swap(&p.jam[i], &p.jam[indexMin]);
	}
	cout << "\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
	OutputData(p,sumData);
}
/* 			AKHIR SELECTION SORT 			*/

/* 			INSERTION SORT 			*/
/*void InsertSort(p,arr,sumData){
	for(int j = 0; j < size; j++){
		int index1 = 0,index2 = 0;
		l1 = arr[j].length();
		l2 = arr[j+1].length();
		char char_array1[l1 + 1];
		char char_array2[l2 + 1];
		strcpy(char_array1, arr[indexMin].c_str());
		strcpy(char_array2, arr[j].c_str());
		if(char_array1[index1] > char_array2[index2]){
			while(arr[j + 1] < arr[j] && j >= 0){
			swap(&arr[j],&arr[j + 1]);
			j--;
		}
		}
		else if(char_array1[0] == char_array2[0]){
			bool same = false;
			int index = 0;
			int  a,b;
			while(!same){
				++index;
				a = char_array1[index];
				b = char_array2[index];
				if(a == b){
					continue;
				}else if(a != b){
					if(a > b){
						indexMin = j;
						same = true;
					}else{
						same = true;
					}
				}
			}
		}
	}
}*/
/* 			AKHIR INSERTION SORT 			*/
void SortFile(){
	int pil;
	char pilih = 'Y',main;
	int pilihSubjek,sumData;
	parkir p;
	string arr[20];
	string namaFile,f;
	f = ".txt";
	cout << "Masukkan Nama File : ";cin >> namaFile;
	namaFile += f;
	sumData = ReadData(p,namaFile);
	do{
		cout << string(30,'=') << endl;
		cout << "PILIH METODE SORT" << endl;
		cout << string(30,'=') << endl;
		cout << "1. Bubble Sort\n";
		cout << "2. Selection Sort\n";
		cout << "3. Insert Sort\n";
		cout << "4. Shell Sort\n";
		cout << "5. Quick Sort\n";
		cout << "Pilih : ";cin >>pil; 
		enum pilihSort{BUBBLE = 1,SELECTION,INSERT,SHELL,QUICK};
		while(pil <= 5 && (pilih == 'Y' || pilih == 'y')){
			cout << string(30,'=') << endl;
			cout << "Pilih Berdasarkan:\n";
			cout << string(30,'=') << endl;
			cout << "1. Plat Kendaraan\n";
			cout << "2. Nama Kendaraan\n";
			cout << "3. Waktu Masuk\n";
			cout << "Pilih : "; cin >> pilihSubjek;
			if(pilihSubjek == 1){
				for(int i = 0;i < sumData;i++){
					arr[i] = p.plat[i];
				}
			}else if(pilihSubjek == 2){
				for(int i = 0; i < sumData; i++){
					arr[i] = p.namaKendaraan[i];
				}	
			}else if(pilihSubjek == 3){
				for(int i = 0; i < sumData; i++){
					arr[i] = p.jam[i];
				}
			}
			switch(pil){
				case BUBBLE:
				BubbleSort(p,arr,sumData);
				OutputData(p,sumData);
				cout<<endl;
				break;
				case SELECTION:
				SelectionSort(p,arr,sumData);
				break;
				case INSERT:
				// InsertSort(p,arr,sumData);
				break;
				case SHELL:
				// ShellSort(arr,sumData);
				break;
				case QUICK:
				// QuickSort(arr,sumData);
				break;
			}
			cout << "Kembali ke Opsi Urut (Y/N)? "; cin >> pilih;
		}
		cout << "Kembali ke Menu Sort (Y/N)? "; cin >> main; 
	}while(main == 'Y' || main == 'y');
}
/*====================AKHIR SORT====================*/


/*====================TRANSAKSI====================*/
void Merge(string type){
ulang:
if (type == "sambung"){
cout<<"==================\n";
cout<<" MERGING SAMBUNG\n";
cout<<"==================";
}
else{
cout<<"==================\n";
cout<<" MERGING URUT\n";
cout<<"==================";
}
cout<<"\nFile 1 : \n";
string file1 = ReadFile();
cout<<"\nFile 2 : \n";
string file2 = ReadFile();
	string namaFile;
	int i = 0;
	string f = ".txt";
	parkir p;
	ifstream myFile;
	myFile.open(file1);
	while(getline(myFile,p.plat[i])){
		myFile >> p.namaKendaraan[i];
		myFile >> p.jam[i];
		i++;
		myFile.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	myFile.close();
	myFile.open(file2);
	while(getline(myFile,p.plat[i])){
		myFile >> p.namaKendaraan[i];
		myFile >> p.jam[i];
		i++;
		myFile.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	myFile.close();
	if(type == "urut"){
		cout<<"\nMelakukan Proses Bubble Sorting Terlebih Dahulu...\n";
		string arr[20];
		for(int j = 0;j < i;j++){
			arr[j] = p.plat[j];
		}
		BubbleSort(p,arr,i);
	}
	cout<<"\nFile baru : \n";
	cout <<"Input nama File baru: "; cin >> namaFile;
	namaFile += f;
	cout<<"\nFile baru berhasil disimpan, Silahkan lihat data pada Main menu\n";
	
	ofstream inFile;
	inFile.open(namaFile, ios::trunc);
	for(int j=0; j<i; j++){
		inFile << p.plat[j] << endl
		<< p.namaKendaraan[j] << endl
		<< p.jam[j] << endl;
	}
	string loop;
	loop:
	cout << "\n\nUlangi Merge (Y/N)? "; cin >> loop;
	if(loop == "y" || loop == "Y"){
		system("cls");
		goto ulang;
	}else if(loop == "n" || loop == "N"){
	}else{
		cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
		goto loop;
	}
}

void Update(){

}

void Split(){

}

void EditFile(){
string loop;
int pilihan;
ulang:
cout<<"=========================\n";
cout<<" TRANSAKSI\n";
cout<<"=========================\n";
cout<<"1. Merging Sambung\n";
cout<<"2. Merging Urut\n";
cout<<"3. Updating\n";
cout<<"4. Spliting\n";
cout<<"Masukan Pilihan : "; cin>> pilihan;
enum editOption{sambung = 1, urut, update, split};
	switch(pilihan ){
		case sambung:
		Merge("sambung");
		break;
		case urut:
		Merge("urut");
		break;
		case update:
		Update();
		break;
		case split:
		Split();
		break;
	}
	loop:
	cout << "\n\nUlangi Menu Transaksi (Y/N)? "; cin >> loop;
	if(loop == "y" || loop == "Y"){
		system("cls");
		goto ulang;
	}else if(loop == "n" || loop == "N"){
	}else{
		cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
	goto loop;
	}
}


/*====================AKHIR TRANSAKSI====================*/

int main()
{
	int pilihan = MainMenu();
	string loop;

	enum option{WRITE = 1,READ,SORT,FIND,EDIT,FINISH};
	while(pilihan != FINISH){
		switch(pilihan){
			case WRITE:
			WriteFile();
			break;
			case READ:
			ReadFile();
			break;
			case SORT:
			SortFile();
			break;
			case FIND:
			SearchFile();
			break;
			case EDIT:
			EditFile();
			break;
		}
		ulang:
		cout << "\n\nKembali Ke Halaman Utama (Y/N)? "; cin >> loop;
		if(loop == "y" || loop == "Y"){
			system("cls");
			pilihan = MainMenu();
		}else if(loop == "n" || loop == "N"){
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang;
		}
	}
	return 0;
}
