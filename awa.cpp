#include <iostream>
#include <string.h>

using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;

int main(){
	string nama, jurusan;
	char huruf;
	int nim;
	double kuis, resp, tugas, projek, rt;
	puts("Input Nilai Praktikum =====\n");
	cout << "Nama     : "; getline(cin, nama);
	cout << "NIM      : "; cin >> nim;
	cout << "Kuis     : "; cin >> kuis; 
	cout << "Responsi : "; cin >> resp;
	cout << "Tugas    : "; cin >> tugas;
	cout << "Project  : "; cin >> projek;
	
	puts("\n\nHasil Akhir ==============\n");
	cout << "Nama     : " << nama << endl;
	cout << "NIM      : " << nim << endl;
	switch(nim/1000000){
		case 121 : 
		jurusan = "Teknik Kimia";
		break;
		case 122 : 
		jurusan = "Teknik Industri";
		break;
		case 123 : 
		jurusan = "Informatika";
		break;
		case 124 : 
		jurusan = "Sistem Informasi";
		break;
		default : 
		jurusan = "Gaib";
	}
	
	cout << "Jurusan   : " << jurusan << endl;
	rt = (0.2 * kuis) + (0.35 * resp) + (0.15 * tugas) + (0.3 * projek);
	
	cout << "Rata-rata : " << rt << endl;
	
	if(rt>=80) huruf = 'A';
	else if(rt<80 && rt >=60) huruf = 'B';
	else if(rt<60 && rt >=40) huruf = 'C';
	else if(rt<40 && rt >=20) huruf = 'D';
	else huruf = 'E';
	
	cout<<"Nilai Huruf   : " << huruf <<endl;
	if(huruf > 'B') cout<<"Maaf anda tidak lulus praktikum"<<endl;
	else cout<<"Selamat anda lulus praktikum"<<endl;
}
