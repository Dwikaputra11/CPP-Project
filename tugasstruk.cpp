#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	int jbarang1, jbarang2, jbarang3;
	int hbarang1, hbarang2, hbarang3;

	

	string nbarang1, nbarang2, nbarang3;

	int total; 


	cout << "PROGRAM SOAL NO 2" << endl;
	cout << "NIM 	: 123200112" << endl; 
	cout << "Nama 	: I Made Dwika Putra Riswanda" << endl; 

	cout << endl ;

	cout << "------------------------------------------" << endl;
	cout << endl;
	cout << "INPUT PEMBELIAN	:" << endl;
	cout << endl; 

	//barang 1
	cout << "Nama Barang 1	:"; getline(cin,nbarang1); 
	cout << "Jumlah Barang 1	:"; cin >> jbarang1;
	cout << "Harga Barang 1	:"; cin >> hbarang1; cin.ignore();

	cout << endl;

	//barang 2
	cout << "Nama Barang 2	:"; getline(cin,nbarang2); 
	cout << "Jumlah Barang 2	:"; cin >> jbarang2;
	cout << "Harga Barang 2	:"; cin >> hbarang2; cin.ignore();

	cout << endl;

	//barang 3
	cout << "Nama Barang 3	:"; getline(cin,nbarang3); 
	cout << "Jumlah Barang 3	:"; cin >> jbarang3;
	cout << "Harga Barang 3	:"; cin >> hbarang3; 

	cout << endl;
	cout << "PEMBAYARAN	:" << endl;
	cout << "------------------------------------------" << endl;
	cout << "No" << setw(19) << "Nama Barang" << setw(20) << "Jumlah Barang" << endl;
	cout << "1" << setw(20) << nbarang1 << setw(15) << jbarang1 << endl;
	cout << "2" << setw(20) << nbarang2 << setw(15) << jbarang2 << endl;
	cout << "3" << setw(20) << nbarang3 << setw(15) << jbarang3 << endl;

	cout << "------------------------------------------" << endl;
	total = hbarang1*jbarang1 + hbarang2*jbarang2 + hbarang3*jbarang3 ;
	
	cout << "Total harga" << " = " << "Rp" << total;
	cout << endl;

	cin.get();
	cin.get();
	return 0;
}
