#include <iostream>
#include <array>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

struct dvd{
	int no_KTP;
	string nama;
	string judul;
	string id_dvd;
};
dvd d[100];

struct search{
	string nama, judul, id,no;
};
search s[100];

struct sort{
	int ktp[100];
	string name[100];
	string title[100];
	string cid[100];
};
sort urut;

void input(){
	int banyak_data;
	string nama_file;
	ofstream file;
	
	cout << string(23,'=') << endl;
	cout << "INPUT DATA KEPENDUDUKAN" << endl;
	cout << string(23,'=') << endl << endl;
	cout << "Masukkan Nama File\t: "; cin >> nama_file;

	cout << "\nBanyaknya Data = "; cin >> banyak_data;

	cout << "\nSilakan masukkan data peminjaman " << endl;

	if(banyak_data == 1){
		cout << "\tNama Peminjam\t: "; cin.ignore(); getline(cin, d[0].nama);
		cout << "\tNomor KTP\t: "; cin >> d[0].no_KTP;
		cout << "\tJudul DVD\t: "; cin.ignore(); getline(cin, d[0].judul);
		cout << "\tId DVD\t\t: "; getline(cin, d[0].id_dvd);
		cout << endl;
	}else{
		cout << "\tNama Peminjam\t: "; cin.ignore(); getline(cin, d[0].nama);
		cout << "\tNomor KTP\t: "; cin >> d[0].no_KTP;
		cout << "\tJudul DVD\t: "; cin.ignore(); getline(cin, d[0].judul);
		cout << "\tId DVD\t\t: "; getline(cin, d[0].id_dvd);
		cout << endl;

		for(int i = 1; i < banyak_data; i++){
			cout << "\tNama Peminjam\t: "; getline(cin, d[i].nama);
			cout << "\tNomor KTP\t: "; cin >> d[i].no_KTP;
			cout << "\tJudul DVD\t: "; cin.ignore(); getline(cin, d[i].judul);
			cout << "\tId DVD\t\t: "; getline(cin, d[i].id_dvd);
			cout << endl;
		}
	}

	file.open(nama_file, ios::trunc);
	for(int i = 0; i < banyak_data; i++){
		file << d[i].nama << endl;
		file << d[i].no_KTP << endl;
		file << d[i].judul << endl;
		file << d[i].id_dvd << endl;
	}
	file.close();

	cout << "Data telah berhasil terinput!!" << endl << endl;
}

void tampilkan(){
	ifstream file;
	string nama_file, nama, judul, id;
	int no;

	cout << string (19,'=') << endl;
	cout << "DATA PEMINJAMAN DVD"<< endl;
	cout << string (19,'=') << endl << endl;
	cout << "Nama File\t: "; cin >> nama_file;

	cout << endl;
	cout << string(88,'=') << endl;
	cout << "Nama" << setw(30) << "Nomor KTP" << setw(20) << "Judul DVD" << setw(18) << "Id DVD" << endl;
	cout << string(88,'=') << endl;
	
	file.open(nama_file);
	while(getline(file,nama)){
		file >> no;
		file.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(file,judul);
		file >> id;
		file.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << nama << setw(19) << no << setw(25) << judul << setw(12) << id << endl;
	}
	cout << string(88,'=') << endl;
}

int binsrch(search s[], string x, int o, int n){
    int awal = 0 ;
    int akhir = n - 1;

    if(o == 1){
	    while(awal <= akhir){
	        int tengah = awal + (akhir - awal) / 2;

	        if(x == s[tengah].nama){
	            return tengah;
	        }

	        if(x > s[tengah].nama){
	            awal = tengah + 1;
	        }else if(x < s[tengah].nama){
	            akhir = tengah - 1;
	        }
	    }
    return -1;
    }else if(o == 2){
	    while(awal <= akhir){
	        int tengah = awal + (akhir - awal) / 2;

	        if(x == s[tengah].no){
	            return tengah;
	        }

	        if(x > s[tengah].no){
	            awal = tengah + 1;
	        }else if(x < s[tengah].no){
	            akhir = tengah - 1;
	        }
	    }
    return -1;
    }else if(o == 3){
	    while(awal <= akhir){
	        int tengah = awal + (akhir - awal) / 2;

	        if(x == s[tengah].judul){
	            return tengah;
	        }

	        if(x > s[tengah].judul){
	            awal = tengah + 1;
	        }else if(x < s[tengah].judul){
	            akhir = tengah - 1;
	        }
	    }
    return -1;
    }else if(o == 4){
	    while(awal <= akhir){
	        int tengah = awal + (akhir - awal) / 2;

	        if(x == s[tengah].id){
	            return tengah;
	        }

	        if(x > s[tengah].id){
	            awal = tengah + 1;
	        }else if(x < s[tengah].id){
	            akhir = tengah - 1;
	        }
	    }
    return -1;
    }else{
    	return -1;
	}
}

