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
Nggak Ada
*/

struct parkir{
	string jam;
	string namaKendaraan;
	string plat;
} dataParkir[20];
/*		Main Menu 		*/
int MainMenu();

/*		Input File 		*/
void WriteFile();

/*		Output Data 		*/
string ReadFile();
int ReadData(parkir p[],string namaFile);

/*		Sort 		*/
void OutputData(parkir p, int sumData);
void Swap(string *a, string *b);
void Swap(int *a, int *b);
void BubbleSort(parkir p[], string arr[], int sumData);
void SelectionSort(parkir p[], string arr[], int sumData);
void InsertSort(parkir p[],string arr[],int sumData);
void ShellSort(parkir p[], string arr[],int sumData);
int partition (parkir p[],string arr[], int low, int high);
void QuickSort(parkir p[],string arr[],int low,int high);
int compare(string a, string b);
void MergeSort(parkir* park[], string* arr, int bottom, int top);
void SortFile();

/*		Search 		*/
void OutputSubData(parkir p[],int dataSama[],int sumData);
void OutputSubData(parkir p[],int dataSama[],int sumData, int *urutan);
int ReadDataBinary(parkir p[],string namaFile);
parkir BubbleSortNoOutput(parkir p[], string arr[], int sumData, int *urutan);
int BinarySearch(string arr[],string find,int n);
void BinarySearchMenu(parkir p[],int sumData,string namaFile);
void SequentialSearch(parkir p[],int sumData);
void SearchFile();

/*		Merge 		*/
/*void Merge(string type);
void EditFile();*/


/*====================MAIN CODING====================*/
int main()
{
	int pilihan = MainMenu();
	string loop;
	char ulang;
	int foundFile;

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
			cout << "\n\n\t===== TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI! =====\n\n";
			system("pause");
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto ulang;
		}
	}
	return 0;
}
/*====================AKHIR MAIN CODING====================*/

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
		cout << string(42,'=') << endl;
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
		string namaFile;
		int jml;
		string f = ".txt";
		cout <<"Input nama File: "; cin >> namaFile;
		namaFile += f;
		ofstream myFile;
		myFile.open(namaFile, ios::app);
		cout << "Masukkan Jumlah data yang dimasukkan : "; cin >> jml;cin.ignore();
		parkir p[jml];
		system("cls");
		cout << string(30,'=') << endl;
		cout << "INPUT DATA PARKIR\n";
		cout << string(30,'=') << endl;
		for(int i = 0; i < jml; i++){
			cout << "Data ke-" << i + 1 << endl;
			cout << "Masukkan nomor plat kendaraan  : ";getline(cin,p[i].plat);myFile << p[i].plat << endl ;
			cout << "Masukkan nama mobil            : ";getline(cin,p[i].namaKendaraan);myFile << p[i].namaKendaraan << endl;
			cout << "Masukkan waktu masuk kendaraan : "; cin >> p[i].jam;cin.ignore();myFile << p[i].jam << endl ;
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
	ulang_inputNama:
	cout <<"Input nama File: "; cin >> namaFile;
	namaFile += f;
	string plat,nama,waktuMasuk;
	ifstream myFile;
	myFile.open(namaFile);
	if(myFile.is_open()){
		cout << "\n\n\t" << string(90,'=') << endl;
		cout << "\t" << "|" << setw(6) <<"No" << setw(25) << "Nama Kendaraan" << setw(28) << "Plat Kendaraan" << setw(22) << "Waktu Masuk" << setw(8) << "|" << endl;
		while(getline(myFile,plat)){
			i++;
			cout << "\t" <<string(90,'=') << endl;
			myFile >> nama;
			myFile >> waktuMasuk;
			cout << "\t" << "|" << setw(5) << i << setw(22) << nama << setw(28) << plat << setw(22) << waktuMasuk << setw(12) << "|" << endl;
			myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			// masalah getline string : https://stackoverflow.com/questions/11039323/use-getline-and-when-read-file-c
		}
		cout << "\t" + string(90,'=') << endl;
		return namaFile;
	}else{
		cout << "Nama File tidak ditemukan!" << endl;
		system("pause");
		system("cls");
		goto ulang_inputNama;
	}
}
int ReadData(parkir *p ,string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,(*(p+sumData).plat)){
			myFile >> (*(p+sumData).namaKendaraan);
			myFile >> (*(p+sumData).jam);
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
/*====================AKHIR MEMBACA FILE====================*/

/*========================SORT========================*/

void OutputData(parkir p, int sumData){
	cout << "\n\n\t" + string(90,'=') << endl;
	cout << "\t" << "|" << setw(6) <<"No" << setw(25) << "Nama Kendaraan" << setw(28) << "Plat Kendaraan" << setw(22) << "Waktu Masuk" << setw(8) << "|" << endl;
	for(int i = 0; i < sumData; i++){
		cout << "\t" + string(90,'=') << endl;
		cout << "\t" <<"|" << setw(5) << i + 1 << setw(22) << p[i].namaKendaraan << setw(28) << p.[i]plat << setw(22) << p[i].jam << setw(12) << "|" << endl;
	}
	cout << "\t" + string(90,'=') << endl;
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
void BubbleSort(parkir p[] , string arr[], int sumData){
	int l1,l2;
	cout << "\n\nSebelum Sort : ";
	for(int i = 0; i < sumData; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "\nPROSES SORT: \n";
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
			 	Swap(&p[j].namaKendaraan,&p[j+1].namaKendaraan);
				Swap(&p[j].plat, &p[j+1].plat);
				Swap(&p[j].jam, &p[j+1].jam);
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
						 	Swap(&p[j].namaKendaraan,&p[j + 1].namaKendaraan);
							Swap(&p[j].plat, &p[j + 1].plat);
							Swap(&p[j].jam, &p[j + 1].jam);
							same = true;
						}else{
							same = true;
						}
					}
				} 
			}
		}
		for(int k = 0; k < sumData; k++){
			cout << arr[k] << " ";
		}
		cout << endl;
	}
	cout << "\n\nSetelah Sort : ";
	for(int i = 0; i < sumData; i++){
		cout <<arr[i]<< " ";
	}
	cout << endl;
}
/*			AKHIR BUBBLE SORT 		*/


