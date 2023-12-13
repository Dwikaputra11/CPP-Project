#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct data{
	string nama[20];
	int kelas[20];
};
data d;

void tukarstring(string *e, string *f);
void tukarint(int *x, int *y);
void bubble(int a, data &d);
void bubble2(int a, data &d);

int main()
{
	data d;
	// ofstream myfile;
	int a,pilih1;

	// myfile.open("tes1.txt",ios::trunc);
	// myfile.close();
	cout << "input banyak data : "; cin >> a;
	cin.ignore();
	for(int i=0; i < a; i++) {
		cout << "nama : "; getline(cin, d.nama[i]);
		cout << "Kelas : "; cin >> d.kelas[i];
		cin.ignore();
		// myfile.open("tes1.txt",ios::app);
		// myfile << d[i].nama << "\n";
		// myfile << d[i].kelas << "\n";
		// myfile.close();
	}
	cout << "urutkan data dari:\n1. Nama\n2. Kelas " << endl;
	cout << "pilih : "; cin >> pilih1;
	switch(pilih1) {
		case 1:
			bubble(a,d);
			cout << "alphabetical :" << endl;
			for(int i=0; i<a; i++) {
				cout << "nama : " << d.nama[i] << endl;
				cout << "kelas : " << d.kelas[i] << endl;
			}
			break;
		case 2:
			bubble2(a,d);
			for(int i=0; i<a; i++) {
				cout << "nama : " << d.nama[i] << endl;
				cout << "kelas : " << d.kelas[i] << endl;
			}
			break;
	}
	cin.get();
	return 0;
}

void tukarstring(string *e, string *f){
	string temp;
	temp = *e;
	*e = *f;
	*f = temp;
}

void tukarint(int *x, int *y){
	int temp1;
	temp1 = *x;
	*x = *y;
	*y = temp1;
}

void bubble(int a, data &d){
	string temp;
	int temp1;
	for(int i = 0; i < a - 1; i++) {
		for(int j = 0; j<a - i - 1; j++){
			if(d.nama[j + 1] < d.nama[j]) {
				tukarstring(&d.nama[j + 1], &d.nama[j]);
				tukarint(&d.kelas[j + 1], &d.kelas[j]);
				// temp=d[i].nama;
				// d[i].nama=d[j].nama;
				// d[j].nama=temp;
				// temp1=d[i].kelas;
				// d[i].kelas=d[j].kelas;
				// d[j].kelas=temp1;
			}
		}
	}
}

void bubble2(int a, data &d){
	string temp;
	int temp1;
	for(int i = 0; i < a - 1; i++) {
		for(int j = 0; j<a - i - 1; j++){
			if(d.kelas[j + 1] < d.kelas[j]) {
				tukarstring(&d.nama[j + 1], &d.nama[j]);
				tukarint(&d.kelas[j + 1], &d.kelas[j]);
				/*temp1=d[i].kelas;
				d[i].kelas=d[j].kelas;
				d[j].kelas=temp1;
				temp=d[i].nama;
				d[i].nama=d[j].nama;
				d[j].nama=temp;*/
			}
		}
	}
}