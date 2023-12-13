#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <windows.h>
using namespace std;

/*YANG PERLU DIPERBAIKI & DITAMBAH*/
/*

*/

struct penduduk{
	string golonganDarah[20];
	string status[20];
	string namaPenduduk[20];
	string asalDaerah[20];
	string NIK[20];
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
		cout << "INPUT DATA PENDUDUK\n";
		cout << string(30,'=') << endl;  
		for(int i = 0; i < jml; i++){
			cout << "Data ke-" << i + 1 << endl;
			cout << "Masukkan Nama Penduduk  : ";getline(cin,p.namaPenduduk[i]);myFile << p.namaPenduduk[i] << endl;
			cout << "Masukkan Asal Daerah    : ";getline(cin,p.asalDaerah[i]);myFile << p.asalDaerah[i] << endl;
			cout << "Masukkan NIK            : ";getline(cin,p.NIK[i]);myFile << p.NIK[i] << endl;
			cout << "Masukkan Status Kawin 	 : ";getline(cin,p.status[i]);myFile << p.status[i] << endl;
			cout << "Masukkan Golongan Darah : ";cin >> p.golonganDarah[i];myFile << p.golonganDarah[i] << endl ;cin.ignore();
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
	string nama,nik,golDarah,status,asal;
	ifstream myFile;
	myFile.open(namaFile);
	cout << "\n\n\t" + string(126,'=') << endl;
	cout << "\t" << "|" << setw(4) <<"No" << setw(25) << "Nama Penduduk" << setw(20) <<"Asal Daerah" << setw(14) << "NIK" << setw(28) << "Golongan Darah" << setw(18) <<"Status" << setw(16) << "|" << endl;
	while(getline(myFile,nama)){
		i++;
		cout << "\t" + string(126,'=') << endl;
		getline(myFile,asal);
		getline(myFile,nik);
		getline(myFile,status);
		myFile >> golDarah;
		cout << "\t" << "|" << setw(4) << i << setw(25) << nama << setw(18) << asal << setw(19) << nik << setw(18) << golDarah << setw(25) <<  status << setw(16) << "|" << endl;
		myFile.ignore(numeric_limits<streamsize>::max(),'\n');
		// masalah getline string : https://stackoverflow.com/questions/11039323/use-getline-and-when-read-file-c
	}
	cout << "\t" + string(126,'=') << endl;
	return namaFile;
}
int ReadData(penduduk &p,string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,p.namaPenduduk[sumData])){
			getline(myFile,p.asalDaerah[sumData]);
			getline(myFile,p.NIK[sumData]);
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

/*========================SORT========================*/

void OutputData(penduduk &p, int sumData){
	cout << "\n\n\t" + string(126,'=') << endl;
	cout << "\t" << "|" << setw(4) <<"No" << setw(25) << "Nama Penduduk" << setw(20) <<"Asal Daerah" << setw(14) << "NIK" << setw(28) << "Golongan Darah" << setw(18) <<"Status" << setw(16) << "|" << endl;
	for(int i = 0; i < sumData; i++){
		cout << "\t" + string(126,'=') << endl;
		cout << "\t" << "|" << setw(4) << i + 1 << setw(25) << p.namaPenduduk[i] << setw(18) << p.asalDaerah[i] << setw(19) << p.NIK[i] << setw(18) << p.golonganDarah[i] << setw(25) << p.status[i] << setw(16) << "|" << endl;
	}
	cout << "\t" + string(126,'=') << endl;
}

void Swap(string *a, string *b){
 	string temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*			BUBBLE SORT 		*/
void BubbleSort(penduduk &p, string arr[], int sumData){
	int l1,l2;
	cout << "\n\nSebelum Sort : ";
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
				Swap(&p.namaPenduduk[j],&p.namaPenduduk[j+1]);
				Swap(&p.asalDaerah[j],&p.asalDaerah[j+1]);
				Swap(&p.status[j], &p.status[j+1]);
				Swap(&p.NIK[j], &p.NIK[j+1]);
				Swap(&p.golonganDarah[j], &p.golonganDarah[j+1]);
				/*cout << "Proses Sort : "
				for(int k = 0; k < sumData; k++){
					cout << arr[i] << " ";
				}
				cout << endl;*/
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
						 	Swap(&p.namaPenduduk[j],&p.namaPenduduk[j+1]);
						 	Swap(&p.asalDaerah[j],&p.asalDaerah[j+1]);
							Swap(&p.status[j], &p.status[j+1]);
							Swap(&p.NIK[j], &p.NIK[j+1]);
							Swap(&p.golonganDarah[j], &p.golonganDarah[j+1]);
							same = true;
							/*cout << "Proses Sort : ";
							for(int k = 0; k < sumData; k++){
								cout << arr[i] << " ";
							}
							cout << endl;*/
						}else{
							same = true;
						}
					}
				} 
			}
		}
	}
	cout << "\n\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/*			AKHIR BUBBLE SORT 		*/


