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
1. kondisi looping di setiap function
2. merge sort belom
3. buat fungsi untuk penampilan merge agar nggak keliatan haisl file gabungannya
*/

struct parkir{
	string jam[20];
	string namaKendaraan[20];
	string plat[20];
}dataParkir;

/*====================MAIN MENU====================*/
int MainMenu(){
	int pilih;
	bool isTrue = false;
	while(!isTrue){
		cout << string(42,'=') << endl;
		cout << "DAFTAR KENDARAAN PARKIR DI CAREFOUR\n";
		cout << string(42,'=') << endl;
		cout << "1. INPUT DATA\n";
		cout << "2. TAMPILKAN DATA \n";
		cout << "3. SORTING DATA \n";
		cout << "4. SEARCHING DATA \n";
		cout << "5. TRANSAKSI DATA \n";
		cout << "6. KELUAR\n";
		cout << "Pilih Nomor : "; cin >> pilih;
		if(pilih > 6){
			cout << "Keyword Anda SALAH, Silahkan Input Lagi..\n";
			system("pause");
			system("cls");
		}else{
			isTrue = true;
		}
	}

	system("cls");
	return pilih;
}
/*====================AKHIR MAIN MENU====================*/

/*====================MENULIS FILE====================*/
void WriteFile(){
	char loop;
	do{
		cout << string(30,'=') << endl;
		cout << "INPUT DATA PARKIR\n";
		cout << string(30,'=') << endl;
		parkir p;
		string namaFile;
		int jml;
		string f = ".txt";
		cout <<"Input nama File: "; cin >> namaFile;
		namaFile += f;
		ofstream myFile;
		myFile.open(namaFile, ios::app);
		cout << "Masukkan Jumlah data yang dimasukkan : "; cin >> jml;cin.ignore();
		system("cls");
		cout << string(30,'=') << endl;
		cout << "INPUT DATA PARKIR\n";
		cout << string(30,'=') << endl;
		for(int i = 0; i < jml; i++){
			cout << "Data ke-" << i + 1 << endl;
			cout << "Masukkan nomor plat kendaraan  : ";getline(cin,p.plat[i]);myFile << p.plat[i] << endl ;
			cout << "Masukkan nama mobil            : ";getline(cin,p.namaKendaraan[i]);myFile << p.namaKendaraan[i] << endl;
			cout << "Masukkan waktu masuk kendaraan : "; cin >> p.jam[i];cin.ignore();myFile << p.jam[i] << endl ;
			cout << endl;
		}
		ulang_opsi:
		cout << "\n\nInput File Lagi? \n";
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
	cout <<"Input nama File: "; cin >> namaFile;
	namaFile += f;
	string plat,nama,waktuMasuk;
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

void Swap(int *a, int *b){
 	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*			BUBBLE SORT 		*/
void BubbleSort(parkir &p, string arr[], int sumData){
	int l1,l2;
	cout << "\n\nSebelum Sort : ";
	for(int i = 0; i < sumData; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "PROSES SORT: \n";
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
		for(int k = 0; k < sumData; k++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "\n\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}

// a < b = -1
// a == b = 0
// a > b = 1
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

parkir BubbleSortNoOutput(parkir p, string arr[], int sumData, int *urutan) {
    for(int i=0; i<sumData; i++) {
        urutan[i] = i;
    }
    for(int i=0; i<sumData; i++) {
        for(int j=0; j<sumData-i-1; j++) {
            if(compare(arr[j], arr[j+1]) > 0) {
                Swap(&arr[j],&arr[j+1]);
                 Swap(&p.namaKendaraan[j],&p.namaKendaraan[j+1]);
                Swap(&p.plat[j], &p.plat[j+1]);
                Swap(&p.jam[j], &p.jam[j+1]);
                Swap(&urutan[j], &urutan[j+1]);
            }
        }
    }
    return p;
}

/*			AKHIR BUBBLE SORT 		*/


/* 			SELECTION SORT 			*/
void SelectionSort(parkir &p, string arr[], int sumData){
	int indexMin,l1,l2;
	cout << "Sebelum Sort : ";
	for(int i = 0; i < sumData; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "\nPROSES SORT: \n";
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
		for(int k = 0; k < sumData; k++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/* 			AKHIR SELECTION SORT 			*/

/* 			INSERTION SORT 			*/
void InsertSort(parkir &p,string arr[],int sumData){
	int l1,l2;
	bool same;
	int i;
	cout << "\n\nSebelum Sort : ";
	for(int k = 0; k < sumData; k++){
		cout << arr[k] << " ";
	}
	cout << endl;
	cout << "\nPROSES SORT: \n";
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
				Swap(&p.namaKendaraan[i],&p.namaKendaraan[i + 1]);
				Swap(&p.plat[i], &p.plat[i + 1]);
				Swap(&p.jam[i], &p.jam[i + 1]);
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
							cout << "\nyang di swap sama dengan: " << arr[i] << " & " << arr[i + 1] << endl;
							Swap(&arr[i],&arr[i+1]);
						 	Swap(&p.namaKendaraan[i],&p.namaKendaraan[i + 1]);
							Swap(&p.plat[i], &p.plat[i + 1]);
							Swap(&p.jam[i], &p.jam[i + 1]);
							same = true;
						}else{
							same = true;
						}
					}
				}
			}
		}
		for(int i = 0; i < sumData; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "\n\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/* 			AKHIR INSERTION SORT 			*/

/* 			SHELL SORT 			*/
void ShellSort(parkir &p, string arr[],int sumData){
	int gap = sumData;
	int l1,l2;
	bool same;
	cout << "Sebelum Sort : ";
	for(int k = 0; k < sumData; k++){
		cout << arr[k] << " ";
	}
	cout << endl;
	cout << "\nPROSES SORT: \n";
	for(int gap = sumData/2; gap > 0; gap/=2){
		for(int i = gap; i < sumData; i++){
			string temp = arr[i];
			l1 = temp.length();
			char char_array1[l1 + 1];
			// mengubah bentung string ke char array
			strcpy(char_array1, temp.c_str());
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
						Swap(&arr[j],&arr[j-gap]);
						Swap(&p.namaKendaraan[j],&p.namaKendaraan[j-gap]);
						Swap(&p.plat[j], &p.plat[j-gap]);
						Swap(&p.jam[j], &p.jam[j-gap]);
						// cout << "\nProses Sort lebih besar : ";
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
									Swap(&arr[j],&arr[j-gap]);
									Swap(&p.namaKendaraan[j],&p.namaKendaraan[j-gap]);
									Swap(&p.plat[j], &p.plat[j-gap]);
									Swap(&p.jam[j], &p.jam[j-gap]);
									// cout << "\nProses Sort sama dengan : ";
									same = true;
								}else{
									same = true;
								}
							}
						}
					}
				}
			}
		}
		for(int i = 0; i < sumData; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/* 			AKHIR SHELL SORT 			*/

/* 			QUICK SORT 			*/
int partition (parkir &p,string arr[], int low, int high){
	int l1,l2;
	bool same;
    string pivot = arr[high]; // pivot
    // cout << "\nIsi Pivot adalah : " << pivot << endl;
    int i = (low - 1);//index terkecil
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
        if(object <= pi)
        {
            if(object < pi){
            	++i;
				// cout << "\nyang di swap lebih besar: " << arr[i] << " & " << arr[j] << endl;
				Swap(&arr[i],&arr[j]);
				Swap(&p.namaKendaraan[i],&p.namaKendaraan[j]);
				Swap(&p.plat[i], &p.plat[j]);
				Swap(&p.jam[i], &p.jam[j]);
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
							// cout << "\nyang di swap sama dengan: " << arr[i] << " & " << arr[j] << endl;
							Swap(&arr[i],&arr[j]);
						 	Swap(&p.namaKendaraan[i],&p.namaKendaraan[j]);
							Swap(&p.plat[i], &p.plat[j]);
							Swap(&p.jam[i], &p.jam[j]);
							same = true;
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
	Swap(&p.namaKendaraan[i + 1],&p.namaKendaraan[high]);
	Swap(&p.plat[i + 1], &p.plat[high]);
	Swap(&p.jam[i + 1], &p.jam[high]);
	cout << "\nHasil Proses Sort Sementara: ";
	for(int i = low; i <= high; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
    return (i + 1);
}
void QuickSort(parkir &p,string arr[],int low,int high){
	if(low < high)
    {
        int pi = partition(p,arr, low, high);
 		// cout << "\npivot berada di index " << pi << " yaitu : " << arr[pi] << endl;
        // cout << "\nMasuk Quick Sort kiri : \n";
        QuickSort(p,arr, low, pi - 1);
        // cout << "\nMasuk Quick Sort kanan : \n";
        QuickSort(p,arr, pi + 1, high);
    }
}
/* 			AKHIR QUICK SORT 			*/

/*				MERGE SORT 				*/
void MergeSort(parkir* park, string* arr, int bottom, int top) {
	cout << endl;
	if(bottom == top) return;
	int mid = (bottom+top)/2;
	
	// Split arr into two in the mid, then sort each of them
	// If array is (E D C B A), split them into (E D C) and (B A), sort each of them so it become (C D E) (A B)
	
	MergeSort(park, arr, bottom, mid);
	MergeSort(park, arr, mid+1, top);
	
	int left = bottom;
	int right = mid+1;
	int arrCount = top - bottom + 1;
	
	// bottom       top
	//   v           v
	//   C  D  E  A  B
	//   ^        ^
	//  left    right
	
	// Sorting process
	
	string tmp[arrCount];
	parkir pTmp;
	int i = 0;
	while(i < arrCount) {
		if(left > mid) { // If 'left' points beyond the mid point (in our case, it's pointing at 'B')
			tmp[i] = arr[right];
			pTmp.jam[i] = park->jam[right];
			pTmp.namaKendaraan[i] = park->namaKendaraan[right];
			pTmp.plat[i] = park->plat[right];
			right++;
		} else if(right > top) { // If 'right' points beyond the top point (in our case, it's pointing beyond 'A')
			tmp[i] = arr[left];
			pTmp.jam[i] = park->jam[left];
			pTmp.namaKendaraan[i] = park->namaKendaraan[left];
			pTmp.plat[i] = park->plat[left];
			left++;
		} else if(compare(arr[left], arr[right]) > 0) { // If arr[left] > arr[right]
			tmp[i] = arr[right];
			pTmp.jam[i] = park->jam[right];
			pTmp.namaKendaraan[i] = park->namaKendaraan[right];
			pTmp.plat[i] = park->plat[right];
			right++;
		} else { // If arr[left] < arr[right]
			tmp[i] = arr[left];
			pTmp.jam[i] = park->jam[left];
			pTmp.namaKendaraan[i] = park->namaKendaraan[left];
			pTmp.plat[i] = park->plat[left];
			left++;
		}
		i++;
	}
	
	// Once the program enters this part, array 'tmp' is sorted version of array 'arr[bottom to top]'
	// Now, let's put array tmp into 'arr[bottom to top]'
	
	for(int i=0; i<arrCount; i++) {
		arr[i+bottom] = tmp[i];
		park->jam[i+bottom] = pTmp.jam[i];
		park->namaKendaraan[i+bottom] = pTmp.namaKendaraan[i];
		park->plat[i+bottom] = pTmp.plat[i];
	}
}
/*				AKHIR MERGE SORT 				*/

/* 			MENU SORT 			*/
void SortFile(){
	int pil;
	char main;
	int pilihSubjek,sumData;
	parkir p;
	string arr[20];
	string namaFile,f;
	f = ".txt";
	cout << string(30,'=') << endl;
	cout << "SORTING DATA PARKIR" << endl;
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
		cout << "6. Merge Sort\n";
		cout << "Pilih : ";cin >>pil;
		system("cls");
		char loop = 'Y';
		enum pilihSort{BUBBLE = 1,SELECTION,INSERT,SHELL,QUICK,MERGE};
		while(pil <= 6 && (loop == 'Y' | loop == 'y')){
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
					cout << endl;
					cout << "\nPROSES SORT: \n";
					QuickSort(p,arr,0,sumData-1);
					cout << "\nSetelah Sort : ";
					for(int i = 0; i < sumData; i++){
						cout <<arr[i]<< " ";
					}
					cout << endl;
					break;
				case MERGE:
					cout << "Sebelum Sort : ";
					for(int k = 0; k < sumData; k++){
						cout << arr[k] << " ";
					}
					cout << endl;
					MergeSort(&p, arr, 0, sumData-1);
					cout << "\nSetelah Sort : ";
					for(int i=0; i<sumData; i++) {
						cout << arr[i] << " ";
					}
					cout << endl;
					break;
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

void OutputSubData(parkir &p,int dataSama[],int sumData){
	int data;
	for(int i = 0; i < sumData; i++){
		if(dataSama[i] > 0){
			cout << "\nData ke-" << i + 1 << endl;
			cout << "Nama Kendaraan\t: " << p.namaKendaraan[i] << endl;
			cout << "Jam Masuk\t: " << p.jam[i] << endl;
			cout << "Plat Kendaraan\t: " << p.plat[i] << endl;
		}
	}
	cout << endl;
}

void OutputSubData(parkir &p,int dataSama[],int sumData, int *urutan){
	int data;
	for(int i = 0; i < sumData; i++){
		if(dataSama[i] > 0){
			cout << "\nData ke-" << urutan[i] + 1 << endl;
			cout << "Nama Kendaraan\t: " << p.namaKendaraan[i] << endl;
			cout << "Jam Masuk\t: " << p.jam[i] << endl;
			cout << "Plat Kendaraan\t: " << p.plat[i] << endl;
		}
	}
	cout << endl;
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

void SequentialSearch(parkir &p,int sumData){
	char loop;
	do{
		int dataSama[20] = {0};
		int opsi;
		string name;
		cout << "Cari Berdasarkan: \n";
		cout << "1. Nama Kendaraan\n";
		cout << "2. Jam Masuk\n";
		cout << "3. Plat Kendaraan\n";
		cout << "Pilih: "; cin >> opsi;cin.ignore();
		if(opsi == 1){
			int find = 0;
			cout << "Masukkan Nama Kendaraan yang Dicari : ";getline(cin,name);
			int i = 0;
			while(i < sumData){
				if(p.namaKendaraan[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
				i++;
			}
			if(find > 0){
				OutputSubData(p,dataSama,sumData);
			}else{
				cout << "Nama Kendaraan Tidak Ditemukan\n";
			}
		}else if(opsi == 2){
			int find = 0;
			cout << "Masukkan Jam Masuk Kendaraan yang Dicari : ";getline(cin,name);
			int i = 0;
			while(i < sumData){
				if(p.jam[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
					i++;
			}
			if(find > 0){
				OutputSubData(p,dataSama,sumData);
			}else{
				cout << "Tidak Ada Kendaraan yang Masuk Pada Jam " << name << endl;
			}
		}else if(opsi == 3){
			cout << "Masukkan Plat Kendaraan yang Dicari : ";getline(cin,name);
			int find = 0;
			int i = 0;
			while(i < sumData){
				if(p.plat[i] == name){
					dataSama[i]++;
					find++;
					i++;
				}
				else
					i++;
			}
			if(find > 0){
				OutputSubData(p,dataSama,sumData);
			}else{
				cout << "Plat Kendaraan Tidak Ditemukan\n";
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

void BinarySearch(parkir &p,int sumData){
	char ulang;
	do{
		int dataSama[20] = {0};
		int opsi;
		string name;
		system("cls");
		cout << "Cari Berdasarkan: \n";
		cout << "1. Nama Kendaraan\n";
		cout << "2. Jam Masuk\n";
		cout << "3. Plat Kendaraan\n";
		cout << "Pilih: "; cin >> opsi;cin.ignore();
		if(opsi == 1){
            int urutan[20];
			parkir pSorted = BubbleSortNoOutput(p, p.namaKendaraan, sumData, urutan);

			cout << "Masukkan Nama Kendaraan yang Dicari : ";getline(cin,name);
			int kendaraan = BinarySearch(pSorted.namaKendaraan, name, sumData);
			if (kendaraan == -1) {
				cout << "Nama Kendaraan Tidak Ditemukan\n";
			} else {
				dataSama[kendaraan] = 1;

				for(int i=kendaraan-1; i >= 0; i--) {
					if(pSorted.namaKendaraan[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=kendaraan+1; i < sumData; i++) {
					if(pSorted.namaKendaraan[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 2){
		    int urutan[20];
			parkir pSorted = BubbleSortNoOutput(p, p.jam, sumData, urutan);

			cout << "Masukkan Jam Masuk Kendaraan yang Dicari : ";getline(cin,name);
			int kendaraan = BinarySearch(pSorted.jam, name, sumData);

			if (kendaraan == -1) {
				cout << "Tidak Ada Kendaraan yang Masuk Pada Jam " << name << endl;
			} else {
				dataSama[kendaraan] = 1;
				for(int i=kendaraan-1; i >= 0; i--) {
					if(p.jam[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=kendaraan+1; i < sumData; i++) {
					if(p.jam[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 3){
		    int urutan[20];
			parkir pSorted = BubbleSortNoOutput(p, p.plat, sumData, urutan);

			cout << "Masukkan Plat Kendaraan yang Dicari : ";getline(cin,name);
			int kendaraan = BinarySearch(pSorted.plat, name, sumData);

			if (kendaraan == -1) {
				cout << "Plat Kendaraan Tidak Ditemukan\n";
			} else {
				dataSama[kendaraan] = 1;
				for(int i=kendaraan-1; i >= 0; i--) {
					if(p.plat[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=kendaraan+1; i < sumData; i++) {
					if(p.plat[i] == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}
		cout << "Kembali ke Opsi Searching ? ";cin >> ulang;
		system("cls");
	}while(ulang == 'y' | ulang == 'Y');
}

void SearchFile(){
	char loop;
	do{
		int pil,sumData,index;
		parkir dataParkir;
		string namaFile,name;
		string arrBinary[20];
		string f = ".txt";
		enum pilihan{SEQUENTIAL = 1, BINARY};
		cout << "==========================================\n";
		cout << "CARI DATA KENDARAAN PARKIR\n";
		cout << "==========================================\n";
		cout << "Masukkan Nama File : ";cin >> namaFile;
		namaFile += f;
		sumData = ReadData(dataParkir,namaFile);
		system("cls");
		cout << "==========================================\n";
		cout << "CARI DATA KENDARAAN PARKIR\n";
		cout << "==========================================\n";
		cout << "1. Sequential Search\n";
		cout << "2. Binary Search\n";
		cout << "Pilih : ";cin >> pil;
		switch(pil){
			case SEQUENTIAL:
			SequentialSearch(dataParkir,sumData);
			break;
			case BINARY:
			BinarySearch(dataParkir, sumData);
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
			case FINISH:
			cout << "\n====== TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI ======\n\n";
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
