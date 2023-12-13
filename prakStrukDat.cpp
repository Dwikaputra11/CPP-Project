#include <iostream>
#include <string>

using namespace std;

typedef struct typenode *typeptr;
typedef int typeinfo;

struct typenode{
	typeinfo info;
	typeptr next;
};
typeptr awal, akhir;

void buatListBaru();
void sisiNode(typeinfo infoBaru);
void hapusNode(typeinfo infoNode);
void bacaMaju();
void bacaMundur();

int main()
{
	int pil;
	int angka; 

	enum{NEW = 1, DELETE,FORWARD, BACKWARD};
	string loop;

	do{
		cout <<"\n" << string(30,'-') << "\n";	
		cout << string(6,'-') << " MENU LINKED LIST " << string(6,'-') << "\n";
		cout << string(30,'-') << "\n";
		cout << "1. Menu Sisip Node Baru\n";
		cout << "2. Menu Hapus Node\n";
		cout << "3. Menu Baca Maju\n";
		cout << "4. Menu Baca Mundur\n"; 
		cout << "Pilih : ";cin >> pil;

		switch(pil){
			case NEW:{
				int jum; 
				buatListBaru();
				cout << "Menu Input Node\n";
				cout << "Masukkan Jumlah Sisip Node : "; cin >> jum;
				int i = 1;
				while(jum--){
					cout << "Sisip Nilai Ke-" << i++ << " = "; cin >> angka;
					sisiNode(angka);
				}
				cout <<"\n" +  string(30,'-') + "\n";
				cout << "\nNode Berhasil Diinput!\n";
			}
			break;
			case DELETE:
			cout << "Menu Hapus Node\n";
			cout << "Input Nilai Node Yang Akan Dihapus : "; cin >> angka;
			hapusNode(angka);
			break;
			case FORWARD:
			cout << "Menu Baca Maju\n";
			bacaMaju();
			break;
			case BACKWARD:
			cout << "Menu Baca Maju\n";
			bacaMundur();
			break;

		}
		cout <<"\n" +  string(30,'-') + "\n";
		cout << "Kembali ke menu ? (y/t) : "; cin >> loop;
	}while(loop == "y");


	return 0;
}

void buatListBaru(){
	int first = -999999,last = 999999;
	awal = (typenode*)malloc(sizeof(typenode));
	akhir = (typenode*)malloc(sizeof(typenode));
	awal -> info = first;
	akhir -> info = last;
	awal -> next = akhir;
	akhir -> next = NULL;
}

void sisiNode(typeinfo infoBaru){
	typeptr nodeBaru,bantu;
	nodeBaru = (typenode*)malloc(sizeof(typenode));
	nodeBaru->info = infoBaru;
	bantu = awal;
	while(infoBaru > bantu->next->info){
		bantu = bantu->next;
	}
	nodeBaru->next = bantu->next;
	bantu->next = nodeBaru;	
}

void hapusNode(typeinfo infoNode){
	typeptr hapus,bantu;
	hapus = (typenode*)malloc(sizeof(typenode));
	hapus->info = infoNode;

	if(awal == NULL){
		cout <<"\n" +  string(30,'-') + "\n";
		cout << "\nList Masih Kosong\n";
	}else if(awal->next->info == infoNode){
		hapus = awal->next;
		awal -> next = hapus->next;
		free(hapus); 
	}else{
		bantu = awal->next;
		while((bantu->next->info != infoNode) && (bantu->next != akhir)){
			bantu = bantu->next;
		}
		hapus = bantu->next;
		if(hapus == akhir){
			cout <<"\n" +  string(30,'-') + "\n";
			cout << "\nNode Tidak Ditemukan...\n";
		}
		else if(hapus->next == akhir){
			bantu->next = akhir;
			cout <<"\n" +  string(30,'-') + "\n";
			cout << "\nNode " << infoNode << " Berhasil Dihapus dari List\n";
		}else{
			bantu->next = hapus->next;
			cout <<"\n" +  string(30,'-') + "\n";
			cout << "\nNode " << infoNode << " Berhasil Dihapus dari List\n";	
		}
		free(hapus);
	}
}

void bacaMaju(){
	typeptr bantu;
	bantu = awal->next;

	while(bantu -> next != NULL){
		cout << " " << bantu -> info;
		bantu = bantu -> next;
	}
}
void bacaMundur(){
	typeptr bantu, ekor;
	ekor = awal;
	awal = akhir;

	do{
		bantu = ekor;
		while(bantu->next != akhir){
			bantu = bantu->next;
		}
		akhir->next = bantu;
		akhir = bantu;
	}while(akhir != ekor);
	akhir->next = NULL;
	bantu = awal;
	bacaMaju();
}