/* 			SELECTION SORT 			*/
void SelectionSort(penduduk &p, string arr[], int sumData){
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
		Swap(&p.namaPenduduk[i],&p.namaPenduduk[indexMin]);
		Swap(&p.asalDaerah[i],&p.asalDaerah[indexMin]);
		Swap(&p.status[i], &p.status[indexMin]);
		Swap(&p.NIK[i], &p.NIK[indexMin]);
		Swap(&p.golonganDarah[i], &p.golonganDarah[indexMin]);
	}
	cout << "\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/* 			AKHIR SELECTION SORT 			*/

/* 			INSERTION SORT 			*/ 
void InsertSort(penduduk &p,string arr[],int sumData){
	int l1,l2;
	bool same;
	int i;
	cout << "\n\nSebelum Sort : ";
	for(int k = 0; k < sumData; k++){
		cout << arr[k] << " ";
	}
	cout << endl;
	for(int j = 0; j < sumData; j++){
		// cout << "\nj ke-" << j << endl;
		for(int i = j;(i >= 0) && ((j + 1) < sumData);i--){
			l1 = arr[i].length();
			l2 = arr[i+1].length();
			char char_array1[l1 + 1];
			char char_array2[l2 + 1];
			strcpy(char_array1, arr[i].c_str());
			strcpy(char_array2, arr[i+1].c_str());
			int str1, str2;
			str1 = char_array1[0];
			str2 = char_array2[0];
			// cout << "\ni sebelum : " << i << endl;
			if(str2 < str1){
				// cout << "\nyang di swap  lebih besar: " << arr[i] << " & " << arr[i + 1] << endl;
				Swap(&arr[i],&arr[i + 1]);
				Swap(&p.namaPenduduk[i],&p.namaPenduduk[i + 1]);
				Swap(&p.asalDaerah[i],&p.asalDaerah[i+1]);
				Swap(&p.status[i], &p.status[i + 1]);
				Swap(&p.NIK[i], &p.NIK[i + 1]);
				Swap(&p.golonganDarah[i], &p.golonganDarah[i + 1]);
				cout << "Proses Sort : ";
				for(int k = 0; k < sumData; k++){
					cout << arr[k] << " ";
				}
				cout << endl;
			}else if(str1 == str2){
				same = false;
				int index = 0;
				int  a,b;
				while(!same){
					++index;
					a = char_array1[index];
					b = char_array2[index];
					if(a == b){
						continue;
					}else if(a != b){
						if(b < a){
							// cout << "\nyang di swap sama dengan: " << arr[i] << " & " << arr[i + 1] << endl; 
							Swap(&arr[i],&arr[i + 1]);
							Swap(&p.namaPenduduk[i],&p.namaPenduduk[i + 1]);
							Swap(&p.asalDaerah[i],&p.asalDaerah[i+1]);
							Swap(&p.status[i], &p.status[i + 1]);
							Swap(&p.NIK[i], &p.NIK[i + 1]);
							Swap(&p.golonganDarah[i], &p.golonganDarah[i + 1]);
							same = true;
							cout << "Proses Sort : ";
							for(int i = 0; i < sumData; i++){
								cout << arr[i] << " ";
							}
							cout << endl;
						}else{
							same = true;
						}
					}
				}
			}
		}
	}
	cout << "\n\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/* 			AKHIR INSERTION SORT 			*/

/* 			SHELL SORT 			*/
void ShellSort(penduduk &p, string arr[],int sumData){
	int l1,l2;
	bool same;
	cout << "Sebelum Sort : ";
	for(int k = 0; k < sumData; k++){
		cout << arr[k] << " ";
	}
	cout << endl;
	for(int gap = sumData/2; gap > 0; gap/=2){ //8 
		for(int i = gap; i < sumData; i++){
			string temp = arr[i];
			l1 = temp.length();
			char char_array1[l1 + 1];
			// mengubah bentuk string ke char array
			strcpy(char_array1, temp.c_str());//sort = 's','o','r','t' merge = 'm','e','r','g','e'
			// deklarasi untuk mengambil char index pertama pada char array
			int charBegin1, charBegin2;
			charBegin1 = char_array1[0];
			int j; 
			for(j = i; j >= gap; j -= gap){
				l2 = arr[j-gap].length();
				char char_array2[l2 + 1];
				// mengubah bentung string ke char array
				strcpy(char_array2, arr[j - gap].c_str());
				// mengambil char index pertama pada char array
				charBegin2 = char_array2[0];
				if(charBegin2 >= charBegin1){
					if(charBegin2 > charBegin1){
						Swap(&arr[j],&arr[j - gap]);
						Swap(&p.namaPenduduk[j],&p.namaPenduduk[j - gap]);
						Swap(&p.asalDaerah[j],&p.asalDaerah[j-gap]);
						Swap(&p.status[j], &p.status[j - gap]);
						Swap(&p.NIK[j], &p.NIK[j - gap]);
						Swap(&p.golonganDarah[j], &p.golonganDarah[j - gap]);
						cout << "\nProses Sort lebih besar : ";
						for(int i = 0; i < sumData; i++){
							cout << arr[i] << " ";
						}
						cout << endl;
					}else if(charBegin2 == charBegin1){
						same = false;
						int index = 0;
						int  a,b;
						while(!same){
							++index;
							a = char_array1[index];
							b = char_array2[index];
							if(a == b){
								continue;
							}else if(a != b){
								if(b > a){
									Swap(&arr[j],&arr[j - gap]);
									Swap(&p.namaPenduduk[j],&p.namaPenduduk[j - gap]);
									Swap(&p.asalDaerah[j],&p.asalDaerah[j-gap]);
									Swap(&p.status[j], &p.status[j - gap]);
									Swap(&p.NIK[j], &p.NIK[j - gap]);
									Swap(&p.golonganDarah[j], &p.golonganDarah[j - gap]);
									cout << "\nProses Sort sama dengan : ";
									for(int i = 0; i < sumData; i++){
									cout << arr[i] << " ";
									}
									cout << endl;
									same = true;
								}else{
									same = true;
								}
							}
						}
					}
					// if(same) break;
				}
			}
		}
	}
	cout << "\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/* 			AKHIR SHELL SORT 			*/

/* 			QUICK SORT 			*/
int partition (penduduk &p,string arr[], int low, int high){
	int l1,l2;
	bool same;
    string pivot = arr[high]; // pivot
    cout << "\nIsi Pivot adalah : " << pivot << endl;
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 	l1 = pivot.length();
	char char_array1[l1 + 1];
	strcpy(char_array1, pivot.c_str());
	int pi, object;
	pi = char_array1[0];
    for(int j = low; j <= high - 1; j++)
    {
    	l2 = arr[j].length();
		char char_array2[l2 + 1];
		strcpy(char_array2, arr[j].c_str());
		object = char_array2[0];
        // If current element is smaller than the pivot
        if(object <= pi) 
        {
             // increment index of smaller element
            if(object < pi){
            	++i;
				cout << "\nyang di swap lebih besar: " << arr[i] << " & " << arr[j] << endl;
				Swap(&arr[i],&arr[j]);
				Swap(&p.namaPenduduk[i],&p.namaPenduduk[j]);
				Swap(&p.asalDaerah[i],&p.asalDaerah[j]);
				Swap(&p.status[i], &p.status[j]);
				Swap(&p.NIK[i], &p.NIK[j]);
				Swap(&p.golonganDarah[i], &p.golonganDarah[j]);
				cout << "Proses Sort : ";
				for(int k = low; k <= high; k++){
					cout << arr[k] << " ";
				}
				cout << endl;
			}else if(pi == object){
				same = false;
				int index = 0;
				int  a,b;
				while(!same){
					++index;
					a = char_array1[index];
					b = char_array2[index];
					if(a == b){
						continue;
					}else if(a != b){
						if(b < a){
							++i;
							cout << "\nyang di swap sama dengan: " << arr[i] << " & " << arr[j] << endl; 
							Swap(&arr[i],&arr[j]);
							Swap(&p.namaPenduduk[i],&p.namaPenduduk[j]);
							Swap(&p.asalDaerah[i],&p.asalDaerah[j]);
							Swap(&p.status[i], &p.status[j]);
							Swap(&p.NIK[i], &p.NIK[j]);
							Swap(&p.golonganDarah[i], &p.golonganDarah[j]);
							same = true;
							cout << "Proses Sort : ";
							for(int i = low; i <= high; i++){
								cout << arr[i] << " ";
							}
							cout << endl;
						}else{
							same = true;
						}
					}
				}
			}
        }
    }
    Swap(&arr[i + 1],&arr[high]);
	Swap(&p.namaPenduduk[i + 1],&p.namaPenduduk[high]);
	Swap(&p.asalDaerah[i + 1],&p.asalDaerah[high]);
	Swap(&p.status[i + 1], &p.status[high]);
	Swap(&p.NIK[i + 1], &p.NIK[high]);
	Swap(&p.golonganDarah[i + 1], &p.golonganDarah[high]);
	cout << "\nHasil Proses Sort Sementara: ";
	for(int i = low; i <= high; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
    return (i + 1);
}
void QuickSort(penduduk &p,string arr[],int low,int high){
	if(low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(p,arr, low, high);
 		cout << "\npivot berada di index " << pi << " yaitu : " << arr[pi] << endl;
        // Separately sort elements before
        // partition and after partition
        cout << "\nMasuk Quick Sort kiri : \n";
        QuickSort(p,arr, low, pi - 1);
        cout << "\nMasuk Quick Sort kanan : \n";
        QuickSort(p,arr, pi + 1, high);
    }
}
/* 			AKHIR QUICK SORT 			*/

/* 			MENU SORT 			*/
void SortFile(){
	int pil;
	char main;
	int pilihSubjek,sumData;
	penduduk p;
	string arr[20];
	string namaFile,f;
	f = ".txt";
	cout << string(30,'=') << endl;
	cout << "SORTING DATA PENDUDUK" << endl;
	cout << string(30,'=') << endl;
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
		system("cls");
		char loop = 'Y'; 
		enum pilihSort{BUBBLE = 1,SELECTION,INSERT,SHELL,QUICK};
		while(pil <= 5 && (loop == 'Y' | loop == 'y')){
			cout << string(30,'=') << endl;
			cout << "Pilih Berdasarkan:\n";
			cout << string(30,'=') << endl;
			cout << "1. Nama Penduduk\n";
			cout << "2. Asal Daerah\n";
			cout << "3. NIK\n";
			cout << "4. Golongan Darah\n";
			cout << "5. Status Kawin\n";
			cout << "Pilih : "; cin >> pilihSubjek;
			if(pilihSubjek == 1){
				for(int i = 0;i < sumData;i++){
					arr[i] = p.namaPenduduk[i];
				}
			}else if(pilihSubjek == 2){
				for(int i = 0; i < sumData; i++){
					arr[i] = p.asalDaerah[i];
				}	
			}else if(pilihSubjek == 3){
				for(int i = 0; i < sumData; i++){
					arr[i] = p.NIK[i];
				}
			}else if(pilihSubjek == 4){
				for(int i = 0; i < sumData; i++){
					arr[i] = p.golonganDarah[i];
				}
			}else if(pilihSubjek == 5){
				for(int i = 0; i < sumData; i++){
					arr[i] = p.status[i];
				}
			}
			switch(pil){
				case BUBBLE:
				BubbleSort(p,arr,sumData);
				break;
				case SELECTION:
				SelectionSort(p,arr,sumData);
				break;
				case INSERT:
				InsertSort(p,arr,sumData);
				break;
				case SHELL:
				ShellSort(p,arr,sumData);
				break;
				case QUICK:
				cout << "Sebelum Sort : ";
				for(int k = 0; k < sumData; k++){
					cout << arr[k] << " ";
				}
				QuickSort(p,arr,0,sumData-1);
				cout << "\nSetelah Sort : ";
				for(int i = 0; i < sumData; i++){
					cout <<arr[i]<< " ";
				}
				cout << endl;
				break;
			}
			OutputData(p,sumData);
			ulang_opsi:
			cout << "\n\nUlangi Opsi Sort? \n";
			cout << "Y -> Kembali\n";
			cout << "N -> Keluar\n";
			cout << "Pilih : " ; cin >> loop;
			if(loop == 'y' | loop == 'Y'){
				system("cls");
			}else if(loop == 'n' | loop == 'N'){
				break;
			}else{
				cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
				goto ulang_opsi;
			}
		}
		ulang_menu:
		cout << "\n\nKembali ke Menu Sort? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : " ; cin >> main;
			if(main == 'y' | main == 'Y'){
				system("cls");
			}else if(main == 'n' | main == 'N'){
				break;
			}else{
				cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
				goto ulang_menu;
			}
		system("cls"); 
	}while(main == 'Y' | main == 'y');
}
/* 			AKHIR MENU SORT 			*/

/*====================AKHIR SORT====================*/

/*====================SEARCH====================*/

void OutputData(penduduk &p,int dataSama[],int sumData){
	for(int i = 0; i < sumData; i++){
		if(dataSama[i] > 0){
			cout << "\nData ke-" << i + 1 << endl;
			cout << "Nama Penduduk\t: " << p.namaPenduduk[i] << endl;
			cout << "Asal Daerah\t: " << p.asalDaerah[i] << endl;
			cout << "NIK\t\t: " << p.NIK[i] << endl;
			cout << "Golongan Darah\t: " << p.golonganDarah[i] << endl;
			cout << "Status Kawin\t: " << p.status[i] << endl;
		}
	}
	cout << endl;
}
void OutputSubData(penduduk &p,int dataSama[],int sumData, int *urutan){
	int data;
	for(int i = 0; i < sumData; i++){
		if(dataSama[i] > 0){
			cout << "\nData ke-" << urutan[i] + 1 << endl;
			cout << "Nama Penduduk\t: " << p.namaPenduduk[i] << endl;
			cout << "Asal Daerah\t: " << p.asalDaerah[i] << endl;
			cout << "NIK\t\t: " << p.NIK[i] << endl;
			cout << "Golongan Darah\t: " << p.golonganDarah[i] << endl;
			cout << "Status Kawin\t: " << p.status[i] << endl;
		}
	}
	cout << endl;
}

int ReadDataBinary(penduduk &p,string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,p.namaPenduduk[sumData])){
			getline(myFile,p.asalDaerah[sumData]);
			getline(myFile,p.NIK[sumData]);
			getline(myFile,p.status[sumData]);
			myFile >> p.golonganDarah[sumData];
			myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			sumData++;
		}
	}
	return sumData; 
}