void srchbin(){
	int pilihan, i = 0, hasil;
	char opsi;
	bool ketemu;
	string nama_file, nama, cari;
	ifstream file;
	
	do{
		cout << "Masukkan nama file : "; cin >> nama_file;

		cout << "Cari berdasarkan : " << endl;
		cout << "\t1. Nama" << endl;
		cout << "\t2. No KTP" << endl;
		cout << "\t3. Judul DVD" << endl;
		cout << "\t4. Id DVD" << endl << endl;

		cout << "Masukkan Pilihan : "; cin >> pilihan;

		file.open(nama_file);
		while(getline(file,s[i].nama)){
			file.clear();
			file >> s[i].no;
			file.ignore(numeric_limits<streamsize>::max(),'\n'); 
			getline(file,s[i].judul);
			file >> s[i].id;
			file.ignore(numeric_limits<streamsize>::max(),'\n');
			i++;
		}

		switch(pilihan){
			case 1 :
				system("cls");
				cout << "=====" << endl;
				cout << "NAMA" << endl;
				cout << "=====" << endl << endl;
				cout << "Masukkan pencarian  : "; getline(cin,cari);
				hasil = binsrch(s,cari,1,i);

				if(hasil == -1){
					cout << "Tidak ditemukan!" << endl;
				}else{
					system("cls");
					cout << "Informasi DVD :" << endl << endl;
					cout << "\tNama \t: " << s[hasil].nama << endl;
					cout << "\tNo KTP \t: " << s[hasil].no << endl;
					cout << "\tJudul \t: " << s[hasil].judul << endl;
					cout << "\tId DVD \t: " << s[hasil].id << endl;
				}

				cout << "\ny = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 2 :
				system("cls");
				cout << "======" << endl;
				cout << "NO KTP" << endl;
				cout << "======" << endl << endl;
				cout << "Masukkan pencarian  : "; getline(cin,cari);
				hasil = binsrch(s,cari,2,i);

				if(hasil == -1){
					cout << "Tidak ditemukan!" << endl;
				}else{
					system("cls");
					cout << "Informasi DVD :" << endl << endl;
					cout << "\tNama \t: " << s[hasil].nama << endl;
					cout << "\tNo KTP \t: " << s[hasil].no << endl;
					cout << "\tJudul \t: " << s[hasil].judul << endl;
					cout << "\tId DVD \t: " << s[hasil].id << endl;
				}

				cout << "\ny = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 3 :
				system("cls");
				cout << "=====" << endl;
				cout << "JUDUL" << endl;
				cout << "=====" << endl << endl;
				cout << "Masukkan pencarian  : "; getline(cin,cari);
				hasil = binsrch(s,cari,3,i);

				if(hasil == -1){
					cout << "Tidak ditemukan!" << endl;
				}else{
					system("cls");
					cout << "Informasi DVD :" << endl << endl;
					cout << "\tNama \t: " << s[hasil].nama << endl;
					cout << "\tNo KTP \t: " << s[hasil].no << endl;
					cout << "\tJudul \t: " << s[hasil].judul << endl;
					cout << "\tId DVD \t: " << s[hasil].id << endl;
				}

				cout << "\ny = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 4 :
				system("cls");
				cout << "======" << endl;
				cout << "ID DVD" << endl;
				cout << "======" << endl << endl;
				cout << "Masukkan pencarian  : "; getline(cin,cari);
				hasil = binsrch(s,cari,4,i);

				if(hasil == -1){
					cout << "Tidak ditemukan!" << endl;
				}else{
					system("cls");
					cout << "Informasi DVD :" << endl << endl;
					cout << "\tNama \t: " << s[hasil].nama << endl;
					cout << "\tNo KTP \t: " << s[hasil].no << endl;
					cout << "\tJudul \t: " << s[hasil].judul << endl;
					cout << "\tId DVD \t: " << s[hasil].id << endl;
				}

				cout << "\ny = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			default :
				system("cls");
				cout << "======" << endl;
				cout << "SALAH!" << endl;
				cout << "======" << endl << endl;
				cout << "\nSalah Input!!!" << endl;
				cout << "\ny = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
		}	
	}while(opsi == 'y' || opsi == 'Y');
}