/* 			SELECTION SORT 			*/
void SelectionSort(parkir p[], string arr[], int sumData){
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
		Swap(&p[i].namaKendaraan,&p[indexMin].namaKendaraan);
		Swap(&p[i].plat, &p[indexMin].plat);
		Swap(&p[i].jam, &p[indexMin].jam);
		for(int k = 0; k < sumData; k++){
			cout << arr[k] << " ";
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
void InsertSort(parkir p[],string arr[],int sumData){
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
				Swap(&p[i].namaKendaraan,&p[i + 1].namaKendaraan);
				Swap(&p[i].plat, &p[i + 1].plat);
				Swap(&p[i].jam, &p[i + 1].jam);
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
							Swap(&arr[i],&arr[i + 1]);
							Swap(&p[i].namaKendaraan,&p[i + 1].namaKendaraan);
							Swap(&p[i].plat, &p[i + 1].plat);
							Swap(&p[i].jam, &p[i + 1].jam);
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
void ShellSort(parkir p[], string arr[],int sumData){
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
						Swap(&p[j].namaKendaraan,&p[j - gap].namaKendaraan);
						Swap(&p[j].plat, &p[j - gap].plat);
						Swap(&p[j].jam, &p[j - gap].jam);
						// cout << "\nProses Sort lebih besar : ";
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
									Swap(&arr[j],&arr[j-gap]);
									Swap(&p[j].namaKendaraan,&p[j - gap].namaKendaraan);
									Swap(&p[j].plat, &p[j - gap].plat);
									Swap(&p[j].jam, &p[j - gap].jam);
									// cout << "\nProses Sort sama dengan : ";
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
int partition (parkir p[],string arr[], int low, int high){
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
				Swap(&p[i].namaKendaraan,&p[j].namaKendaraan);
				Swap(&p[i].plat, &p[j].plat);
				Swap(&p[i].jam, &p[j].jam);
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
							Swap(&p[i].namaKendaraan,&p[j].namaKendaraan);
							Swap(&p[i].plat, &p[j].plat);
							Swap(&p[i].jam, &p[j].jam);
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
	Swap(&p[i + 1].namaKendaraan,&p[high].namaKendaraan);
	Swap(&p[i + 1].plat, &p[high].plat);
	Swap(&p[i + 1].jam, &p[high].jam);
    return (i + 1);
}
void QuickSort(parkir p[],string arr[],int low,int high){
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

void MergeSort(parkir* park[], string* arr, int bottom, int top) {
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
			pTmp[i].jam = park[right]->jam;
			pTmp[i].namaKendaraan = park[right]->namaKendaraan;
			pTmp[i].plat = park[right]->plat;
			right++;
		} else if(right > top) { // If 'right' points beyond the top point (in our case, it's pointing beyond 'A')
			tmp[i] = arr[left];
			pTmp[i].jam = park[left]->jam;
			pTmp[i].namaKendaraan = park[left]->namaKendaraan;
			pTmp[i].plat = park[left]->plat;
			left++;
		} else if(compare(arr[left], arr[right]) > 0) { // If arr[left] > arr[right]
			tmp[i] = arr[right];
			pTmp[i].jam = park[right]->jam;
			pTmp[i].namaKendaraan = park[right]->namaKendaraan;
			pTmp[i].plat = park[right]->plat;
			right++;
		} else { // If arr[left] < arr[right]
			tmp[i] = arr[left];
			pTmp[i].jam = park[left]->jam;
			pTmp[i].namaKendaraan = park[left]->namaKendaraan;
			pTmp[i].plat = park[left]->plat;
			left++;
		}
		i++;
	}
	
	// Once the program enters this part, array 'tmp' is sorted version of array 'arr[bottom to top]'
	// Now, let's put array tmp into 'arr[bottom to top]'
	
	for(int i=0; i<arrCount; i++) {
		arr[i+bottom] = tmp[i];
		park[i + bottom]->jam = pTmp[i].jam;
		park[i + bottom]->namaKendaraan = pTmp[i].namaKendaraan;
		park[i + bottom]->plat = pTmp[i].plat;
	}

	// tampilan proses sort
	for(int k = bottom; k < top; k++){
		cout << arr[k] << " ";
	}
	cout << endl;
}
/*				AKHIR MERGE SORT 				*/

/* 			MENU SORT 			*/
void SortFile(){
	int pil;
	char main;
	int pilihSubjek,sumData;
	parkir p[100];
	string arr[20];
	string namaFile,f;
	f = ".txt";
	ulang_inputNama:
	cout << string(30,'=') << endl;
	cout << "SORTING DATA PARKIR" << endl;
	cout << string(30,'=') << endl;
	cout << "Masukkan Nama File : ";cin >> namaFile;
	namaFile += f;
	sumData = ReadData(p,namaFile);
	if(sumData == -1) goto ulang_inputNama;
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
					arr[i] = p[i].plat;
				}
			}else if(pilihSubjek == 2){
				for(int i = 0; i < sumData; i++){
					arr[i] = p[i].namaKendaraan;
				}	
			}else if(pilihSubjek == 3){
				for(int i = 0; i < sumData; i++){
					arr[i] = p[i].jam;
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
				cout << "\nPROSES SORT: \n";
				MergeSort(&p,arr,0,sumData - 1);
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

void OutputSubData(parkir p[],int dataSama[],int sumData){
	int data;
	for(int i = 0; i < sumData; i++){
		if(dataSama[i] > 0){
			cout << "\nData ke-" << i + 1 << endl;
			cout << "Nama Kendaraan\t: " << p[i].namaKendaraan << endl;
			cout << "Jam Masuk\t: " << p[i].jam << endl;
			cout << "Plat Kendaraan\t: " << p[i].plat << endl; 
		}
	}
	cout << endl;
}
void OutputSubData(parkir p[],int dataSama[],int sumData, int *urutan){
	int data;
	for(int i = 0; i < sumData; i++){
		if(dataSama[i] > 0){
			cout << "\nData ke-" << urutan[i] + 1 << endl;
			cout << "Nama Kendaraan\t: " << p[i].namaKendaraan << endl;
			cout << "Jam Masuk\t: " << p[i].jam << endl;
			cout << "Plat Kendaraan\t: " << p[i].plat << endl;
		}
	}
	cout << endl;
}

int ReadDataBinary(parkir p[],string namaFile){
	ifstream myFile;
	myFile.open(namaFile);
	int sumData = 0;
	if(myFile.is_open()){
		while(getline(myFile,p[sumData]->plat)){
			myFile >> p[sumData]->namaKendaraan;
			myFile >> p[sumData]->jam;
			myFile.ignore(numeric_limits<streamsize>::max(),'\n');
			sumData++;
		}
	}
	return sumData; 
}

parkir BubbleSortNoOutput(parkir p[], string arr[], int sumData, int *urutan) {
    for(int i=0; i<sumData; i++) {
        urutan[i] = i;
    }
    for(int i=0; i<sumData; i++) {
        for(int j=0; j<sumData-i-1; j++) {
            if(compare(arr[j], arr[j+1]) > 0) {
                Swap(&arr[j],&arr[j+1]);
                Swap(&p[j].namaKendaraan,&p[j + 1].namaKendaraan);
                Swap(&p[j].plat, &p[j + 1].plat);
                Swap(&p[j].jam, &p[j + 1].jam);
                Swap(&urutan[j], &urutan[j+1]);
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
void BinarySearchMenu(parkir p[],int sumData,string namaFile){
	char loop;
	do{
		int dataSama[sumData] = {0};
		int opsi;
		string name;
		system("cls");
		cout << "Cari Berdasarkan: \n";
		cout << "1. Nama Kendaraan\n";
		cout << "2. Jam Masuk\n";
		cout << "3. Plat Kendaraan\n";
		cout << "Pilih: "; cin >> opsi;cin.ignore();
		if(opsi == 1){
            int urutan[sumData];
			parkir pSorted = BubbleSortNoOutput(p, p.namaKendaraan, sumData, urutan);

			cout << "Masukkan Nama Kendaraan yang Dicari : ";getline(cin,name);
			int kendaraan = BinarySearch(pSorted.namaKendaraan, name, sumData);
			if (kendaraan == -1) {
				cout << "Nama Kendaraan Tidak Ditemukan\n";
			} else {
				dataSama[kendaraan] = 1;

				for(int i=kendaraan-1; i >= 0; i--) {
					if(pSorted[i].namaKendaraan == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=kendaraan+1; i < sumData; i++) {
					if(pSorted[i].namaKendaraan == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 2){
		    int urutan[sumData];
			parkir pSorted = BubbleSortNoOutput(p, p.jam, sumData, urutan);

			cout << "Masukkan Jam Masuk Kendaraan yang Dicari : ";getline(cin,name);
			int kendaraan = BinarySearch(pSorted.jam, name, sumData);

			if (kendaraan == -1) {
				cout << "Tidak Ada Kendaraan yang Masuk Pada Jam " << name << endl;
			} else {
				dataSama[kendaraan] = 1;
				for(int i=kendaraan-1; i >= 0; i--) {
					if(p[i].jam == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=kendaraan+1; i < sumData; i++) {
					if(p[i].jam == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				OutputSubData(pSorted, dataSama, sumData, urutan);
			}
		}else if(opsi == 3){
		    int urutan[sumData];
			parkir pSorted = BubbleSortNoOutput(p, p.plat, sumData, urutan);

			cout << "Masukkan Plat Kendaraan yang Dicari : ";getline(cin,name);
			int kendaraan = BinarySearch(pSorted.plat, name, sumData);

			if (kendaraan == -1) {
				cout << "Plat Kendaraan Tidak Ditemukan\n";
			} else {
				dataSama[kendaraan] = 1;
				for(int i=kendaraan-1; i >= 0; i--) {
					if(p[i].plat == name) {
						dataSama[i] = 1;
					} else {
						break;
					}
				}
				for(int i=kendaraan+1; i < sumData; i++) {
					if(p[i].plat == name) {
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
void SequentialSearch(parkir p[],int sumData){
	char loop;
	do{
		int dataSama[sumData] = {0};
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
				if(p[i].namaKendaraan == name){
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
				if(p[i].jam == name){
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
				if(p[i].plat == name){
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

void SearchFile(){
	char loop;
		int pil,sumData,index;
		string namaFile,name;
		string arrBinary[20];
		string f = ".txt";
		enum pilihan{SEQUENTIAL = 1, BINARY};
		ulang_inputNama:
		cout << "==========================================\n";
		cout << "CARI DATA KENDARAAN PARKIR\n";
		cout << "==========================================\n";
		cout << "Masukkan Nama File : ";cin >> namaFile;
		namaFile += f;
		sumData = ReadData(dataParkir,namaFile);
		parkir dataParkir[sumData];
		if(sumData == -1) goto ulang_inputNama;
		system("cls");
		do{
			cout << "==========================================\n";
			cout << "CARI DATA KENDARAAN PARKIR\n";
			cout << "==========================================\n";
			cout << "1. Sequential Search\n";
			cout << "2. Binary Search\n";
			cout << "Pilih : ";cin >> pil;
			system("cls");
			switch(pil){
				case SEQUENTIAL:
				SequentialSearch(dataParkir,sumData);
				break;
				case BINARY:
				BinarySearchMenu(dataParkir, sumData,namaFile);
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
/*void Merge(string type){
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
			break;
		}else{
			cout << "Keyword yang Anda SALAH, Silahkan Ketik Ulang!" << endl;
			goto loop;
		}
	}while(loop == "y" || loop == "Y");
}*/
/*				AKHIR MERGE 				*/

/*				MENU TRAKSAKSI 				*/
/*void EditFile(){
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
}*/
/*				AKHIR MENU TRAKSAKSI 				*/

/*====================AKHIR TRANSAKSI====================*/