int compare(string a, string b) {
    int aLength = a.length();
    int bLength = b.length();
    int length = min(aLength, bLength);
    for(int i=0; i<length; i++) {
        if(a[i]<b[i]) {
            return -1;
        }
        if(a[i]>b[i]) {
            return 1;
        }
    }
    if(aLength < bLength) {
        return -1;
    } else if (aLength > bLength){
        return 1;
    } else {
        return 0;
    }
}

penduduk BubbleSortNoOutput(penduduk p, string arr[], int sumData, int *urutan) {
    for(int i=0; i<sumData; i++) {
        urutan[i] = i;
    }
    for(int i=0; i<sumData; i++) {
        for(int j=0; j<sumData-i-1; j++) {
            if(compare(arr[j], arr[j+1]) > 0) {
                Swap(&arr[j],&arr[j+1]);
				Swap(&p.namaPenduduk[j],&p.namaPenduduk[j+1]);
				Swap(&p.asalDaerah[j],&p.asalDaerah[j+1]);
				Swap(&p.status[j], &p.status[j+1]);
				Swap(&p.NIK[j], &p.NIK[j+1]);
				Swap(&p.golonganDarah[j], &p.golonganDarah[j+1]);
            }
        }
    }
    return p;
}
int BinarySearch(string arr[],string find,int n){
	int lower = 0;
	int upper = n-1;
	while(lower <= upper){
		int mid = (lower + upper)/2;
		if(arr[mid] == find){
			return mid;
		}else if(find < arr[mid]){
			upper = mid - 1;
		}else{
			lower = mid + 1;
		}
	}
	return -1;
}
void BinarySearchMenu(penduduk &p,int sumData,string namaFile){
	char loop;
	do{
		int dataSama[20] = {0};
		int opsi;
		string name;
		system("cls");
		cout << "Cari Berdasarkan: \n";
		cout << "1. Nama Penduduk\n";
		cout << "2. Asal Daerah\n";
		cout << "3. NIK\n";
		cout << "4. Status\n";
		cout << "5. Golongan Darah\n";
		cout << "Pilih: "; cin >> opsi;cin.ignore();
		if(opsi == 1){
            int urutan[20];
			penduduk pSorted = BubbleSortNoOutput(p, p.namaPenduduk, sumData, urutan);

			cout << "Masukkan Nama Kendaraan yang Dicari : ";getline(cin,name);
			int nPenduduk = BinarySearch(pSorted.namaPenduduk, name, sumData);
			if (nPenduduk == -1) {
				cout << "Nama Penduduk Tidak Ditemukan\n";
			} else {
				dataSama[nPenduduk] = 1;

				for(int i=nPenduduk-1; i >= 0; i--) {
					if(pSorted.namaPenduduk[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=nPenduduk+1; i < sumData; i++) {
					if(pSorted.namaPenduduk[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 2){
		    int urutan[20];
			penduduk pSorted = BubbleSortNoOutput(p, p.asalDaerah, sumData, urutan);

			cout << "Masukkan Asal Penduduk yang Dicari : ";getline(cin,name);
			int asal = BinarySearch(pSorted.asalDaerah, name, sumData);

			if (asal == -1) {
				cout << "Tidak Ada Penduduk yang Berasal Dari " << name << endl;
			} else {
				dataSama[asal] = 1;
				for(int i=asal-1; i >= 0; i--) {
					if(p.asalDaerah[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=asal+1; i < sumData; i++) {
					if(p.asalDaerah[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 3){
		    int urutan[20];
			penduduk pSorted = BubbleSortNoOutput(p, p.NIK, sumData, urutan);

			cout << "Masukkan NIK yang Dicari : ";getline(cin,name);
			int nik = BinarySearch(pSorted.NIK, name, sumData);

			if (nik == -1) {
				cout << "NIK Tidak Ditemukan\n";
			} else {
				dataSama[nik] = 1;
				for(int i=nik-1; i >= 0; i--) {
					if(p.NIK[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=nik+1; i < sumData; i++) {
					if(p.NIK[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 4){
		    int urutan[20];
			penduduk pSorted = BubbleSortNoOutput(p, p.status, sumData, urutan);

			cout << "Masukkan Status yang Dicari : ";getline(cin,name);
			int status = BinarySearch(pSorted.status, name, sumData);

			if (status == -1) {
				cout << "status Tidak Ditemukan\n";
			} else {
				dataSama[status] = 1;
				for(int i=status-1; i >= 0; i--) {
					if(p.status[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=status+1; i < sumData; i++) {
					if(p.status[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 5){
		    int urutan[20];
			penduduk pSorted = BubbleSortNoOutput(p, p.golonganDarah, sumData, urutan);

			cout << "Masukkan NIK yang Dicari : ";getline(cin,name);
			int golDar = BinarySearch(pSorted.golonganDarah, name, sumData);

			if (golDar == -1) {
				cout << "golDar Tidak Ditemukan\n";
			} else {
				dataSama[golDar] = 1;
				for(int i=golDar-1; i >= 0; i--) {
					if(p.golonganDarah[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=golDar+1; i < sumData; i++) {
					if(p.golonganDarah[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}
		ulang:
		cout << "\n\nKembali ke Opsi ? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : " ; cin >> loop;
		if(loop == 'y' | loop == 'Y'){
			sumData = ReadDataBinary(p,namaFile);
			system("cls");
		}else if(loop == 'n' | loop == 'N'){
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang;
		}
		system("cls");
	}while(loop == 'y' | loop == 'Y');
}
void SequentialSearch(penduduk &p,int sumData){
	char loop;
	do{
		int dataSama[20] = {0};
		int opsi;
		string name;
		cout << "Cari Berdasarkan: \n";
		cout << "1. Nama Penduduk\n";
		cout << "2. Asal Daerah\n";
		cout << "3. NIK\n";
		cout << "4. Golongan Darah\n";
		cout << "5. Status Kawin\n";
		cout << "Pilih: "; cin >> opsi;cin.ignore();
		if(opsi == 1){
			int find = 0;
			cout << "Masukkan Nama Penduduk yang Dicari : ";getline(cin,name);
			int i = 0;
			while(i < sumData){
				if(p.namaPenduduk[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
				i++;
			} 
			if(find > 0){
				OutputData(p,dataSama,sumData);
			}else{
				cout << "Nama Penduduk Tidak Ditemukan\n";
			}
		}else if(opsi == 2){
			int find = 0;
			cout << "Masukkan Asal Daerah Penduduk yang Dicari : ";getline(cin,name);
			int i = 0;
			while(i < sumData){
				if(p.asalDaerah[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
					i++;
			} 
			if(find > 0){
				OutputData(p,dataSama,sumData);
			}else{
				cout << "Tidak Ada Penduduk yang Berasal dari " << name << endl;
			}
		}else if(opsi == 3){
			cout << "Masukkan NIK yang Dicari : ";getline(cin,name);
			int find = 0;
			int i = 0;
			while(i < sumData){
				if(p.NIK[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
					i++;
			}
			if(find > 0){
				OutputData(p,dataSama,sumData);
			}else{
				cout << "NIK Penduduk Tidak Ditemukan\n"; 
			}
		}else if(opsi == 4){
			cout << "Masukkan Golongan Darah yang Dicari : ";getline(cin,name);
			int find = 0;
			int i = 0;
			while(i < sumData){
				if(p.golonganDarah[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
					i++;
			}
			if(find > 0){
				OutputData(p,dataSama,sumData);
			}else{
				cout << "Golongan Darah Penduduk Tidak Ditemukan\n"; 
			}
		}else if(opsi == 5){
			cout << "Masukkan Status yang Dicari : ";getline(cin,name);
			int find = 0;
			int i = 0;
			while(i < sumData){
				if(p.status[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
					i++;
			}
			if(find > 0){
				OutputData(p,dataSama,sumData);
			}else{
				cout << "Status Penduduk Tidak Ditemukan\n"; 
			}
		}
		ulang:
		cout << "\n\nKembali ke Opsi ? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : " ; cin >> loop;
		if(loop == 'y' | loop == 'Y'){
			system("cls");
		}else if(loop == 'n' | loop == 'N'){
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang;
		}
		system("cls");
	}while(loop == 'y' | loop == 'Y');
}
void SearchFile(){
	char loop;
	do{
		int pil,sumData,index;
		penduduk dataPenduduk;
		string namaFile,name;
		string arrBinary[20];
		string f = ".txt";
		enum pilihan{SEQUENTIAL = 1, BINARY};
		cout << "==========================================\n";
		cout << "CARI DATA KENDARAAN PENDUDUK\n";
		cout << "==========================================\n";
		cout << "Masukkan Nama File : ";cin >> namaFile;
		namaFile += f;
		sumData = ReadData(dataPenduduk,namaFile);
		system("cls");
		cout << "==========================================\n";
		cout << "CARI DATA KENDARAAN PARKIR\n";
		cout << "==========================================\n";
		cout << "1. Sequential Search\n";
		cout << "2. Binary Search\n";
		cout << "Pilih : ";cin >> pil;
		system("cls");
		switch(pil){
			case SEQUENTIAL:
			SequentialSearch(dataPenduduk,sumData);
			break;
			case BINARY:
			BinarySearchMenu(dataPenduduk, sumData,namaFile);
			break;
		}
		loop:
		cout << "\n\nUlangi Menu Metode Search? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : " ; cin >> loop;
		if(loop == 'y' | loop == 'Y'){
			system("cls");
		}
		else if(loop == 'n' || loop == 'N'){
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto loop;
		}
	}while(loop == 'y' | loop == 'Y');
}
/*====================AKHIR SEARCH====================*/

/*====================TRANSAKSI====================*/

/*					MERGE 					*/

void BubbleSortMerge(penduduk &p, string arr[], int sumData, int awal) {
    for(int i=0; i<sumData-awal; i++) {
        for(int j=awal; j<sumData-i-1; j++) {
            if(compare(arr[j], arr[j+1]) > 0) {
                Swap(&arr[j],&arr[j+1]);
				Swap(&p.namaPenduduk[j],&p.namaPenduduk[j+1]);
				Swap(&p.asalDaerah[j],&p.asalDaerah[j+1]);
				Swap(&p.status[j], &p.status[j+1]);
				Swap(&p.NIK[j], &p.NIK[j+1]);
				Swap(&p.golonganDarah[j], &p.golonganDarah[j+1]);
            }
        }
    }
}
void Merge(string type){
	string loop;
	do{
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
			int iFile1 = 0;
			int iFile2 = 0;
			int sumData = 0;
			string f = ".txt";
			penduduk p;
			ifstream myFile;
			myFile.open(file1);
			while(getline(myFile,p.namaPenduduk[sumData])){
				getline(myFile,p.asalDaerah[sumData]);
				getline(myFile,p.NIK[sumData]);
				getline(myFile,p.status[sumData]);
				myFile >> p.golonganDarah[sumData];
				iFile1++;
				sumData++; 
				myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			}
			if(type == "urut"){
				cout<<"\nMelakukan Proses Bubble Sorting Terlebih Dahulu...\n";
				string arr[20];
				for(int j = sumData - iFile1;j < sumData;j++){
					arr[j] = p.NIK[j];
				}
				BubbleSortMerge(p,arr,sumData,sumData-iFile1);
			}

			myFile.close();
			myFile.open(file2);
			while(getline(myFile,p.namaPenduduk[sumData])){
				getline(myFile,p.asalDaerah[sumData]);
				getline(myFile,p.NIK[sumData]);
				getline(myFile,p.status[sumData]);
				myFile >> p.golonganDarah[sumData];
				iFile2++;
				sumData++;
				myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			}
			if(type == "urut"){
				string arr[20];
				for(int j = sumData - iFile2;j < sumData;j++){
					arr[j] = p.NIK[j];
				}
				BubbleSortMerge(p,arr,sumData,sumData-iFile2);
			}
			myFile.close();
			
			cout<<"\nFile baru : \n";
			cout <<"Input nama File baru: "; cin >> namaFile;
			namaFile += f;
			cout<<"\nFile baru berhasil disimpan, Silahkan lihat data pada Main menu\n";
			
			ofstream inFile;
			inFile.open(namaFile, ios::trunc);
			for(int j=0; j<sumData; j++){
				inFile << p.namaPenduduk[j] << endl
				<< p.asalDaerah[j] << endl
				<< p.NIK[j] << endl
				<< p.status[j] << endl
				<< p.golonganDarah[j] << endl;
			}
		loop:
		cout << "\n\nUlangi Merge ? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : " ; cin >> loop;
		if(loop == "y" || loop == "Y"){
			system("cls");
			goto ulang;
		}else if(loop == "n" || loop == "N"){
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto loop;
		}
	}while(loop == "y" || loop == "Y");
}
/*				AKHIR MERGE 				*/

/*				MENU TRAKSAKSI 				*/
void EditFile(){
	char loop;
	do {
		int pilihan;
		ulang:
		cout<<"=========================\n";
		cout<<" TRANSAKSI\n";
		cout<<"=========================\n";
		cout<<"1. Merging Sambung\n";
		cout<<"2. Merging Urut\n";
		cout<<"Masukan Pilihan : "; cin>> pilihan;
		enum editOption{SAMBUNG = 1, URUT};
		system("cls");
		switch(pilihan ){
			case SAMBUNG:
			Merge("sambung");
			break;
			case URUT:
			Merge("urut");
			break;
		}
		loop:
		cout << "\n\nUlangi Menu Transaksi? \n";
		cout << "Y -> Kembali\n";
		cout << "N -> Keluar\n";
		cout << "Pilih : " ; cin >> loop;
		if(loop == 'y' | loop == 'Y'){
			system("cls");
		}
		else if(loop == 'n' || loop == 'N'){
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto loop;
		}
	}while(loop == 'Y' | loop == 'Y');
}
/*				AKHIR MENU TRAKSAKSI 				*/
/*====================AKHIR TRANSAKSI====================*/

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