void seqsrch(search s[], int x, int n){
	int i = 0;
	bool ketemu = false;
	string temp;

	cout << "Masukkan pencarian  : "; getline(cin,temp);

	if(x == 1){
		while((!ketemu) && (i < n)){
			if(temp == s[i].nama){
				ketemu = true;
			}else{
				i++;
			}
		}
	}else if(x == 2){
		while((!ketemu) && (i < n)){
			if(temp == s[i].no){
				ketemu = true;
			}else{
				i++;
			}
		}
	}else if(x == 3){
		while((!ketemu) && (i < n)){
			if(temp == s[i].judul){
				ketemu = true;
			}else{
				i++;
			}
		}
	}else if(x == 4){
		while((!ketemu) && (i < n)){
			if(temp == s[i].id){
				ketemu = true;
			}else{
				i++;
			}
		}
	}

	if(ketemu){
		system("cls");
		cout << "Informasi DVD :" << endl << endl;
		cout << "\tNama \t: " << s[i].nama << endl;
		cout << "\tNo KTP \t: " << s[i].no << endl;
		cout << "\tJudul \t: " << s[i].judul << endl;
		cout << "\tId DVD \t: " << s[i].id << endl;
	}else{
		cout << "Tidak ada DVD ditemukan" << endl;
	}
}


/*				SEQUENTIAL METHOD 				*/
void srchseq(){
	search s[100];
	int pilihan, i = 0, x;
	char opsi;
	bool ketemu;
	string nama_file;
	ifstream file;
	
	cout << "Masukkan nama file : "; cin >> nama_file;

	system("cls");

	cout << string(19,'=') << endl;
	cout << "Cari berdasarkan : " << endl;
	cout << "\t1. Nama" << endl;
	cout << "\t2. No KTP" << endl;
	cout << "\t3. Judul DVD" << endl;
	cout << "\t4. Id DVD" << endl;
	cout << string(19,'=') << endl << endl;

	cout << "Masukkan Pilihan Opsi: "; cin >> pilihan;

	file.open(nama_file);
	if(file.is_open()){
		while(getline(file,s[i].nama)){
			cout << "baca " << i << endl;
			cout << s[i].nama << endl;
			file >> s[i].no;
			cout << s[i].no << endl;
			file.ignore(numeric_limits<streamsize>::max(),'\n'); 
			getline(file,s[i].judul);
			cout << s[i].judul << endl;
			file >> s[i].id;
			cout << s[i].id << endl;
			file.ignore(numeric_limits<streamsize>::max(),'\n');
			i++;
		}
		for(int a = 0; a < i; a++){
		cout << "masuk looping baca\n";
			cout << s[i].nama << endl;
			cout << s[i].no << endl;
			cout << s[i].judul << endl;
		}

		system("pause");
		switch(pilihan){
			case 1 :
				system("cls");
				cout << string(4,'=') << endl;
				cout << "NAMA" << endl;
				cout << string(4,'=') << endl << endl;
				seqsrch(s,1,i);
				system("cls");
				break;
			case 2 :
				system("cls");
				cout << string(6,'=') << endl;
				cout << "NO KTP" << endl;
				cout << string(6,'=') << endl << endl;
				seqsrch(s,2,i);
				system("cls");
				break;
			case 3 :
				system("cls");
				cout << string(5,'=') << endl;
				cout << "JUDUL" << endl;
				cout << string(5,'=') << endl << endl;
				seqsrch(s,3,i);
				system("cls");
				break;
			case 4 :
				system("cls");
				cout << string(6,'=') << endl;
				cout << "ID DVD" << endl;
				cout << string(6,'=') << endl << endl;
				seqsrch(s,4,i);
				system("cls");
				break;
			default :
				system("cls");
				cout << string(6,'=') << endl;
				cout << "SALAH!" << endl;
				cout << string(6,'=') << endl << endl;
				cout << "\nSalah Input!!!" << endl;
				system("cls");
				break;
		}	
	}else{
		cout << "Nama File yang Anda Masukkan Tidak Ditemukan!" << endl;
	}

}
/*				AKHIR SEQUENTIAL METHOD 				*/


