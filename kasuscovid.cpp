#include <iostream>
using namespace std;

int totalkasus (int x , int y){
	return x + y;
} 

int main()
{
	int mati1, odp1, mati2, odp2, positif1, positif2 ;
	int totalpos, totalmati, totalodp; 

	cout << "---PERSEBARAN KASUS DI KELURAHAN A---" << endl;
	cout << endl;

	cout << "---MINGGU  PERTAMA ---\n";
	cout << "jumlah pasien postif baru: ";
	cin >> positif1;

	cout << "jumlah pasien yang meninggal baru: ";
	cin >> mati1;

	cout << "jumlah pasien ODP baru: ";
	cin >> odp1;

	cout << endl;

	cout << "---MINGGU KEDUA---\n";
	cout << endl;

	cout << "jumlah pasien positif baru: ";
	cin >> positif2;

	cout << "jumlah pasien yang meninggal baru: ";
	cin >> mati2;

	cout << "jumlah pasien ODP baru: ";
	cin >> odp2;

	cout << endl;

	if ((positif1 < positif2) && (mati1 != 0 || mati2 != 0) && (odp1 != 0 || odp2 != 0)){
		cout << "Daerah ini termasuk Zona Hitam" <<endl;
	} else if ((positif1 != 0 || positif2 != 0) && (mati1 == 0 && mati2 == 0) && (odp1 != 0 || odp2 != 0)){
		cout << "Daerah ini termasuk Zona Merah" << endl;
	} else if (positif1 == 0 && positif2 == 0 && mati1 == 0 && mati2 == 0 && (odp1 != 0 || odp2 != 0)){
		cout << "Daerah ini termasuk Zona Oranye" << endl;
	} else if (positif1 == 0 && positif2 == 0 && mati1 == 0 && mati2 == 0 && odp1 == 0 && odp2 == 0){
		cout << "Daerah ini termasuk Zona Hijau" << endl;
	}

	cout << endl;

	totalpos = totalkasus(positif1, positif2);
	cout << "total pasien positif Covid-19 di kelurahan A: " << totalpos << endl;

	totalmati = totalkasus(mati1, mati2);
	cout << "total pasien positif Covid-19 meninggal di kelurahan A: "<< totalmati << endl;

	totalodp = totalkasus(odp1, odp2);
	cout << "total ODP Covid-19 di kelurahan A: " << totalodp << endl;



	cin.get();
	cin.get();
	return 0;
}
