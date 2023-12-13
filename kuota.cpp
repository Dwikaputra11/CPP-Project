#include <iostream>
using namespace std;


int main()
{	
	string instansi;
	int siswa, pengajar;
	int ksiswa, kpengajar;
	int total;

	cout << "---Kuota KEMENDIKBUD---" << endl;
	cout << endl;

	cout << "Intansi (PAUD, SD, SMP, SMA, Universitas): ";
	cin >> instansi;

	//Conditional / ternary operator
	ksiswa = (instansi == "PAUD")? 20 : 0;
	ksiswa = (instansi == "SD")? 35 : 0;
	ksiswa = (instansi == "SMP")? 35 : 0;
	ksiswa = (instansi == "SMA")? 35 : 0;
	ksiswa = (instansi == "Universitas")? 50 : 0;
	

	cout << "Jumlah pengajar \t: ";
	cin >> pengajar;
	//Conditional / ternary operator
	kpengajar = (instansi == "PAUD")? 42 : 0;
	kpengajar = (instansi == "SD")? 42 : 0;
	kpengajar = (instansi == "SMP")? 42 : 0;
	kpengajar = (instansi == "SMA")? 42 : 0;
	kpengajar = (instansi == "Universitas")? 50 : 0;

	total = 6000*(siswa*ksiswa + pengajar*kpengajar);

	cout << "total biaya kuota \t: " << "Rp" << total << endl;

	
	cin.get();
	cin.get();
	return 0;
}