/*				SEARCH MENU 				*/
void searching(){
	int opsi;
	search s;
	cout << string(25,'=') << endl;
	cout << "CARI DATA DVD" << endl;
	cout << string(25,'=') << endl;
	cout << "\t1. Sequential" << endl;
	cout << "\t2. Binary" << endl;
	cout << string(25,'=') << endl << endl;

	cout << "Masukkan Pilihan : "; cin >> opsi;

	switch(opsi){
		case 1 :
			system("cls");
			srchseq(s);
			system("cls");
			break;
		case 2 :
			system("cls");
			srchbin();
			system("cls");
			break;
		default :
			cout << "Input yang anda masukkan salah!" << endl;
			break;
	}
}

void tukarint(int *ktp1, int *ktp2){
	int temp;

	temp = *ktp1;
	*ktp1 = *ktp2;
	*ktp2 = temp;
}

void tukarstr(string *nama1, string *nama2){
	string temp1;

	temp1 = *nama1;
	*nama1 = *nama2;
	*nama2 = temp1;
}


void klasifikasi(int z, sort &urut, int pi, string tampung_string[], int tampung_int[]){
	if(pi == 1){
		for(int i=0; i<z; i++){
			tampung_string[i] = urut.name[i];
		}
	}
	else if(pi ==2){
		for(int i=0; i<z; i++){
			tampung_int[i] = urut.ktp[i];
		}
	}
	else if(pi == 3){
		for(int i=0; i<z; i++){
			tampung_string[i] = urut.title[i];
		}
	}else if(pi == 4){
		for(int i=0; i<z; i++){
			tampung_string[i] = urut.cid[i];
		}
	}
}

void tampilsorting(int z, sort urut){
	fstream file;
	string nama_file;

	cout << "Simpan hasil pengurutan\t: "; cin >> nama_file;
	cout << string(88,'=') << endl;
	cout << "Nama" << setw(30) << "Nomor KTP" << setw(20) << "Judul DVD" << setw(18) << "Id DVD" << endl;
	cout << string(88,'=') << endl;
	
	file.open(nama_file,ios::trunc);
	file.close();
	for(int i=0; i<z; i++){
		file.open(nama_file,ios::app);
		file << urut.name[i] << endl;
		file << urut.ktp[i] << endl;
		file << urut.title[i] << endl;
		file << urut.cid[i] << endl;
		cout << urut.name[i] << setw(24) << urut.ktp[i] << setw(25) << urut.title[i] << setw(20) << urut.cid[i] << endl;
		file.close();
	}
}

void bubblestring(int z, sort &urut, string tampung_string[]){
	int temp;
	string temp1, temp2, temp3;

	for(int i = 0; i < z-1; i++) {
		for(int j = 0; j<z-1-i; j++){
			if(tampung_string[j+1] < tampung_string[j]) {
				tukarstr(&urut.name[j+1], &urut.name[j]);
				tukarstr(&tampung_string[j+1], &tampung_string[j]);
				tukarint(&urut.ktp[j+1], &urut.ktp[j]);
				tukarstr(&urut.title[j+1], &urut.title[j]);
				tukarstr(&tampung_string[j+1], &tampung_string[j]);
				tukarstr(&urut.cid[j+1], &urut.cid[j]);
				tukarstr(&tampung_string[j+1], &tampung_string[j]);
			}
		}
	}	
}

void bubbleint(int z, sort &urut, int tampung_int[]) {
	int temp;
	string temp1, temp2, temp3;

	for(int i = 0; i < z-1; i++) {
		for(int j = 0; j<z-1-i; j++){
			if(tampung_int[j+1] < tampung_int[j]) {
				tukarstr(&urut.name[j+1], &urut.name[j]);
				tukarint(&urut.ktp[j+1], &urut.ktp[j]);
				tukarint(&tampung_int[j+1], &tampung_int[j]);
				tukarstr(&urut.title[j+1], &urut.title[j]);
				tukarstr(&urut.cid[j+1], &urut.cid[j]);
			}
		}
	}	
}


void insertionstring(int z, sort &urut, string tampung_string[]){
	int temp,i,j;
	string temp1, temp2, temp3;

	for(i = 0; i < z; i++) {
		temp1 = urut.name[i];
		temp = urut.ktp[i];
		temp2 = urut.title[i];
		temp3 = urut.cid[i];
		j = i-1; 
		while(temp1 < tampung_string[j] && (j >= 0)){
			tukarstr(&urut.name[j+1], &urut.name[j]);
			tukarstr(&tampung_string[j+1], &tampung_string[j]);
			tukarint(&urut.ktp[j+1], &urut.ktp[j]);
			tukarstr(&urut.title[j+1], &urut.title[j]);
			tukarstr(&tampung_string[j+1], &tampung_string[j]);
			tukarstr(&urut.cid[j+1], &urut.cid[j]);
			tukarstr(&tampung_string[j+1], &tampung_string[j]);
			j--;
		}
	}
	
}

void insertionint(int z, sort &urut, int tampung_int[]) {
	int temp,i,j;
	string temp1, temp2, temp3;

	for(i = 0; i < z; i++) {
		temp1 = urut.name[i];
		temp = urut.ktp[i];
		temp2 = urut.title[i];
		temp3 = urut.cid[i];
		j = i-1; 
		while(temp < tampung_int[j] && (j >= 0)){
			tukarstr(&urut.name[j+1], &urut.name[j]);
			tukarint(&urut.ktp[j+1], &urut.ktp[j]);
			tukarint(&tampung_int[j+1], &tampung_int[j]);
			tukarstr(&urut.title[j+1], &urut.title[j]);
			tukarstr(&urut.cid[j+1], &urut.cid[j]);
			j--;
		}
	}
	
}

void selectionstring(int z, sort &urut, string tampung_string[]){
	int i, j, k;

	for(i = 0; i < z; i++){
		int k = i;
		for(j = i + 1; j < z; j++){
			if(tampung_string[k] > tampung_string[j]){
				k = j;
			}
		}
		tukarstr(&urut.name[j+1], &urut.name[j]);
		tukarstr(&tampung_string[j+1], &tampung_string[j]);
		tukarint(&urut.ktp[j+1], &urut.ktp[j]);
		tukarstr(&urut.title[j+1], &urut.title[j]);
		tukarstr(&tampung_string[j+1], &tampung_string[j]);
		tukarstr(&urut.cid[j+1], &urut.cid[j]);
		tukarstr(&tampung_string[j+1], &tampung_string[j]);
	}
}

void selectionint(int z, sort &urut, int tampung_int[]){
	int i, j, k;

	for(i = 0; i < z; i++){
		int k = i;
		for(j = i + 1; j < z; j++){
			if(tampung_int[k] > tampung_int[j]){
				k = j;
			}
		}
		tukarstr(&urut.name[j+1], &urut.name[j]);
		tukarint(&urut.ktp[j+1], &urut.ktp[j]);
		tukarint(&tampung_int[j+1], &tampung_int[j]);
		tukarstr(&urut.title[j+1], &urut.title[j]);
		tukarstr(&urut.cid[j+1], &urut.cid[j]);
	}
}

void shellsortstring(int z, sort &urut, string tampung_string[]){
	string temp1,temp2,temp3;
	int temp;

	for(int gap = z/2; gap > 0; gap /= 2) {
	    for(int i = gap; i < z; i += 1) {
	        temp1 = urut.name[i];
			temp = urut.ktp[i];
			temp2 = urut.title[i];
			temp3 = urut.cid[i];		 
	        int j;           
	        for(j = i; j >= gap && tampung_string[j - gap] > temp1; j -= gap){
	        	tampung_string[j] = tampung_string[j - gap];
	            tukarstr(&urut.name[j], &urut.name[j-gap]);
				tukarstr(&tampung_string[j], &tampung_string[j-gap]);
				tukarint(&urut.ktp[j], &urut.ktp[j-gap]);
				tukarstr(&urut.title[j], &urut.title[j-gap]);
				tukarstr(&tampung_string[j], &tampung_string[j-gap]);
				tukarstr(&urut.cid[j], &urut.cid[j-gap]);
				tukarstr(&tampung_string[j], &tampung_string[j-gap]);    
	        }
	    }
	}
}

void shellsortint(int z, sort &urut, int tampung_int[]){
	string temp1,temp2,temp3;
	int temp;

	for(int gap = z/2; gap > 0; gap /= 2) {
	    for(int i = gap; i < z; i += 1) {
	        temp1 = urut.name[i];
			temp = urut.ktp[i];
			temp2 = urut.title[i];
			temp3 = urut.cid[i];		 
	        int j;           
	        for(j = i; j >= gap && tampung_int[j - gap] > temp; j -= gap){
	        	tampung_int[j] = tampung_int[j - gap];
	            tukarstr(&urut.name[j], &urut.name[j-gap]);
				tukarint(&urut.ktp[j], &urut.ktp[j-gap]);
				tukarint(&tampung_int[j], &tampung_int[j-gap]);
				tukarstr(&urut.title[j], &urut.title[j-gap]);
				tukarstr(&urut.cid[j], &urut.cid[j-gap]);  
	        }
	    }
	}
}

int partition(int z, sort &urut, int low, int high){
	string pivot = urut.name[high];
    int pivot1 = urut.ktp[high];
    string pivot2 = urut.title[high];
    string pivot3 = urut.cid[high];
    int i = (low - 1); 

    for(int j = low; j <= high - 1; j++)
    {
        if(urut.name[j] < pivot)
        {
            i++; // increment index of smaller element
            tukarstr(&urut.name[i], &urut.name[j]);
            tukarint(&urut.ktp[i], &urut.ktp[j]);
            tukarstr(&urut.title[i], &urut.title[j]);
            tukarstr(&urut.cid[i], &urut.cid[j]);
        }
    }
    tukarstr(&urut.name[i + 1], &urut.name[high]);
    tukarint(&urut.ktp[i+1], &urut.ktp[high]);
    tukarstr(&urut.title[i+1], &urut.title[high]);
    tukarstr(&urut.cid[i+1], &urut.cid[high]);
    return (i + 1);
}

void quicksort(int z, sort &urut, int low, int high){
	if(low < high) {
	    int pi = partition(z,urut, low, high);
	     
	    quicksort(z,urut, low, pi - 1);
	    quicksort(z,urut, pi + 1, high);
	}
}

void sorting(sort &urut){
	fstream file;
	string nama_file;
	int pilih, pi;
	int z = 0;
	string tampung_string[100];
	int tampung_int[100];
	
	cout << string(26,'=') << endl;
	cout << " METODE SORTING" << endl;
	cout << string(26,'=') << endl;
	cout << "1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Shell Sort\n5. Quick Sort\n6. Merge Sort" << endl;
	cout << string(26,'=') << endl;
	cout << "Pilih : "; cin >> pilih;

	cout << "Nama File\t: "; cin >> nama_file;

	file.open(nama_file);

	if(file.is_open()){
		while(getline(file,urut.name[z])){
			file >> urut.ktp[z];
			file.ignore(numeric_limits<streamsize>::max(),'\n'); 
			getline(file,urut.title[z]);
			file >> urut.cid[z];
			file.ignore(numeric_limits<streamsize>::max(),'\n');
			z++;
		}

		system("cls");

		switch(pilih) {
			case 1:
				cout << string(26,'=') << endl;
				cout << " PENGURUTAN DATA BUBBLE" << endl;
				cout << string(26,'=') << endl;
				cout << "\t1. Nama\n\t2. Nomor KTP\n\t3. Judul DVD\n\t4. ID DVD" << endl;
				cout << string(26,'=') << endl;
				cout << "Pilih : "; cin >> pi;
				klasifikasi(z,urut,pi,tampung_string,tampung_int);
				system("cls");
				switch(pi){
					case 1:
						bubblestring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
					case 2:
						bubbleint(z,urut,tampung_int);
						tampilsorting(z,urut);
						break;
					case 3:
						bubblestring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
					case 4:
						bubblestring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
				}
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "==========================" << endl;
				cout << " PENGURUTAN DATA INSERTION" << endl;
				cout << "==========================" << endl;
				cout << "\t1. Nama\n\t2. Nomor KTP\n\t3. Judul DVD\n\t4. ID DVD" << endl;
				cout << "==========================" << endl;
				cout << "Pilih : "; cin >> pi;
				klasifikasi(z,urut,pi,tampung_string,tampung_int);
				system("cls");
				switch(pi){
					case 1:
						insertionstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
					case 2:
						insertionint(z,urut,tampung_int);
						tampilsorting(z,urut);
						break;
					case 3:
						insertionstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
					case 4:
						insertionstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
				}
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "==========================" << endl;
				cout << " PENGURUTAN DATA SELECTION" << endl;
				cout << "==========================" << endl;
				cout << "\t1. Nama\n\t2. Nomor KTP\n\t3. Judul DVD\n\t4. ID DVD" << endl;
				cout << "==========================" << endl;
				cout << "Pilih : "; cin >> pi;
				klasifikasi(z,urut,pi,tampung_string,tampung_int);
				system("cls");
				switch(pi){
					case 1:
						selectionstring(z,urut,tampung_string);
						tampilsorting(z,urut);					
						break;
					case 2:
						selectionint(z,urut,tampung_int);
						tampilsorting(z,urut);
						break;
					case 3:
						selectionstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
					case 4:
						selectionstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
				}
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "==========================" << endl;
				cout << " PENGURUTAN DATA SHELLSORT" << endl;
				cout << "==========================" << endl;
				cout << "\t1. Nama\n\t2. Nomor KTP\n\t3. Judul DVD\n\t4. ID DVD" << endl;
				cout << "==========================" << endl;
				cout << "Pilih : "; cin >> pi;
				klasifikasi(z,urut,pi,tampung_string,tampung_int);
				system("cls");
				switch(pi){
					case 1:
						shellsortstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
					case 2:
						shellsortint(z,urut,tampung_int);
						tampilsorting(z,urut);
						break;
					case 3:
						shellsortstring(z,urut,tampung_string);
						tampilsorting(z,urut);
					case 4:
						shellsortstring(z,urut,tampung_string);
						tampilsorting(z,urut);
						break;
				}
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "===========================" << endl;
				cout << " PENGURUTAN DATA QUICK-SORT" << endl;
				cout << "===========================" << endl;
				cout << "\t1. Nama\n\t2. Nomor KTP\n\t3. Judul DVD\n\t4. ID DVD" << endl;
				cout << "==========================" << endl;
				cout << "Pilih : "; cin >> pi;
				// klasifikasi(z,urut,pi,tampung_string,tampung_int);
				switch(pi){
					case 1:
						quicksort(z,urut,0,z-1);
						tampilsorting(z,urut);
						break;
					case 2:
						quicksort(z,urut,0,z-1);
						tampilsorting(z,urut);
						break;
					case 3:
						quicksort(z,urut,0,z-1);
						tampilsorting(z,urut);
						break;
					case 4:
						quicksort(z,urut,0,z-1);
						tampilsorting(z,urut);
						break;
				}
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "===========================" << endl;
				cout << " PENGURUTAN DATA MERGE-SORT" << endl;
				cout << "===========================" << endl;
				cout << "\t1. Nama\n\t2. Nomor KTP\n\t3. Judul DVD\n\t4. ID DVD" << endl;
				cout << "==========================" << endl;
				cout << "Pilih : "; cin >> pi;
				klasifikasi(z,urut,pi,tampung_string,tampung_int);
				system("cls");
				break;
		}
	}else{
		cout << "File tidak ditemukan!" << endl;
	}

}

void transaksi(){
	cout << "belum gayn hehe" << endl;
}


/*				MAIN MENU 				*/
int main(){
	char opsi;
	int pilihan;

	do{
		cout << string(23,'=') << endl;
		cout << "TUGAS PROJECT ALGO 2021" << endl;
		cout << string(23,'=') << endl;
		cout << "\t1. INPUT DATA" << endl;
		cout << "\t2. TAMPILKAN DATA" << endl;
		cout << "\t3. SEARCHING DATA" << endl;
		cout << "\t4. SORTING DATA" << endl;
		cout << "\t5. TRANSAKSI" << endl;
		cout << "\t6. KELUAR" << endl;
		cout << string(23,'=') << endl;
		cout << string(23,'=') << endl << endl;

		cout << "Masukkan Pilihan Menu\t: "; cin >> pilihan;

		switch(pilihan){
			case 1 : 
				system("cls");
				input();
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 2 :
				system("cls");
				tampilkan();
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 3 :
				system("cls");
				searching();
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				break;
			case 4 :
				system("cls");
				sorting(urut);
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 5 :
				system("cls");
				transaksi();
				system("cls");
				break;
			case 6 :
				exit(1);
			default :
				cout << "Periksa kembali pilihan yang anda masukkan!" << endl;
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				break;
		}
	}while(opsi == 'y' || opsi == 'Y');

	system("pause");
	return 0;
}
/*				AKHIR MAIN MENU 				*/